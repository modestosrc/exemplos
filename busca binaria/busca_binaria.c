#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
	
unsigned int *criaLista(size_t tamanho_lista) {
    unsigned int *lista;

    lista = (unsigned int *)malloc(tamanho_lista * sizeof(unsigned int));
    if (lista == NULL) {
        printf ("Lista não alocada corretamente!");
        return NULL;
    }

    unsigned int *inicio_lista = lista;

    for (int i = 0; i <= tamanho_lista; i++) {
        *lista = i;
        lista++;
    }

    return inicio_lista;
}

unsigned int buscaBinaria(unsigned int *lista, unsigned int tamanho_lista, unsigned int numero_pesquisado) {
    unsigned int baixo = 0;
    unsigned int alto = tamanho_lista; 
    unsigned int lopps_usados = 0;
    unsigned int indice;

    while (baixo <= alto) {
        lopps_usados++;
        indice = (baixo + alto) / 2;
        unsigned int chute = lista[indice];
        
        if (chute == numero_pesquisado) goto FIM;
        if (chute > numero_pesquisado) alto = indice - 1;
        else baixo = indice + 1;
    }

    printf("Não encontrado!\n");
    return -1;
    FIM:
    printf("Loops usados: %u\n", lopps_usados);
    return indice;
}

int main(int argc, char *argv[]) {
    unsigned int numero = strtoul(argv[1], NULL, 10);
    size_t tamanho_lista = strtoul(argv[2], NULL, 10);
    unsigned int *lista = criaLista(tamanho_lista);
    unsigned int indice;

    indice = buscaBinaria(lista, tamanho_lista, numero);
    if (indice == -1) return 1;
    printf("Numero está em: %u\n", indice);

    return 0;
}
