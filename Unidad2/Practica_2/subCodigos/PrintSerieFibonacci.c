#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    printf("El termino en la posicion %d es: %d\n",n,fibonacci(n));
    return 0;
}