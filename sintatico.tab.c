/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 4 "sintatico.y"

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "cgen.h"


//Funcoes do bison
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;
int yylex();
void yyerror(const char *s);

//Funcoes do sintatico.y

int linha_fim_estr, linha_fimif;
int erro_semantico = 0;
int busca_tabela(char *id);

void verifica_tabela();
void processa_operacao(int isNum1, int val1, int arit1, int isNum2, int val2, int arit2, tipoInstr tipo);
int checa_elemento(char *nome);
int checa_tipo(TS var, int isNum, int isBool, int isArit);


/* Line 371 of yacc.c  */
#line 96 "sintatico.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sintatico.tab.h".  */
#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF_CONFLICT = 258,
     ELSE = 259,
     PROGRAM = 260,
     FUNCTION = 261,
     PROCEDURE = 262,
     READ = 263,
     WRITE = 264,
     BLOCO_ABRE = 265,
     BLOCO_FECHA = 266,
     TRUE = 267,
     FALSE = 268,
     WHILE = 269,
     IF = 270,
     THEN = 271,
     DO = 272,
     VAR = 273,
     TIPO = 274,
     NUM = 275,
     ID = 276,
     OP_ATRIB = 277,
     REL_MENOR = 278,
     REL_MAIOR = 279,
     REL_IGUAL = 280,
     REL_MENOR_IGUAL = 281,
     REL_MAIOR_IGUAL = 282,
     REL_DIF = 283,
     SOMA = 284,
     SUB = 285,
     MULT = 286,
     DIV = 287,
     AND = 288,
     OR = 289,
     NOT = 290,
     PAR_ABRE = 291,
     PAR_FECHA = 292,
     VIRGULA = 293,
     PONTO_VIRGULA = 294,
     DOIS_PONTOS = 295,
     PONTO = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 32 "sintatico.y"

	char *cadeia;
	int valor;

	struct tipoExp{
		int val;
		int isNum;
		int isArit;
		int isBool;
	}tipoExp;

	struct tipoRel{
		int inicio;
		int fim;
		int isArit;
		int isBool;
	}tipoRel;


/* Line 387 of yacc.c  */
#line 200 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 228 "sintatico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    11,    17,    19,    22,    25,    27,
      29,    34,    39,    40,    48,    52,    56,    61,    66,    70,
      71,    74,    77,    81,    85,    89,    90,    92,    94,    97,
      98,   109,   110,   119,   121,   123,   125,   127,   130,   134,
     138,   142,   146,   150,   154,   158,   162,   166,   170,   174,
     178,   182,   186,   188,   190,   194,   196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,     5,    21,    39,    44,    45,    41,
      -1,    52,    55,    10,    46,    11,    -1,    47,    -1,    46,
      47,    -1,    51,    39,    -1,    48,    -1,    50,    -1,    14,
      61,    17,    47,    -1,    15,    61,    16,    47,    -1,    -1,
      15,    61,    16,    47,     4,    49,    47,    -1,    10,    46,
      11,    -1,    21,    22,    60,    -1,     8,    36,    63,    37,
      -1,     9,    36,    62,    37,    -1,    21,    36,    37,    -1,
      -1,    18,    53,    -1,    54,    39,    -1,    54,    39,    53,
      -1,    21,    40,    19,    -1,    21,    38,    54,    -1,    -1,
      56,    -1,    57,    -1,    57,    56,    -1,    -1,     6,    21,
      36,    37,    40,    19,    39,    58,    47,    39,    -1,    -1,
       7,    21,    36,    37,    39,    59,    47,    39,    -1,    20,
      -1,    12,    -1,    13,    -1,    21,    -1,    35,    60,    -1,
      60,    29,    60,    -1,    60,    30,    60,    -1,    60,    31,
      60,    -1,    60,    32,    60,    -1,    36,    61,    37,    -1,
      21,    36,    37,    -1,    60,    23,    60,    -1,    60,    24,
      60,    -1,    60,    25,    60,    -1,    60,    27,    60,    -1,
      60,    26,    60,    -1,    60,    28,    60,    -1,    60,    33,
      60,    -1,    60,    34,    60,    -1,    60,    -1,    60,    -1,
      62,    38,    60,    -1,    21,    -1,    63,    38,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   105,   120,   123,   124,   126,   127,   129,
     130,   142,   153,   152,   173,   176,   206,   207,   208,   220,
     221,   224,   225,   228,   241,   259,   260,   263,   264,   267,
     266,   280,   279,   293,   300,   307,   314,   329,   330,   339,
     348,   357,   366,   370,   379,   394,   409,   424,   440,   456,
     471,   472,   473,   476,   493,   512,   523
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF_CONFLICT", "ELSE", "PROGRAM",
  "FUNCTION", "PROCEDURE", "READ", "WRITE", "BLOCO_ABRE", "BLOCO_FECHA",
  "TRUE", "FALSE", "WHILE", "IF", "THEN", "DO", "VAR", "TIPO", "NUM", "ID",
  "OP_ATRIB", "REL_MENOR", "REL_MAIOR", "REL_IGUAL", "REL_MENOR_IGUAL",
  "REL_MAIOR_IGUAL", "REL_DIF", "SOMA", "SUB", "MULT", "DIV", "AND", "OR",
  "NOT", "PAR_ABRE", "PAR_FECHA", "VIRGULA", "PONTO_VIRGULA",
  "DOIS_PONTOS", "PONTO", "$accept", "programa", "$@1", "bloco_principal",
  "componente", "estrutura", "estrutura_bloco", "$@2", "bloco_composto",
  "estrutura_simples", "variavel_declaracao_inicio",
  "variavel_declaracao_lista", "variavel_declaracao",
  "funcao_declaracao_inicio", "funcao_declaracao_lista",
  "funcao_declaracao", "$@3", "$@4", "exp", "rel", "argumentos_O",
  "argumentos_I", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    45,    46,    46,    47,    47,    48,
      48,    48,    49,    48,    50,    51,    51,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    58,
      57,    59,    57,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     5,     1,     2,     2,     1,     1,
       4,     4,     0,     7,     3,     3,     4,     4,     3,     0,
       2,     2,     3,     3,     3,     0,     1,     1,     2,     0,
      10,     0,     8,     1,     1,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,    19,     0,     0,    25,
       0,    20,     0,     3,     0,     0,     0,    26,    27,     0,
       0,    21,     0,     0,     0,    28,    24,    23,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     8,
       9,     0,     0,     0,     0,     0,     0,    34,    35,    33,
      36,     0,     0,    52,     0,     0,     0,     0,     4,     6,
       7,     0,    31,    55,     0,    53,     0,    14,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    18,     0,     0,    16,
       0,    17,     0,    43,    42,    44,    45,    46,    48,    47,
      49,    38,    39,    40,    41,    50,    51,    10,    11,    29,
       0,    56,    54,    12,     0,    32,     0,     0,    13,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     8,    37,    38,    39,   116,    40,    41,
       9,    11,    12,    16,    17,    18,   114,    88,    53,    54,
      66,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -45
static const yytype_int8 yypact[] =
{
      15,     3,    64,    18,   -45,   -45,    50,    48,    29,    11,
     -32,   -45,    32,   -45,    51,    53,    65,   -45,    11,    48,
      59,    48,    40,    56,    35,   -45,   -45,   -45,   -45,    58,
      60,    62,    63,    35,   -10,   -10,   -17,    44,   -45,   -45,
     -45,    54,    61,    55,    75,   -10,    52,   -45,   -45,   -45,
      66,   -10,   -10,    57,    83,    87,   -10,    67,   -45,   -45,
     -45,    86,   -45,   -45,   -15,   -16,     2,   -45,    69,   -45,
      70,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,    35,    35,   -16,   -45,    71,    35,   -45,
      88,   -45,   -10,   -45,   -45,   -16,   -16,   -16,   -16,   -16,
     -16,    10,    10,   -45,   -45,   -16,   -16,   -45,   104,   -45,
      72,   -45,   -16,   -45,    35,   -45,    35,    73,   -45,   -45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,    80,   -37,   -45,   -45,   -45,   -45,
     -45,    93,    96,   -45,    98,   -45,   -45,   -45,   -44,   -31,
     -45,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    65,    47,    48,    55,    56,    19,    69,    20,    59,
      49,    50,    85,    77,    78,    79,    80,    14,    15,    57,
       1,    70,    89,    90,     3,    51,    52,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    91,
      92,    79,    80,    31,    32,    33,   107,   108,   112,    34,
      35,   110,    31,    32,    33,    58,    36,     5,    34,    35,
      31,    32,    33,    67,     4,    36,    34,    35,     7,    10,
      13,    21,    22,    36,    23,    24,    29,   117,    27,   118,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    30,    60,    62,    42,    63,    43,    44,    45,
      83,    61,    68,    84,    86,    87,    93,    94,   113,   111,
     109,   115,   119,    46,    28,    26,    25
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      37,    45,    12,    13,    35,    22,    38,    51,    40,    46,
      20,    21,    56,    29,    30,    31,    32,     6,     7,    36,
       5,    52,    37,    38,    21,    35,    36,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    37,
      38,    31,    32,     8,     9,    10,    83,    84,    92,    14,
      15,    88,     8,     9,    10,    11,    21,    39,    14,    15,
       8,     9,    10,    11,     0,    21,    14,    15,    18,    21,
      41,    39,    21,    21,    21,    10,    36,   114,    19,   116,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    36,    39,    39,    37,    21,    37,    36,    36,
      17,    40,    36,    16,    37,    19,    37,    37,     4,    21,
      39,    39,    39,    33,    21,    19,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    43,    21,     0,    39,    44,    18,    45,    52,
      21,    53,    54,    41,     6,     7,    55,    56,    57,    38,
      40,    39,    21,    21,    10,    56,    54,    19,    53,    36,
      36,     8,     9,    10,    14,    15,    21,    46,    47,    48,
      50,    51,    37,    37,    36,    36,    46,    12,    13,    20,
      21,    35,    36,    60,    61,    61,    22,    36,    11,    47,
      39,    40,    39,    21,    63,    60,    62,    11,    36,    60,
      61,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    17,    16,    60,    37,    19,    59,    37,
      38,    37,    38,    37,    37,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    47,    47,    39,
      47,    21,    60,     4,    58,    39,    49,    47,    47,    39
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 106 "sintatico.y"
    {
				
				TS temp;
				strcpy(temp.cadeia, (yyvsp[(2) - (3)].cadeia));
				temp.tipo = TIPO_INDEFINIDO;
				temp.usado = 1;
				temp.estr = PROGRAMA;
				
				inserir_elemento_no_final(temp);

			}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 120 "sintatico.y"
    {;}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 123 "sintatico.y"
    {;}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 124 "sintatico.y"
    {;}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 126 "sintatico.y"
    {(yyval.valor) = getLinhaAtual();}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 127 "sintatico.y"
    {(yyval.valor) = getLinhaAtual();}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 129 "sintatico.y"
    {;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 131 "sintatico.y"
    {
					int linhaaux;
					setLinhaAtual((yyvsp[(2) - (4)].tipoRel).fim);

					linhaaux = ((yyvsp[(4) - (4)].valor) - 1 + 2) - ((yyvsp[(2) - (4)].tipoRel).fim + 1); //(PC+4 + 2 intruções do jump de volta pro while) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP_REL_FALSE, linhaaux, -1);

					setLinhaAtual((yyvsp[(4) - (4)].valor));
					linhaaux = (yyvsp[(2) - (4)].tipoRel).inicio - ((yyvsp[(4) - (4)].valor) + 2); //+2 instruções pro jump no final
					montador(yyout, INSTR_JUMP, linhaaux, -1);
				}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 143 "sintatico.y"
    {
					int linhaaux;
					setLinhaAtual((yyvsp[(2) - (4)].tipoRel).fim);

					linhaaux = ((yyvsp[(4) - (4)].valor) - 1) - ((yyvsp[(2) - (4)].tipoRel).fim + 1); //(PC+4) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP_REL_FALSE, linhaaux, -1);

					setLinhaAtual((yyvsp[(4) - (4)].valor));
				}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 153 "sintatico.y"
    {
					setLinhaAtual((yyvsp[(4) - (5)].valor) + 2); //mais duas instruções do jump
				}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 157 "sintatico.y"
    {
					int linhaaux, linhatual_aux;
					linhatual_aux = getLinhaAtual();

					setLinhaAtual((yyvsp[(2) - (7)].tipoRel).fim);
					linhaaux = ((yyvsp[(4) - (7)].valor) - 1 + 2) - ((yyvsp[(2) - (7)].tipoRel).fim + 1); //(PC-4 + 2 instruções de jump) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP_REL_FALSE, linhaaux, -1);

					setLinhaAtual((yyvsp[(4) - (7)].valor));

					linhaaux = (linhatual_aux - 2) - (yyvsp[(4) - (7)].valor); //(PC+4) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP, linhaaux, -1);

					setLinhaAtual(linhatual_aux);
				}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 173 "sintatico.y"
    {;}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 177 "sintatico.y"
    {
							escreverComentario(yyout, "Processo de atribuicao");
							int index = checa_elemento((yyvsp[(1) - (3)].cadeia));

							if(index < 0){
								erro_semantico = 1;
								printf("ERRO Linha %d: %s nao declarado \n", yylineno, (yyvsp[(1) - (3)].cadeia));
							}
							else{
								int tipo = checa_tipo(buscar_elemento_indice(index), (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).isBool, (yyvsp[(3) - (3)].tipoExp).isArit);
								if(tipo){
									if(!(yyvsp[(3) - (3)].tipoExp).isArit){
										if((yyvsp[(3) - (3)].tipoExp).isNum || (yyvsp[(3) - (3)].tipoExp).isBool){
											montador(yyout, INSTR_LOAD_CTE, (yyvsp[(3) - (3)].tipoExp).val, ac);
										}
										else{
											montador(yyout, INSTR_LOAD_MEMORIA, (yyvsp[(3) - (3)].tipoExp).val, ac);
											
										}
									}
									else
										montador(yyout, INSTR_LOAD_MEMORIA_TEMP, -1, ac);

									montador(yyout, INSTR_STORE_MEMORIA, index, ac);
								}
							}
							escreverComentario(yyout, "Fim de atribuicao");
							
						}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 206 "sintatico.y"
    {;}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 207 "sintatico.y"
    {;}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 209 "sintatico.y"
    {
							int index = checa_elemento((yyvsp[(1) - (3)].cadeia));
							if(index < 0){
								erro_semantico = 1;
								printf("ERRO Linha %d: %s nao declarado \n", yylineno, (yyvsp[(1) - (3)].cadeia));
							}
							
						}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 220 "sintatico.y"
    {;}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 221 "sintatico.y"
    {;}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 224 "sintatico.y"
    {;}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 225 "sintatico.y"
    {;}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 229 "sintatico.y"
    {
							TS temp;
							strcpy(temp.cadeia, (yyvsp[(1) - (3)].cadeia));
							temp.tipo = get_TIPO((yyvsp[(3) - (3)].cadeia));
							temp.usado = 0;
							temp.estr = VARIAVEL;
							
							inserir_elemento_no_final(temp);

							//printf("ID declarado: %s\n", $ID);

						}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 242 "sintatico.y"
    {
							TS temp1, temp2;
							int index = get_n_simbolos() - 1;

							temp2 = buscar_elemento_indice(index);

							strcpy(temp1.cadeia, (yyvsp[(1) - (3)].cadeia));
							temp1.tipo = temp2.tipo;
							temp1.usado = 0;
							temp1.estr = VARIAVEL;

							inserir_elemento_no_final(temp1);

							//printf("ID declarado: %s\n", $ID);
						}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 259 "sintatico.y"
    {;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 260 "sintatico.y"
    {;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 263 "sintatico.y"
    {;}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 264 "sintatico.y"
    {;}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 267 "sintatico.y"
    {
							TS temp;
							strcpy(temp.cadeia, (yyvsp[(2) - (7)].cadeia));
							temp.tipo = get_TIPO((yyvsp[(6) - (7)].cadeia));
							temp.usado = 0;
							temp.estr = FUNCAO;

							inserir_elemento_no_final(temp);

							//printf("Declaracao de funcao: %s \n", $ID);
						}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 280 "sintatico.y"
    {
							TS temp;
							strcpy(temp.cadeia, (yyvsp[(2) - (5)].cadeia));
							temp.tipo = TIPO_INDEFINIDO;
							temp.usado = 0;
							temp.estr = PROCEDIMENTO;

							inserir_elemento_no_final(temp);

							//printf("Declaracao de procedure: %s \n", $ID);
						}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 294 "sintatico.y"
    {
			(yyval.tipoExp).val = (yyvsp[(1) - (1)].valor);
			(yyval.tipoExp).isNum = 1;
			(yyval.tipoExp).isArit = 0;
			(yyval.tipoExp).isBool = 0;
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 301 "sintatico.y"
    {
			(yyval.tipoExp).val = (yyvsp[(1) - (1)].valor);
			(yyval.tipoExp).isNum = 0;
			(yyval.tipoExp).isArit = 0;
			(yyval.tipoExp).isBool = 1;
		}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 308 "sintatico.y"
    {
			(yyval.tipoExp).val = (yyvsp[(1) - (1)].valor);
			(yyval.tipoExp).isNum = 0;
			(yyval.tipoExp).isArit = 0;
			(yyval.tipoExp).isBool = 1;
		}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 315 "sintatico.y"
    {
			int index = checa_elemento((yyvsp[(1) - (1)].cadeia));
			if(index < 0){
				erro_semantico = 1;
				printf("ERRO Linha %d: %s nao declarado \n", yylineno, (yyvsp[(1) - (1)].cadeia));
			}
			else{
				(yyval.tipoExp).val = index;
				(yyval.tipoExp).isNum = 0;
				(yyval.tipoExp).isArit = 0;
				(yyval.tipoExp).isBool = 0;
			}
			
		}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 329 "sintatico.y"
    {;}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 331 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de adicao");

			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_ADD);

			escreverComentario(yyout, "Fim de adicao");
			(yyval.tipoExp).isArit = 1;
		}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 340 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de subtracao");
			
			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_SUB);

			escreverComentario(yyout, "Fim de subtracao");
			(yyval.tipoExp).isArit = 1;
		}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 349 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de multiplicacao");
			
			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_MULT);

			escreverComentario(yyout, "Fim de multiplicacao");
			(yyval.tipoExp).isArit = 1;
		}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 358 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de divisao");
			
			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_DIV);

			escreverComentario(yyout, "Fim de divisao");
			(yyval.tipoExp).isArit = 1;
		}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 367 "sintatico.y"
    {
			(yyval.tipoExp).isArit = (yyvsp[(2) - (3)].tipoRel).isArit; /*para passar para arvore sintática o valor de expressão se ela for aritmética*/
		}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 371 "sintatico.y"
    {
			if(checa_elemento((yyvsp[(1) - (3)].cadeia)) == -1){
				erro_semantico = 1;
				printf("ERRO Linha %d: %s nao declarado \n", yylineno, (yyvsp[(1) - (3)].cadeia));
			}
			
		}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 380 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de relacao <");
			(yyval.tipoRel).inicio = getLinhaAtual();

			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_REL_MENOR);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			(yyval.tipoRel).fim = getLinhaAtual();
			setLinhaAtual((yyval.tipoRel).fim + 2); //+ duas instruções quando for dar jump
			(yyval.tipoRel).isArit = 0;
			(yyval.tipoRel).isBool = 1;

			escreverComentario(yyout, "Fim de <");
		}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 395 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de relacao >");
			(yyval.tipoRel).inicio = getLinhaAtual();

			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_REL_MAIOR);
			montador(yyout, INSTR_STORE_REL, -1, -1);
			
			(yyval.tipoRel).fim = getLinhaAtual();
			setLinhaAtual((yyval.tipoRel).fim + 2); //+ duas instruções quando for dar jump
			(yyval.tipoRel).isArit = 0;
			(yyval.tipoRel).isBool = 1;

			escreverComentario(yyout, "Fim de >");
		}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 410 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de relacao =");
			(yyval.tipoRel).inicio = getLinhaAtual();
			
			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_REL_IGUAL);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			(yyval.tipoRel).fim = getLinhaAtual();
			setLinhaAtual((yyval.tipoRel).fim + 2); //+ duas instruções quando for dar jump
			(yyval.tipoRel).isArit = 0;
			(yyval.tipoRel).isBool = 1;

			escreverComentario(yyout, "Fim de =");
		}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 425 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de relacao >=");
			(yyval.tipoRel).inicio = getLinhaAtual();

			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_REL_MAIOR_IGUAL);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			(yyval.tipoRel).fim = getLinhaAtual();
			setLinhaAtual((yyval.tipoRel).fim + 2);
			(yyval.tipoRel).isArit = 0;
			(yyval.tipoRel).isBool = 1;

			escreverComentario(yyout, "Fim de >=");
		
		}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 441 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de relacao <=");
			(yyval.tipoRel).inicio = getLinhaAtual();

			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit,INSTR_REL_MENOR_IGUAL);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			(yyval.tipoRel).fim = getLinhaAtual();
			setLinhaAtual((yyval.tipoRel).fim + 2);
			(yyval.tipoRel).isArit = 0;
			(yyval.tipoRel).isBool = 1;

			escreverComentario(yyout, "Fim de <=");
		
		}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 457 "sintatico.y"
    {
			escreverComentario(yyout, "Processo de relacao <>");
			(yyval.tipoRel).inicio = getLinhaAtual();

			processa_operacao((yyvsp[(1) - (3)].tipoExp).isNum, (yyvsp[(1) - (3)].tipoExp).val, (yyvsp[(1) - (3)].tipoExp).isArit, (yyvsp[(3) - (3)].tipoExp).isNum, (yyvsp[(3) - (3)].tipoExp).val, (yyvsp[(3) - (3)].tipoExp).isArit, INSTR_REL_DIF);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			(yyval.tipoRel).fim = getLinhaAtual();
			setLinhaAtual((yyval.tipoRel).fim + 2);
			(yyval.tipoRel).isArit = 0;
			(yyval.tipoRel).isBool = 1;

			escreverComentario(yyout, "Fim de <>");
		}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 471 "sintatico.y"
    {;}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 472 "sintatico.y"
    {;}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 473 "sintatico.y"
    {;}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 477 "sintatico.y"
    {	
					if((yyvsp[(1) - (1)].tipoExp).isArit){
						montador(yyout, INSTR_LOAD_MEMORIA_TEMP, (yyvsp[(1) - (1)].tipoExp).val, ac);
						montador(yyout, INSTR_WRITE, (yyvsp[(1) - (1)].tipoExp).val, ac);
					}
					else{
						if((yyvsp[(1) - (1)].tipoExp).isNum){
							montador(yyout, INSTR_LOAD_CTE, (yyvsp[(1) - (1)].tipoExp).val, ac);
							montador(yyout, INSTR_WRITE, (yyvsp[(1) - (1)].tipoExp).val, ac);
						}
						else{
							montador(yyout, INSTR_LOAD_MEMORIA, (yyvsp[(1) - (1)].tipoExp).val, ac);
							montador(yyout, INSTR_WRITE, (yyvsp[(1) - (1)].tipoExp).val, ac);
						}
					}
				}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 494 "sintatico.y"
    {
					if((yyvsp[(3) - (3)].tipoExp).isArit){
							montador(yyout, INSTR_LOAD_MEMORIA_TEMP, (yyvsp[(3) - (3)].tipoExp).val, ac);
							montador(yyout, INSTR_WRITE, (yyvsp[(3) - (3)].tipoExp).val, ac);
						}
					else{
						if((yyvsp[(3) - (3)].tipoExp).isNum){
							montador(yyout, INSTR_LOAD_CTE, (yyvsp[(3) - (3)].tipoExp).val, ac);
							montador(yyout, INSTR_WRITE, (yyvsp[(3) - (3)].tipoExp).val, ac);
						}
						else{
							montador(yyout, INSTR_LOAD_MEMORIA, (yyvsp[(3) - (3)].tipoExp).val, ac);
							montador(yyout, INSTR_WRITE, (yyvsp[(3) - (3)].tipoExp).val, ac);
						}
					}
				}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 513 "sintatico.y"
    {
					int index = checa_elemento((yyvsp[(1) - (1)].cadeia));
					if(index < 0){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, (yyvsp[(1) - (1)].cadeia));
					}
					else{
						montador(yyout, INSTR_READ, index, ac);
					}
				}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 524 "sintatico.y"
    {
					
					int index = checa_elemento((yyvsp[(3) - (3)].cadeia));
				
					if(index < 0){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, (yyvsp[(3) - (3)].cadeia));
					}
					else{
						montador(yyout, INSTR_READ, index, ac);
					}
				}
    break;


/* Line 1792 of yacc.c  */
#line 2150 "sintatico.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 540 "sintatico.y"


void processa_operacao(int flag_a, int val1, int inAc1, int flag_b, int val2, int inAc2, tipoInstr tipo){
	if(!inAc1){
		if(flag_a){
			montador(yyout, INSTR_LOAD_CTE, val1, ac);
			montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
		}
		else{
			montador(yyout, INSTR_LOAD_MEMORIA, val1, ac);
			montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
		}
	}

	if(!inAc2){
		if(flag_b){
			montador(yyout, INSTR_LOAD_CTE, val2, ac);
			montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
		}
		else{
			montador(yyout, INSTR_LOAD_MEMORIA, val2, ac);
			montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
		}
	}
		
	montador(yyout, INSTR_TEMP_ACS, -1, -1);
	montador(yyout, tipo, -1, -1);	
}

int checa_tipo(TS var, int isNum, int isBool, int isArit){
	switch(var.tipo){
		case(INTEGER):
			if(!isNum && !isArit){
				erro_semantico = 1;
				printf("ERRO Linha %d: Tipo incompativel. Esperado expressao de tipo integer \n", yylineno);
				return 0;
			}
		break;
		case(BOOLEAN):
			if(!isBool){
				erro_semantico = 1;
				printf("ERRO Linha %d: Tipo incompativel. Esperado expressao de tipo boolean \n", yylineno);
				return 0;
			}
		break;
		default:
			return 0;
		break;
	}

	return 1;
}

int checa_elemento(char *nome){
	int index = existe_elemento(nome);
	if(index >= 0){
		TS temp = buscar_elemento_indice(index);
		if(temp.usado == 0){
			temp.usado = 1;
			editar_elemento(index, temp);
			//printf("ID usado: %s \n", nome);
		}
		return index;
	}
	return -1;
}

void verifica_tabela(){		/*Verifica se ha simbolos nao utilizados*/
	for(int i = 0; i < get_n_simbolos(); i++){
		TS temp = buscar_elemento_indice(i);
		if(temp.usado == 0)
			printf("Warning: variavel %s declarada, mas nao utilizada\n", temp.cadeia);
	}
}

int main(int argc, char* argv[]){
	extern FILE *yyin;
	extern FILE *yyout;
	int erro;

	++argv; --argc; 	    /* abre arquivo de entrada se houver */
	if(argc > 0){
			yyin = fopen(argv[0],"rt");
			if(yyin == NULL){
				printf("Arquivo nao encontrado");
				exit(EXIT_FAILURE);
			}
	}
	else
		yyin = stdin;

	if(argc > 1)
		yyout = fopen(argv[1],"wt");
	else
		yyout = fopen("a.out","wt");

	montador(yyout, INSTR_INICIO, -1, ac);
	erro = yyparse();	
	montador(yyout, INSTR_FIM, -1, ac);
	
	if(erro == 0){		/*Se o programa estiver sintaticamente correto, ele checa o semantico*/
		//imprimir_lista();
		
		printf("\nPrograma sintaticamente correto\n");
		
		if(erro_semantico == 0)
			printf("Programa semanticamente correto\n");
		
		verifica_tabela();
	}
	
	fclose(yyin);
	fclose(yyout);
	excluir_TS();
}

void yyerror (const char *s){
	extern FILE *yyout;
	printf ("%s in line %d\n", s, yylineno);
}
