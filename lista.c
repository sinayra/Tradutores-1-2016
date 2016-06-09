#include "lista.h"

int n_simbolos = 0;
TS *lista = NULL;

int get_n_simbolos(){
	return n_simbolos;
}

tipoID get_TIPO(char *tipo){
    if(strcmp("integer", tipo) == 0)
        return INTEGER;
    else if(strcmp("boolean", tipo) == 0)
        return BOOLEAN;
    else if(strcmp("char", tipo) == 0)
        return CHAR;
    return TIPO_INDEFINIDO;
}

void inserir_elemento_no_final(TS novo_valor) {
    TS *lista_aux;
    
    n_simbolos++;
    lista_aux = (TS*) realloc (lista, n_simbolos * sizeof(TS));

    if (lista_aux) {
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
    if(lista){
    	for (int i = 0; i < n_simbolos; i++){
        	if(strcmp(lista[i].cadeia, valor_procura) == 0)
        	    return i;
    	}
    }
    return -1;
}

TS buscar_elemento_indice(int indice_busca) {
    TS aux;

    aux.cadeia[0] = '\0';
    aux.tipo = TIPO_INDEFINIDO;
    aux.estr = ESTRUTURA_INDEFINIDA;
    aux.usado = -1;

    if(lista && (indice_busca < n_simbolos && indice_busca >= 0))
    	aux = lista[indice_busca];

    return aux;
}

void imprimir_lista() {
    if(lista){
        printf("\n******TABELA DE SIMBOLOS*****\n\nNome\tEstr\tTipo\tUsado\tValorInt\n");		/*Imprime tabela de simbolos*/
    	for (int i = 0; i < n_simbolos; i++)
    		printf("%s\t%d\t%d\t%d\t%d\n", lista[i].cadeia, lista[i].estr, lista[i].tipo, lista[i].usado, lista[i].valorInt);
        printf("\n");
    }
}

void excluir_TS(){
    free(lista);
}

