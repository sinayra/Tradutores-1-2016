/* Verificando a sintaxe de programas segundo nossa GLC-exemplo */
/* considerando notacao polonesa para expressoes */

%{
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "lista.h"

extern int yylineno;
int erro_semantico = 0;


int yylex();
void yyerror(const char *s);

int busca_tabela(char *id);
void verifica_tabela();
int checa_elemento(char *nome);

%}

%union {
	char *cadeia;
}

%token PROGRAM
%token FUNCTION
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

programa:	PROGRAM ID PONTO_VIRGULA {
							TS temp;
							strcpy(temp.cadeia, $ID);
							temp.tipo = TIPO_INDEFINIDO;
							temp.usado = 1;
							temp.estr = PROGRAMA;
							
							inserir_elemento_no_final(temp);

							printf("Nome do programa: %s \n", $ID);
						}  
						bloco_principal PONTO 
;

bloco_principal:  variavel_declaracao_inicio funcao_declaracao_inicio BLOCO_ABRE componente BLOCO_FECHA	{;}
;

componente:	estrutura {;}
			|componente estrutura{;}
;
estrutura: 	estrutura_simples PONTO_VIRGULA{;}
			|estrutura_bloco {;}
;
estrutura_bloco: bloco_composto {;}
				|WHILE rel DO estrutura {;}
;
bloco_composto:	BLOCO_ABRE componente BLOCO_FECHA {;}
;

estrutura_simples:		ID OP_ATRIB exp			
						{
							if(!checa_elemento($ID)){
								erro_semantico = 1;
								printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
							}
							
						}
						| IO PAR_ABRE argumentos_IO PAR_FECHA{;}
		
;

variavel_declaracao_inicio:	/*empty*/	{;}
							| VAR variavel_declaracao_lista	{;}
;

variavel_declaracao_lista:	variavel_declaracao PONTO_VIRGULA	{;}
							|variavel_declaracao PONTO_VIRGULA variavel_declaracao_lista	{;}
;
	
variavel_declaracao:	ID DOIS_PONTOS TIPO	
						{
							TS temp;
							strcpy(temp.cadeia, $ID);
							temp.tipo = get_TIPO($TIPO);
							temp.usado = 0;
							temp.estr = VARIAVEL;
							
							inserir_elemento_no_final(temp);

							printf("ID declarado: %s\n", $ID);

						}
						|ID VIRGULA variavel_declaracao	
						{
							TS temp1, temp2;
							int index = get_n_simbolos() - 1;

							temp2 = buscar_elemento_indice(index);

							strcpy(temp1.cadeia, $ID);
							temp1.tipo = temp2.tipo;
							temp1.usado = 0;
							temp1.estr = VARIAVEL;

							inserir_elemento_no_final(temp1);

							printf("ID declarado: %s\n", $ID);
						}
;

funcao_declaracao_inicio:	/*empty*/	{;}
					| funcao_declaracao_lista  {;}
;

funcao_declaracao_lista:	funcao_declaracao {;}
							| funcao_declaracao funcao_declaracao_lista {;}
;
funcao_declaracao:	FUNCTION ID PAR_ABRE PAR_FECHA DOIS_PONTOS TIPO PONTO_VIRGULA
						{
							TS temp;
							strcpy(temp.cadeia, $ID);
							temp.tipo = get_TIPO($TIPO);
							temp.usado = 0;
							temp.estr = FUNCAO;

							inserir_elemento_no_final(temp);

							printf("Declaracao de funcao: %s \n", $ID);
						} 
						estrutura PONTO_VIRGULA
;
exp:	NUM					{;}
		| ID				
		{
			if(!checa_elemento($ID)){
				erro_semantico = 1;
				printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
			}
			
		}
		| exp SOMA exp		{;}
		| exp SUB exp		{;}
		| exp MULT exp		{;}
		| ID PAR_ABRE PAR_FECHA
		{
			if(!checa_elemento($ID)){
				erro_semantico = 1;
				printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
			}
			
		}
;
rel:	exp RELACAO exp	{;}
;

IO:	READ {;}
	|WRITE {;}
;

argumentos_IO:	ID 
				{
					if(!checa_elemento($ID)){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
					}
				}
				| ID VIRGULA argumentos_IO 
				{
					if(!checa_elemento($ID)){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
					}
				}
;



%%

int checa_elemento(char *nome){
	int index = existe_elemento(nome);
	if(index >= 0){
		TS temp = buscar_elemento_indice(index);
		if(temp.usado == 0){
			temp.usado = 1;
			editar_elemento(index, temp);
			printf("ID usado: %s \n", nome);
		}
		return 1;
	}
	return 0;
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
		yyout = stdout;

	erro = yyparse();
	
	if(erro == 0){		/*Se o programa estiver sintaticamente correto, ele checa o semantico*/
		imprimir_lista();
		
		printf("\nPrograma sintaticamente correto\n");
		
		if(erro_semantico == 0)
			printf("Programa semanticamente correto\n");
		else
			printf("semantic error\n");
		
		verifica_tabela();
	}
	
	fclose(yyin);
	fclose(yyout);
	excluir_TS();
}

void yyerror (const char *s){
	extern FILE *yyout;
	printf ("%s\n", s);
}
