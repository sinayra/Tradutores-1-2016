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
     WHILE = 267,
     IF = 268,
     THEN = 269,
     DO = 270,
     VAR = 271,
     TIPO = 272,
     NUM = 273,
     ID = 274,
     OP_ATRIB = 275,
     REL_MENOR = 276,
     REL_MAIOR = 277,
     REL_IGUAL = 278,
     REL_MENOR_IGUAL = 279,
     REL_MAIOR_IGUAL = 280,
     REL_DIF = 281,
     SOMA = 282,
     SUB = 283,
     MULT = 284,
     DIV = 285,
     AND = 286,
     OR = 287,
     NOT = 288,
     PAR_ABRE = 289,
     PAR_FECHA = 290,
     VIRGULA = 291,
     PONTO_VIRGULA = 292,
     DOIS_PONTOS = 293,
     PONTO = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 30 "sintatico.y"

	char *cadeia;
	int valor;

	struct tipoExp{
		int val;
		int isNum;
		int arit;
	}tipoExp;

	struct tipoRel{
		int inicio;
		int fim;
	}tipoRel;


/* Line 2058 of yacc.c  */
#line 113 "sintatico.tab.h"
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
