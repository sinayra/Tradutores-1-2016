#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct key_t {
    TS valor;
    struct key_t* next;
	int index;
} key_t;

typedef struct{
	char cadeia[100];
	char tipo[100];
	int usado;
}TS;

static int get_n_simbolos();
void imprimir_lista(key_t* lista);
TS buscar_elemento_indice(key_t* lista, int indice_busca);
int buscar_elemento(key_t* lista, char *valor_procura);
key_t* inserir_elemento_no_final(key_t* lista, TS novo_valor);