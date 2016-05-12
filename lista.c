#include "lista.h"

static int n_simbolos = 0;

static int get_n_simbolos(){
	return n_simbolos;
}

key_t* inserir_elemento_no_final(key_t* lista, TS novo_valor) {
    key_t* elemento = (key_t*)malloc(sizeof(key_t));
    elemento->valor = novo_valor;
    elemento->next = NULL;
	elemento->index = n_simbolos;
	
	n_simbolos++;
	
    if (lista == NULL) {
        return elemento;
    } else {
        key_t* aux = lista;
        while (aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = elemento;
        return lista;
    }
}

int buscar_elemento(key_t* lista, char *valor_procura) {

    if(lista == NULL){
		return 0;
	}

    key_t* aux = lista;
    while ((aux!=NULL) && (strcmp(aux->valor.cadeia, valor_procura) != 0)){
        aux = aux->next;
    }
	
	if(aux==NULL) return 0;
	return 1;
	
}

TS buscar_elemento_indice(key_t* lista, int indice_busca) {

    if(lista == NULL) return NULL;
	if(indice_busca >  n_simbolos) return NULL;
	
    key_t* aux = lista;
    while ((aux!=NULL) && (indice_busca != aux->index)){
        aux = aux->next;
    }

    return(aux->valor);
}

void imprimir_lista(key_t* lista) {

    if(lista == NULL) return;

    key_t* aux = lista;
	
    printf("\nNome\tTipo\n");		/*Imprime tabela de simbolos*/
	while (aux!=NULL){
		printf("%s\t%s\t%d\n", aux->valor.cadeia, aux->valor.tipo, aux->valor.usado);
        aux = aux->next;
    }
    printf("\n");
}

