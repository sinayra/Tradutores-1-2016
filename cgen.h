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
	INSTR_LOAD_CTE,
	INSTR_INVALIDA
}tipoInstr;

//Escreve no arquivo de saída o código intermediário
void montador(FILE *out, tipoInstr tipo, int valor);