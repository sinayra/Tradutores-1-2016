#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char cadeia[100];
	char tipo[100];
	int usado;
}TS;

int get_n_simbolos();
void editar_elemento(int indice, TS linha);
void imprimir_lista();
TS buscar_elemento_indice(int indice_busca);
int existe_elemento(char *valor_procura);
void inserir_elemento_no_final(TS novo_valor);
void excluir_TS();