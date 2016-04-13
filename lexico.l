%{
#include <stdio.h>
#include "sintatico.tab.h"
%}

BLOCO_ABRE	("comeca")
BLOCO_FECHA ("termina")
WHILE ("while")
DO ("do")
ID	[a-zA-Z][a-zA-Z0-9]*	
NUM 	("+"|"-")?[0-9]+(".")[0-9]+
BRANCO	(" "|"\t"|"\n"|"\r")
OP_ARIT		("+"|"-"|"*")
RELACAO	("<"|">"|"=")

%%
{BLOCO_ABRE} 	{return BLOCO_ABRE;}
{BLOCO_FECHA}	{return BLOCO_FECHA;}
{WHILE}			{return WHILE;}
{DO}			{return DO;}
{ID}			{return ID;}
{NUM}			{return NUM;}
(":=") 			{return OP_ATRIB;}
{RELACAO} 		{return RELACAO;}
{OP_ARIT} 		{return OP_ARIT;}

{BRANCO}		{;}
.			{return yytext[0];}


%%
int yywrap() {
 return 1;
}

/*
main() {
  printf("Informe um token:\n");
  yylex();
}
*/