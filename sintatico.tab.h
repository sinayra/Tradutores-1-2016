/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 36 "sintatico.y"

	char *cadeia;
	int valor;

	struct tipoExp{
		int val;
		int isNum;
		int inicio;
		int fim;
		int isArit;
		int isBool;
	}tipoExp;

	struct tipoRel{
		int inicio;
		int fim;
		int isArit;
		int isBool;
		int isNum;
	}tipoRel;


/* Line 2058 of yacc.c  */
#line 121 "sintatico.tab.h"
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
