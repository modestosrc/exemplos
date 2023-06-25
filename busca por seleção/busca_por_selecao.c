#include <stdio.h>

void ordenarPorSelecao(int array[], int size) {
    int i, j, minIndex, temp;
  
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        
        // Troca o elemento atual com o elemento mínimo encontrado
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("Array antes da ordenação:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    ordenarPorSelecao(array, size);
    
    printf("\n\nArray depois da ordenação:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}