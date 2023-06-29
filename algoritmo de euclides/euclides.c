#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    int resultado;
    if ( a < b ) {
        int c = a;
        a = b;
        b = c;
    }
    int r = a % b;
    if ( r == 0 ) resultado = b;
    else resultado = mdc(b, r);

    return resultado;
}

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
   printf("MDC de %d e %d é = %d\n",a, b, mdc(a, b));

   return 0;
}
