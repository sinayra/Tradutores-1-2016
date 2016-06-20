/* Verificando a sintaxe de programas segundo nossa GLC-exemplo */
/* considerando notacao polonesa para expressoes */

%{
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
int checa_elemento(char *nome);

%}

%union {
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
}

%nonassoc IF_CONFLICT	/*Estruturas para eliminar a ambiguidade do IF THEN ELSE*/
%nonassoc ELSE

%token PROGRAM
%token FUNCTION
%token PROCEDURE
%token READ
%token WRITE
%token BLOCO_ABRE
%token BLOCO_FECHA
%token WHILE
%token IF
%token THEN
%token ELSE
%token DO
%token VAR
%token TIPO
%token NUM
%token ID
%token OP_ATRIB
%token REL_MENOR
%token REL_MAIOR
%token REL_IGUAL
%token REL_MENOR_IGUAL
%token REL_MAIOR_IGUAL
%token REL_DIF
%token SOMA
%token SUB
%token MULT
%token DIV
%token AND
%token OR
%token NOT
%token PAR_ABRE
%token PAR_FECHA
%token VIRGULA
%token PONTO_VIRGULA
%token DOIS_PONTOS
%token PONTO
%left SOMA SUB
%left MULT DIV
%left NOT

%type<cadeia> ID TIPO
%type<tipoExp> exp
%type<tipoRel> rel
%type<valor> NUM estrutura

%%
/* Regras definindo a GLC e acoes correspondentes */
/* neste nosso exemplo quase todas as acoes estao vazias */

programa:	PROGRAM ID PONTO_VIRGULA 
			{
				
				TS temp;
				strcpy(temp.cadeia, $ID);
				temp.tipo = TIPO_INDEFINIDO;
				temp.usado = 1;
				temp.estr = PROGRAMA;
				
				inserir_elemento_no_final(temp);

			}  
			bloco_principal PONTO 
;

bloco_principal:  variavel_declaracao_inicio funcao_declaracao_inicio BLOCO_ABRE componente BLOCO_FECHA	{;}
;

componente:	estrutura {;}
			|componente estrutura{;}
;
estrutura: 	estrutura_simples PONTO_VIRGULA {$$ = getLinhaAtual();}
			|estrutura_bloco {$$ = getLinhaAtual();}
;
estrutura_bloco: bloco_composto {;}
				|WHILE rel DO estrutura	
				{
					int linhaaux;
					setLinhaAtual($rel.fim);

					linhaaux = ($estrutura - 1 + 2) - ($rel.fim + 1); //(PC+4 + 2 intruções do jump de volta pro while) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP_REL_FALSE, linhaaux, -1);

					setLinhaAtual($estrutura);
					linhaaux = $rel.inicio - ($estrutura + 2); //+2 instruções pro jump no final
					montador(yyout, INSTR_JUMP, linhaaux, -1);
				}
				|IF rel THEN estrutura %prec IF_CONFLICT
				{
					int linhaaux;
					setLinhaAtual($rel.fim);

					linhaaux = ($estrutura - 1) - ($rel.fim + 1); //(PC+4) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP_REL_FALSE, linhaaux, -1);

					setLinhaAtual($estrutura);
				}
				|IF rel THEN estrutura ELSE 
				{
					setLinhaAtual($4 + 2); //mais duas instruções do jump
				} 
				estrutura 
				{
					int linhaaux, linhatual_aux;
					linhatual_aux = getLinhaAtual();

					setLinhaAtual($rel.fim);
					linhaaux = ($4 - 1 + 2) - ($rel.fim + 1); //(PC-4 + 2 instruções de jump) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP_REL_FALSE, linhaaux, -1);

					setLinhaAtual($4);

					linhaaux = (linhatual_aux - 1) - $4; //(PC+4) - 2 instruções de linha_rel
					montador(yyout, INSTR_JUMP, linhaaux, -1);

					setLinhaAtual(linhatual_aux);
				}

bloco_composto:	BLOCO_ABRE componente BLOCO_FECHA {;}
;

estrutura_simples:		ID OP_ATRIB exp			
						{
							escreverComentario(yyout, "Processo de atribuicao");
							int index = checa_elemento($ID);
							if(index < 0){
								erro_semantico = 1;
								printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
							}
							else{
								if(!$exp.arit){
									if($exp.isNum){
										montador(yyout, INSTR_LOAD_CTE, $exp.val, ac);
									}
									else{
										montador(yyout, INSTR_LOAD_MEMORIA, $exp.val, ac);
										
									}
								}
								montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
								montador(yyout, INSTR_STORE_MEMORIA, index, ac);
							}
							escreverComentario(yyout, "Fim de adicao");
							
						}
						| READ PAR_ABRE argumentos_I PAR_FECHA {;}
						| WRITE PAR_ABRE argumentos_O PAR_FECHA {;}
						| ID PAR_ABRE PAR_FECHA
						{
							int index = checa_elemento($ID);
							if(index < 0){
								erro_semantico = 1;
								printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
							}
							
						}
		
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

							//printf("ID declarado: %s\n", $ID);

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

							//printf("ID declarado: %s\n", $ID);
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

							//printf("Declaracao de funcao: %s \n", $ID);
						} 
						estrutura PONTO_VIRGULA
					| PROCEDURE ID PAR_ABRE PAR_FECHA PONTO_VIRGULA
						{
							TS temp;
							strcpy(temp.cadeia, $ID);
							temp.tipo = TIPO_INDEFINIDO;
							temp.usado = 0;
							temp.estr = PROCEDIMENTO;

							inserir_elemento_no_final(temp);

							//printf("Declaracao de procedure: %s \n", $ID);
						}
						estrutura PONTO_VIRGULA
;
exp:	NUM					
		{

			$$.val = $NUM;
			$$.isNum = 1;
			$$.arit = 0;
		}
		| ID				
		{
			int index = checa_elemento($ID);
			if(index < 0){
				erro_semantico = 1;
				printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
			}
			else{
				$$.val = index;
				$$.isNum = 0;
				$$.arit = 0;
			}
			
		}
		| NOT exp {;}
		| exp SOMA exp		
		{
			escreverComentario(yyout, "Processo de adicao");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_ADD, -1, -1);	
			escreverComentario(yyout, "Fim de adicao");
			$$.arit = 1;
		}
		| exp SUB exp		
		{
			escreverComentario(yyout, "Processo de subtracao");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_SUB, -1, -1);	
			escreverComentario(yyout, "Fim de subtracao");
			$$.arit = 1;
		}
		| exp MULT exp		
		{
			escreverComentario(yyout, "Processo de multiplicacao");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_MULT, -1, -1);	
			escreverComentario(yyout, "Fim de multiplicacao");
			$$.arit = 1;
		}
		| exp DIV exp 
		{
			escreverComentario(yyout, "Processo de divisao");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_DIV, -1, -1);	
			escreverComentario(yyout, "Fim de divisao");
			$$.arit = 1;
		}
		| PAR_ABRE rel PAR_FECHA	{;}
		| ID PAR_ABRE PAR_FECHA				/*Para funções sem argumentos*/
		{
			if(checa_elemento($ID) == -1){
				erro_semantico = 1;
				printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
			}
			
		}
;
rel:	 exp REL_MENOR exp	
		{
			$$.inicio = getLinhaAtual();
			escreverComentario(yyout, "*** Processo de relacao < ***");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_REL_MENOR, -1, -1);	

			montador(yyout, INSTR_STORE_REL, -1, -1);
			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2); //+ duas instruções quando for dar jump

			escreverComentario(yyout, "Fim de <");
		}
		|exp REL_MAIOR exp
		{
			$$.inicio = getLinhaAtual();
			escreverComentario(yyout, "Processo de relacao >");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}


			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_REL_MAIOR, -1, -1);	

			montador(yyout, INSTR_STORE_REL, -1, -1);
			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2); //+ duas instruções quando for dar jump

			escreverComentario(yyout, "Fim de >");
		}
		|exp REL_IGUAL exp
		{
			$$.inicio = getLinhaAtual();
			escreverComentario(yyout, "Processo de relacao =");
			if($1.isNum){
				montador(yyout, INSTR_LOAD_CTE, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $1.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			if($3.isNum){
				montador(yyout, INSTR_LOAD_CTE, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}
			else{
				montador(yyout, INSTR_LOAD_MEMORIA, $3.val, ac);
				montador(yyout, INSTR_STORE_MEMORIA_TEMP, ac, ac);
			}

			montador(yyout, INSTR_TEMP_ACS, -1, -1);
			montador(yyout, INSTR_REL_IGUAL, -1, -1);	

			montador(yyout, INSTR_STORE_REL, -1, -1);
			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2); //+ duas instruções quando for dar jump
			escreverComentario(yyout, "Fim de =");
		}
		|exp REL_MAIOR_IGUAL exp {;}
		|exp REL_MENOR_IGUAL exp {;}
		|exp REL_DIF exp {;}
		|exp AND exp {;}
		|exp OR exp {;}
		|exp {;}
;

argumentos_O:	ID 
				{	
					int index = checa_elemento($ID);
					if(index < 0){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
					}
					else{
						montador(yyout, INSTR_LOAD_MEMORIA, index, ac);
						montador(yyout, INSTR_WRITE, index, ac);
					}
					

				}
				| argumentos_O VIRGULA ID
				{	
					int index = checa_elemento($ID);
					if(index < 0){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
					}
					else{
						montador(yyout, INSTR_LOAD_MEMORIA, index, ac);
						montador(yyout, INSTR_WRITE, index, ac);
					}
					
				}
;

argumentos_I:	ID 
				{
					int index = checa_elemento($ID);
					if(index < 0){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
					}
					else{
						montador(yyout, INSTR_READ, index, ac);
					}
				}
				| argumentos_I VIRGULA ID  
				{
					
					int index = checa_elemento($ID);
				
					if(index < 0){
						erro_semantico = 1;
						printf("ERRO Linha %d: %s nao declarado \n", yylineno, $ID);
					}
					else{
						montador(yyout, INSTR_READ, index, ac);
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
