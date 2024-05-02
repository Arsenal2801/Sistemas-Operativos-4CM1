#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int sumaNaturales(int n) {
    return n * (n + 1) / 2;
}

int mcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return mcd(b, a % b);
}

int sumaDigitos(int num) {
    int suma = 0;
    while (num != 0) {
        suma += num % 10;
        num /= 10;
    }
    return suma;
}

int invertirNumero(int num) {
    int invertido = 0;
    while (num != 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}


int esPrimo(int n) {
    if (n <= 1)
        return 0; // No es primo
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0; // No es primo
    }
    return 1; // Es primo
}

void procesoHijo1(pid_t pidNieto1, pid_t pidNieto2, pid_t pidNieto3) {
  printf("[Proceso-Hijo1] Iniciando proceso hijo 1\n");
  
  printf("- El factorial de 5 es: %d\n", factorial(5));
  printf("\n");

  // Crear y ejecutar a los nietos
  pid_t pidNietoAux;
  if ((pidNietoAux = fork()) == 0) {
    procesoNieto1();
    exit(0);
  } else if (pidNietoAux == -1) {
    perror("Error al crear proceso nieto 1");
    exit(1);
  }
  printf("\n");

  if ((pidNietoAux = fork()) == 0) {
    procesoNieto2();
    exit(0);
  } else if (pidNietoAux == -1) {
    perror("Error al crear proceso nieto 2");
    exit(1);
  }
  printf("\n");

  if ((pidNietoAux = fork()) == 0) {
    procesoNieto3();
    exit(0);
  } else if (pidNietoAux == -1) {
    perror("Error al crear proceso nieto 3");
    exit(1);
  }

  // Esperar a que los nietos terminen
  waitpid(pidNieto1, NULL, 0);
  waitpid(pidNieto2, NULL, 0);
  waitpid(pidNieto3, NULL, 0);

  printf("[Proceso-Hijo1] Finalizando proceso hijo 1\n");
}

void procesoHijo2(pid_t pidNieto4) {
  printf("[Proceso-Hijo2] Iniciando proceso hijo 2\n");
  printf("- Suma de los primero 30 naturales: %d\n", sumaNaturales(30));
  printf("\n");

  // Crear y ejecutar al nieto
  pid_t pidNietoAux;
  if ((pidNietoAux = fork()) == 0) {
    procesoNieto4();
    exit(0);
  } else if (pidNietoAux == -1) {
    perror("Error al crear proceso nieto 4");
    exit(1);
  }

  // Esperar a que el nieto termine
  waitpid(pidNieto4, NULL, 0);

  printf("[Proceso-Hijo2] Finalizando proceso hijo 2\n");
}

void procesoNieto1() {
  printf("[Proceso-Nieto1] Realizando tarea de nieto 1\n");
  printf("- El mcd de 5 y 42 es: %d\n", mcd(5, 42));
  printf("[Proceso-Nieto1] Finalizando tarea de nieto 1\n");
}

void procesoNieto2() {
  printf("[Proceso-Nieto2] Realizando tarea de nieto 2\n");
  printf("- La suma de los digitos del numero 325 es: %d\n", sumaDigitos(325));
  printf("[Proceso-Nieto2] Finalizando tarea de nieto 2\n");
}

void procesoNieto3() {
  printf("[Proceso-Nieto3] Realizando tarea de nieto 3\n");
  printf("- El numero 12389 invertido es: %d\n", invertirNumero(12389));
  printf("[Proceso-Nieto3] Finalizando tarea de nieto 3\n");
}

void procesoNieto4() {
  printf("[Proceso-Nieto4] Realizando tarea de nieto 4\n");
  int primo = esPrimo(586324);
  if (primo == 0){
  printf("- El numero 586324 es primo\n");
  } else if (primo == 1){
  printf("- El numero 586324 no es primo\n");
  }
  printf("[Proceso-Nieto4] Finalizando tarea de nieto 4\n");
}

int main() {
 printf("[Proceso-Padre] Iniciando proceso padre\n");
 printf("- Termino 15 de fibonacci: %d\n", fibonacci(15));
  printf("\n");
 pid_t pidHijo1, pidHijo2;
  if ((pidHijo1 = fork()) == 0) {
    procesoHijo1(0, 0, 0);
    exit(0);
  } else if (pidHijo1 == -1) {
    perror("Error al crear proceso hijo 1");
    exit(1);
  }
  waitpid(pidHijo1, NULL, 0);
  printf("\n");
  if ((pidHijo2 = fork()) == 0) {
    procesoHijo2(0);
    exit(0);
  } else if (pidHijo2 == -1) {
    perror("Error al crear proceso hijo 1");
    exit(1);
  }
  waitpid(pidHijo2, NULL, 0);

  printf("[Proceso-Padre] Finalizando proceso padre\n");

  }

  

