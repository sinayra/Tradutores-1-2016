/* Verificando a sintaxe de programas segundo nossa GLC-exemplo */
/* considerando notacao polonesa para expressoes */
%{
#include <stdio.h> 
%}
%token READ
%token WRITE
%token BLOCO_ABRE
%token BLOCO_FECHA
%token WHILE
%token DO
%token NUM
%token ID
%token OP_ATRIB
%token RELACAO
%token OP_ARIT
%token PAR_ABRE
%token PAR_FECHA
%token VIRGULA
%token PONTO_VIRGULA

%%
/* Regras definindo a GLC e acoes correspondentes */
/* neste nosso exemplo quase todas as acoes estao vazias */

programa:	 BLOCO_ABRE componente BLOCO_FECHA 	{;} /*Tiramos BLOCO_ABRE e BLOCO_FECHA da regra. Colocar de volta depois*/
;

componente:	estrutura {;}
			|estrutura PONTO_VIRGULA componente {;}
;

estrutura: 	estrutura_simples {;}
			|estrutura_bloco {;}
;
estrutura_bloco: bloco_composto {;}
				|WHILE rel DO estrutura {;}
;
bloco_composto:	BLOCO_ABRE repete_estrutura BLOCO_FECHA {;}
;
repete_estrutura: 	estrutura {;}
					| estrutura PONTO_VIRGULA repete_estrutura {;}
;

estrutura_simples:		ID OP_ATRIB exp			{;}
						|func PAR_ABRE argumentos_func PAR_FECHA{;}
		
;
exp:		NUM				{;}
		| ID				{;}
		| exp exp OP_ARIT	{;}
;
rel:	exp RELACAO exp	{;}
;

func:		READ {;}
			|WRITE {;}
;

argumentos_func:	 ID {;}
					| ID VIRGULA argumentos_func {;}
;

%%
int main(int argc, char* argv[]){
	extern FILE *yyin;
	extern FILE *yyout;
	int erro;

	++argv; --argc; 	    /* abre arquivo de entrada se houver */
	if(argc > 0)
		yyin = fopen(argv[0],"rt");
	else
		yyin = stdin;    /* cria arquivo de saida se especificado */
	if(argc > 1)
		yyout = fopen(argv[1],"wt");
	else
		yyout = stdout;

	erro = yyparse ();

	if(erro == 0)
		fprintf(yyout, "Programa sintaticamente correto");

	fclose(yyin);
	fclose(yyout);
}

yyerror (s){
	extern FILE *yyout;
	fprintf (yyout, "%s\n", s);
}
