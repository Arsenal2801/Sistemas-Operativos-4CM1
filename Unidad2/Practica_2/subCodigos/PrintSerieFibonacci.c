#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    printf("El termino en la posicion %d es: %d\n",n,fibonacci(n));
    return 0;
}