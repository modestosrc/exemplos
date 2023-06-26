#include <stdio.h>

void trocarElementos(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int array[], int inicio, int fim) {
    int pivo = array[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (array[j] < pivo) {
            i++;
            trocarElementos(&array[i], &array[j]);
        }
    }

    trocarElementos(&array[i + 1], &array[fim]);
    return (i+1);
}

void quicksort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particiona(array, inicio, fim);
        quicksort(array, inicio, indicePivo - 1);
        quicksort(array, indicePivo + 1, fim);
    }
}

int main(void) {
    int array[] = { 7, 5, 3, 1, 8, 7, 5, 9, 0 };
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original : ");
    for (int i = 0; i < tamanho; i++) printf("%d ", array[i]);
    printf("\n");

    quicksort(array, 0, tamanho -1);

    printf("Array ordenado : ");
    for (int i = 0; i < tamanho; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}
