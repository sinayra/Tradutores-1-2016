/* Verificando a sintaxe de programas segundo nossa GLC-exemplo */
/* considerando notacao polonesa para expressoes */

%{
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
extern int yylineno;

typedef struct{
	char cadeia[100];
	char tipo[100];
	int usado;
}TS;

TS tab[20];

int n_simbolos = 0;


int erro_semantico = 0;

%}

%union {
	char *cadeia;
}

%token PROGRAM
%token READ
%token WRITE
%token BLOCO_ABRE
%token BLOCO_FECHA
%token WHILE
%token DO
%token VAR
%token TIPO
%token NUM
%token ID
%token OP_ATRIB
%token RELACAO
%token SOMA
%token SUB
%token MULT
%token PAR_ABRE
%token PAR_FECHA
%token VIRGULA
%token PONTO_VIRGULA
%token DOIS_PONTOS
%token PONTO
%left SOMA SUB
%left MULT

%type<cadeia> ID TIPO

%%
/* Regras definindo a GLC e acoes correspondentes */
/* neste nosso exemplo quase todas as acoes estao vazias */

programa:	PROGRAM ID PONTO_VIRGULA {printf("Nome do programa: %s \n", $ID);} bloco_principal PONTO 
;

bloco_principal:  variavel_declaracao_inicio BLOCO_ABRE componente BLOCO_FECHA	{;}
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

estrutura_simples:		ID OP_ATRIB exp			
						{
							if(busca_tabela($ID))
								printf("ID usado: %s \n", $ID);
							else{
								erro_semantico = 1;
								printf("Erro: Linha %d\t %s nao declarado \n", yylineno, $ID);
							}
							
						}
						|func PAR_ABRE argumentos_func PAR_FECHA{;}
		
;

variavel_declaracao_inicio:	/*empty*/	{;}
							| VAR variavel_declaracao_lista	{;}
;

variavel_declaracao_lista:	variavel_declaracao PONTO_VIRGULA	{;}
							|variavel_declaracao PONTO_VIRGULA variavel_declaracao_lista	{;}
;
	
variavel_declaracao:	ID DOIS_PONTOS TIPO	
						{
							strcpy(tab[n_simbolos].cadeia, $ID);
							strcpy(tab[n_simbolos].tipo, $TIPO);
							tab[n_simbolos].usado = 0;

							n_simbolos++;
							printf("ID declarado: %s\n", $ID);

						} 
						|ID VIRGULA variavel_declaracao	
						{
							strcpy(tab[n_simbolos].cadeia, $ID);
							strcpy(tab[n_simbolos].tipo, tab[n_simbolos - 1].tipo);

							n_simbolos++;
							printf("ID declarado: %s\n", $ID);
						}
;
exp:	NUM					{;}
		| ID				
		{
			if(busca_tabela($ID))
				printf("ID usado: %s \n", $ID);
			else{
				erro_semantico = 1;
				printf("Erro: Linha %d\t %s nao declarado \n", yylineno, $ID);
			}
			
		}
		| exp SOMA exp		{;}
		| exp SUB exp		{;}
		| exp MULT exp		{;}
;
rel:	exp RELACAO exp	{;}
;

func:		READ {;}
			|WRITE {;}
;

argumentos_func:	 ID {printf("ID declarado: %s \n", $ID);}
					| ID VIRGULA argumentos_func {printf("ID declarado: %s \n", $ID);}
;



%%

int busca_tabela(char *id){		/*Busca simbolo na tabela*/
	int i;
	int finded;
	
	for(i = 0; i < n_simbolos; i++){
		if(!strcmp(tab[i].cadeia, id)){
			tab[i].usado = 1;
			return 1;
		}
	}
	return 0;
}

void verifica_tabela(){		/*Verifica se ha simbolos nao utilizados*/
	int i;
	for(i = 0; i < n_simbolos; i++){
		if(tab[i].usado == 0)
			printf("Warning: variavel %s declarada, mas nao utilizada\n", tab[i].cadeia);
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
		yyin = stdin;    /* cria arquivo de saida se especificado */
	if(argc > 1)
		yyout = fopen(argv[1],"wt");
	else
		yyout = stdout;

	erro = yyparse ();
	
	if(erro == 0){		/*Se o programa estiver sintaticamente correto, ele checa o semantico*/
		int i;
		printf("\nNome\tTipo\n");		/*Imprime tabela de simbolos*/
		for(i = 0; i < n_simbolos; i++){
			printf("%s\t%s\n", tab[i].cadeia, tab[i].tipo);
		}
		
		printf("\nPrograma sintaticamente correto\n");
		
		if(erro_semantico == 0)
			printf("Programa semanticamente correto\n");
		else
			printf("semantic error\n");
		
		verifica_tabela();
	}
	
	fclose(yyin);
	fclose(yyout);
}

yyerror (s){
	extern FILE *yyout;
	printf ("%s\n", s);
}
