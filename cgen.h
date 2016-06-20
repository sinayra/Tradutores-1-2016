#pragma once
#include <stdio.h>
#include "code.h"

typedef enum{
	INSTR_INICIO,
	INSTR_FIM,
	INSTR_WRITE,
	INSTR_READ,
	INSTR_STORE_MEMORIA,
	INSTR_LOAD_MEMORIA,
	INSTR_STORE_MEMORIA_TEMP,
	INSTR_LOAD_CTE,
	INSTR_ADD,
	INSTR_SUB,
	INSTR_MULT,
	INSTR_DIV,
	INSTR_TEMP_ACS,
	INSTR_REL_MENOR,
	INSTR_REL_MAIOR,
	INSTR_REL_IGUAL,
	INSTR_STORE_REL,
	INSTR_JUMP_REL_FALSE,
	INSTR_JUMP,
	INSTR_INVALIDA
}tipoInstr;




//Escreve no arquivo de saída o código intermediário
void montador(FILE *out, tipoInstr tipo, int valor, int reg);
void escreverComentario(FILE *out, char *str);

int getLinhaAtual();
int setLinhaAtual(int linha);
