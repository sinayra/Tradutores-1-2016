%{
#include <stdio.h>
#include "sintatico.tab.h"

extern char *strdup(const char *s);

%}

%option yylineno

PROGRAM		("program")
WRITE		("write")
READ		("read")
FUNCTION	("function")
PROCEDURE	("procedure")
BLOCO_ABRE	("begin")
BLOCO_FECHA ("end")
WHILE 		("while")
DO 			("do")
VAR			("var")
TIPO		("integer"|"boolean"|"char")
ID			[a-zA-Z][a-zA-Z0-9]*	
NUM 		("+"|"-")?[0-9]+(".")[0-9]+
BRANCO		(" "|"\t"|"\r"|"\n")
SOMA		("+")
SUB			("-")
MULT		("*")
RELACAO		("<"|">"|"=")


%%
{PROGRAM}		{return PROGRAM;}
{READ} 			{return READ;}
{WRITE} 		{return WRITE;}
{FUNCTION} 		{return FUNCTION;}
{PROCEDURE} 	{return PROCEDURE;}
{BLOCO_ABRE} 	{return BLOCO_ABRE;}
{BLOCO_FECHA}	{return BLOCO_FECHA;}
{WHILE}			{return WHILE;}
{DO}			{return DO;}
{VAR}			{return VAR;}
{TIPO}			{yylval.cadeia= (char *) strdup(yytext); return TIPO;}
{ID}			{yylval.cadeia= (char *) strdup(yytext); return ID;}
{NUM}			{return NUM;}

(":=") 			{return OP_ATRIB;}
("(") 			{return PAR_ABRE;}
(")") 			{return PAR_FECHA;}
(",") 			{return VIRGULA;}
(";") 			{return PONTO_VIRGULA;}
(":")			{return DOIS_PONTOS;}
(".")			{return PONTO;}

{RELACAO} 		{return RELACAO;}
{SOMA}	 		{return SOMA;}
{SUB}	 		{return SUB;}
{MULT}	 		{return MULT;}

{BRANCO}		{;}
.				{return yytext[0];}


%%
int yywrap() {
 return 1;
}