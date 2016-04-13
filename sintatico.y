/* Verificando a sintaxe de programas segundo nossa GLC-exemplo */
/* considerando notacao polonesa para expressoes */
%{
#include <stdio.h> 
%}
%token BLOCO_ABRE
%token BLOCO_FECHA
%token WHILE
%token DO
%token NUM
%token ID
%token OP_ATRIB
%token RELACAO
%token OP_ARIT

%%
/* Regras definindo a GLC e acoes correspondentes */
/* neste nosso exemplo quase todas as acoes estao vazias */

programa:	 BLOCO_ABRE lista_cmds BLOCO_FECHA 	{;} /*Tiramos BLOCO_ABRE e BLOCO_FECHA da regra. Colocar de volta depois*/
;
lista_cmds:	cmd				{;}
		| cmd ';' lista_cmds	{;}
;
cmd:		ID OP_ATRIB exp			{;}
			|WHILE rel DO cmd {;}
		
	
;
exp:		NUM				{;}
		| ID				{;}
		| exp exp OP_ARIT	{;}
;
rel:	exp RELACAO exp	{;}
;

%%
extern FILE *yyin;
int main (int argc, char*argv[]) {
	int erro;

	printf("Lendo o arquivo %s\n", argv[1]);
	yyin = fopen(argv[1], "r");

	if(yyin){
		erro = yyparse();

		if(erro == 0)
			printf("Programa sintaticamente correto!\n");
	}
	else
		printf("Erro na leitura do arquivo %s\n", argv[1]);

	return 0;
}

yyerror (s){
	fprintf (stderr, "%s\n", s);
}
