#include <stdio.h>

int somaRecursiva(int lista[], int tamanho) {
    if (tamanho <= 0) {
        return 0;
    } else {
        return lista[tamanho - 1] + somaRecursiva(lista, tamanho - 1);
    }
}

int main(void) {
    int lista[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    int soma = somaRecursiva(lista, tamanho);

    printf("%d\n", soma);

    return 0;
}
