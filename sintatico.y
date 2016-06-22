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
void processa_operacao(int isNum1, int val1, int arit1, int isNum2, int val2, int arit2, tipoInstr tipo);
int checa_elemento(char *nome);
int checa_tipo(TS var, int isNum, int isBool, int isArit);

%}

%union {
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
%token TRUE
%token FALSE
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
%type<valor> NUM TRUE FALSE estrutura

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

					linhaaux = (linhatual_aux - 2) - $4; //(PC+4) - 2 instruções de linha_rel
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
								int tipo = checa_tipo(buscar_elemento_indice(index), $exp.isNum, $exp.isBool, $exp.isArit);
								if(tipo){
									if(!$exp.isArit){
										if($exp.isNum || $exp.isBool){
											montador(yyout, INSTR_LOAD_CTE, $exp.val, ac);
										}
										else{
											montador(yyout, INSTR_LOAD_MEMORIA, $exp.val, ac);
											
										}
									}
									else
										montador(yyout, INSTR_LOAD_MEMORIA_TEMP, -1, ac);

									montador(yyout, INSTR_STORE_MEMORIA, index, ac);
								}
							}
							escreverComentario(yyout, "Fim de atribuicao");
							
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
			$$.isArit = 0;
			$$.isBool = 0;
		}
		|TRUE					
		{
			$$.val = $TRUE;
			$$.isNum = 0;
			$$.isArit = 0;
			$$.isBool = 1;
		}
		|FALSE					
		{
			$$.val = $FALSE;
			$$.isNum = 0;
			$$.isArit = 0;
			$$.isBool = 1;
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
				$$.isArit = 0;
				$$.isBool = 0;
			}
			
		}
		| NOT exp {;}
		| exp SOMA exp		
		{
			escreverComentario(yyout, "Processo de adicao");

			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_ADD);

			escreverComentario(yyout, "Fim de adicao");
			$$.isArit = 1;
		}
		| exp SUB exp		
		{
			escreverComentario(yyout, "Processo de subtracao");
			
			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_SUB);

			escreverComentario(yyout, "Fim de subtracao");
			$$.isArit = 1;
		}
		| exp MULT exp		
		{
			escreverComentario(yyout, "Processo de multiplicacao");
			
			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_MULT);

			escreverComentario(yyout, "Fim de multiplicacao");
			$$.isArit = 1;
		}
		| exp DIV exp 
		{
			escreverComentario(yyout, "Processo de divisao");
			
			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_DIV);

			escreverComentario(yyout, "Fim de divisao");
			$$.isArit = 1;
		}
		| PAR_ABRE rel PAR_FECHA	
		{
			$$.isArit = $rel.isArit; /*para passar para arvore sintática o valor de expressão se ela for aritmética*/
		}
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
			escreverComentario(yyout, "Processo de relacao <");
			$$.inicio = getLinhaAtual();

			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_REL_MENOR);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2); //+ duas instruções quando for dar jump
			$$.isArit = 0;
			$$.isBool = 1;

			escreverComentario(yyout, "Fim de <");
		}
		|exp REL_MAIOR exp
		{
			escreverComentario(yyout, "Processo de relacao >");
			$$.inicio = getLinhaAtual();

			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_REL_MAIOR);
			montador(yyout, INSTR_STORE_REL, -1, -1);
			
			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2); //+ duas instruções quando for dar jump
			$$.isArit = 0;
			$$.isBool = 1;

			escreverComentario(yyout, "Fim de >");
		}
		|exp REL_IGUAL exp
		{
			escreverComentario(yyout, "Processo de relacao =");
			$$.inicio = getLinhaAtual();
			
			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_REL_IGUAL);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2); //+ duas instruções quando for dar jump
			$$.isArit = 0;
			$$.isBool = 1;

			escreverComentario(yyout, "Fim de =");
		}
		|exp REL_MAIOR_IGUAL exp 
		{
			escreverComentario(yyout, "Processo de relacao >=");
			$$.inicio = getLinhaAtual();

			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_REL_MAIOR_IGUAL);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2);
			$$.isArit = 0;
			$$.isBool = 1;

			escreverComentario(yyout, "Fim de >=");
		
		}
		|exp REL_MENOR_IGUAL exp 
		{
			escreverComentario(yyout, "Processo de relacao <=");
			$$.inicio = getLinhaAtual();

			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit,INSTR_REL_MENOR_IGUAL);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2);
			$$.isArit = 0;
			$$.isBool = 1;

			escreverComentario(yyout, "Fim de <=");
		
		}
		|exp REL_DIF exp 
		{
			escreverComentario(yyout, "Processo de relacao <>");
			$$.inicio = getLinhaAtual();

			processa_operacao($1.isNum, $1.val, $1.isArit, $3.isNum, $3.val, $3.isArit, INSTR_REL_DIF);
			montador(yyout, INSTR_STORE_REL, -1, -1);

			$$.fim = getLinhaAtual();
			setLinhaAtual($$.fim + 2);
			$$.isArit = 0;
			$$.isBool = 1;

			escreverComentario(yyout, "Fim de <>");
		}
		|exp AND exp {;}
		|exp OR exp {;}
		|exp {;}
;

argumentos_O:	exp 
				{	
					if($exp.isArit){
						montador(yyout, INSTR_LOAD_MEMORIA_TEMP, $exp.val, ac);
						montador(yyout, INSTR_WRITE, $exp.val, ac);
					}
					else{
						if($exp.isNum){
							montador(yyout, INSTR_LOAD_CTE, $exp.val, ac);
							montador(yyout, INSTR_WRITE, $exp.val, ac);
						}
						else{
							montador(yyout, INSTR_LOAD_MEMORIA, $exp.val, ac);
							montador(yyout, INSTR_WRITE, $exp.val, ac);
						}
					}
				}
				| argumentos_O VIRGULA exp
				{
					if($exp.isArit){
							montador(yyout, INSTR_LOAD_MEMORIA_TEMP, $exp.val, ac);
							montador(yyout, INSTR_WRITE, $exp.val, ac);
						}
					else{
						if($exp.isNum){
							montador(yyout, INSTR_LOAD_CTE, $exp.val, ac);
							montador(yyout, INSTR_WRITE, $exp.val, ac);
						}
						else{
							montador(yyout, INSTR_LOAD_MEMORIA, $exp.val, ac);
							montador(yyout, INSTR_WRITE, $exp.val, ac);
						}
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
