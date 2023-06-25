#include <stdio.h>
#include <stdlib.h>

int fatorial(int argumento) {
    if (argumento < 0) {
        printf("Operação impossivel!\nValor negativo!\n");
        return 0;
    }
    if (argumento == 1 || argumento == 0) return 1;
    else return argumento * fatorial(argumento - 1);
}

int main(int argc, char *argv[]) {
    printf("Fatorial do numero: %d = %d\n", atoi(argv[1]), fatorial(atoi(argv[1])));
    return 0;
}