#include "lista.h"

int n_simbolos = 0;
TS *lista = NULL;

int get_n_simbolos(){
	return n_simbolos;
}

void inserir_elemento_no_final(TS novo_valor) {
    TS *lista_aux;
    n_simbolos++;

    lista_aux = (TS*) realloc (lista, n_simbolos * sizeof(TS));

    if (lista_aux != NULL) {
        lista = lista_aux;
        lista[n_simbolos - 1] = novo_valor;
    }
    else {
        free(lista);
        printf("Erro com realloc");
        exit(EXIT_FAILURE);
    }

}

void editar_elemento(int indice, TS linha){
    if(lista && (indice < n_simbolos && indice >= 0))
        lista[indice] = linha;
}

int existe_elemento(char *valor_procura) {

    if(lista == NULL) return -1;
    for (int i = 0; i < n_simbolos; i++){
        if(strcmp(lista[i].cadeia, valor_procura) == 0)
            return i;
    }
    return -1;
}

TS buscar_elemento_indice(int indice_busca) {
    TS aux;

    strcpy(aux.cadeia, "");
    strcpy(aux.tipo, "");
    aux.usado = -1;

    if(lista == NULL) return aux;
	if(indice_busca >  n_simbolos || indice_busca < 0) return aux;

    aux = lista[indice_busca];

    return aux;
}

void imprimir_lista() {

    if(lista){
        printf("\n******TABELA DE SIMBOLOS*****\n\nNome\tTipo\tUsado\n");		/*Imprime tabela de simbolos*/
    	for (int i = 0; i < n_simbolos; i++)
    		printf("%s\t%s\t%d\n", lista[i].cadeia, lista[i].tipo, lista[i].usado);
        printf("\n");
    }
}

void excluir_TS(){
    free(lista);
}

