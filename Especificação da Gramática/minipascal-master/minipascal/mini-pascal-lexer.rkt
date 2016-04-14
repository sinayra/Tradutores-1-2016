#lang racket
;;;
;;; LEXER
;;;

; This module defines two lexers for MiniPascal.

(provide lex color-lex)

; The main one, lex, returns tokens to
; be used by the ragg parser.

; The other one, color-lex, returns tokens
; to be used by DrRacket to syntax color 
; Pascal programs.

(require ragg/support parser-tools/lex)

; Reserved keywords in Pacal ignore case.
; Thus the "PrOgRaM" and "program" are 
; the same keyword. Since the lexer has
; no builtin support for matching mixed case
; strings, we define our own lexer 
; transformation, mixed, that turns
;   (mixed "foo") into
;   (concatenation 
;     (union #\f #\F) (union #\o #\o) (union #\o #\o))
; Remember to use string-downcase on the 
; resulting lexeme.

(require (for-syntax syntax/parse))
(define-lex-trans mixed
  (λ (stx)
    (syntax-parse stx
      [(_ datum)
       (define str (string-downcase (syntax->datum #'datum)))
       (define STR (string-upcase str))
       #`(concatenation
          #,@(for/list ([c (in-string str)]
                        [C (in-string STR)])
               #`(union #,c #,C)))])))

; The following lexer transformation turns
;   (union-mixed "foo" "bar") into
;   (union (mixed "foo") (mixed "bar"))

(define-lex-trans union-mixed
  (λ (stx)
    (syntax-parse stx
      [(_ str ...)
       #`(union (mixed str) ...)])))

; Since we want to define two lexers, it is
; convenient to define lexer abbreviations
; that can be used in both lexers.

(define-lex-abbrevs
  [letter     
   (union (char-range #\a #\z) (char-range #\A #\Z))]
  [digit      
   (char-range #\0 #\9)]
  [identifier 
   (concatenation letter 
                  (repetition 0 +inf.0 (union letter digit)))]
  [integer ; non-negative
   (repetition 1 +inf.0 digit)]
  [char-constant 
   (union (concatenation #\' (char-complement #\') #\') "''''")]
  [string-content 
   (union (char-complement #\') "''")]
  [string-constant 
   (union (concatenation #\' (repetition 0 +inf.0 string-content) #\'))]
  [reserved
   (union-mixed
    "div" "or" "and" "not" "if" "for" "to" "downto"
    "then" "else" "of" "while" "do" "begin" "end" 
    "read" "readln" "write" "writeln"
    "var" "const" "array" "type" "bindable"
    "procedure" "function" "program")]
  [slash-comment
   (concatenation "//" (repetition 0 +inf.0 (char-complement #\newline)))]  
  [curly-comment 
   (concatenation #\{  (repetition 0 +inf.0 (char-complement #\})) #\})]
  [comment 
   (union slash-comment curly-comment)]
  [operators 
   (union "+" "-" "*" "=" "<>" "<" ">" "<=" ">=" ":=")]
  [brackets
   (union "(" ")" "[" "]")]
  [other-delimiters
   (union "." "," ";" ":" "..")]
  [delimiters
   (union operators brackets other-delimiters)])

(define (string-remove-ends str)
  (substring str 1 (sub1 (string-length str))))

;; Lexer for MiniPascal
(define (lex ip)
  (port-count-lines! ip)
  (define my-lexer
    (lexer-src-pos
     [(union "integer" "char" "boolean" "true" "false")
      (token 'IDENTIFIER (string->symbol lexeme))]
     [(union reserved delimiters) ; includes operators
      (string-downcase lexeme)]
     [identifier
      (token 'IDENTIFIER (string->symbol (string-downcase lexeme)))]
     [integer
      (token 'INTEGER-CONSTANT (string->number lexeme))]
     [char-constant
      (if (equal? lexeme "''''")
          (token 'CHARACTER-CONSTANT #\')
          (token 'CHARACTER-CONSTANT (string-ref lexeme 1)))]
     [string-constant
      (token 'STRING-CONSTANT
             (regexp-replace* "''" (string-remove-ends lexeme) "'"))]
     [whitespace
      (token 'WHITESPACE lexeme #:skip? #t)]
     [comment
      (token 'COMMENT lexeme #:skip? #t)]     
     [(eof)
      (void)]))
  (define (next-token) 
    (my-lexer ip))
  next-token)

;;;
;;; COLOR LEXER
;;;

; This lexer is used by DrRacket to color the Pacal program.

; The color lexer returns 5 values:
; - Either a string containing the matching text or the eof object. 
;   Block comments and specials currently return an empty string. 
;   This may change in the future to other string or non-string data.
; - A symbol in '(error comment sexp-comment white-space constant 
;                 string no-color parenthesis other symbol eof).
; - A symbol in '(|(| |)| |[| |]| |{| |}|) or #f.
; - A number representing the starting position of the match (or #f if eof).
; - A number representing the ending position of the match (or #f if eof).

(define (syn-val a b c d e)
  (values a ; string with matching text
          b ; symbol in '(comment white-space no-color eof)
          c ; symbol in '(|(| |)| |[| |]| |{| |}|) or #f.
          (position-offset d)    ; start pos
          (max                   ; end pos
           (position-offset e)
           (+ (position-offset d) 1))))

(define color-lex
  ; REMEMBER to restart DrRacket to test any changes in the 
  ; color-lexer. The lexer is only imported into DrRacket 
  ; at startup.
  (lexer
   [(eof)
    (syn-val lexeme 'eof          #f start-pos end-pos)]
   [reserved
    (syn-val lexeme 'keyword      #f start-pos end-pos)]   
   [brackets
    (syn-val lexeme 'parenthesis  (string->symbol lexeme) start-pos end-pos)]   
   [whitespace
    (syn-val lexeme 'white-space  #f start-pos end-pos)]   
   [slash-comment
    (syn-val lexeme 'comment      #f start-pos end-pos)]
   [curly-comment
    (syn-val lexeme 'sexp-comment #f start-pos end-pos)]
   [(union "{" "}")
    (syn-val lexeme 'sexp-comment (string->symbol lexeme) start-pos end-pos)]
   #;[operators 
      (syn-val lexeme 'symbol     #f start-pos end-pos)]
   [string-constant
    (syn-val lexeme 'string       #f start-pos end-pos)]   
   [identifier
    (syn-val lexeme 'identifier   #f start-pos end-pos)]      
   [(union integer char-constant) 
    (syn-val lexeme 'constant     #f start-pos end-pos)]
   [delimiters
    (syn-val lexeme 'no-color     #f start-pos end-pos)]
   [any-char ; anything else is an error (red)
    (syn-val lexeme 'error        #f start-pos end-pos)]))
