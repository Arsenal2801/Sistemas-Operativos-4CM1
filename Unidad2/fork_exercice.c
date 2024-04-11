#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
// Elaboraron:
//           -Ayala Fuentes Sunem Gizeht
//           -Campos Zeron Salvador
// Función para imprimir una serie numérica de dos en dos
void proceso1(int n) {
  int i;
  for (i = 1; i <= n; i += 2) {
    printf("[Proceso-1] %d\n", i);
  }
}

// Función para imprimir la serie Fibonacci
void proceso2(int n) {
  int a = 0, b = 1, c;
  int i;
  printf("[Proceso-2] 0\n");
  printf("[Proceso-2] 1\n");
  for (i = 3; i <= n; i++) {
    c = a + b;
    printf("[Proceso-2] %d\n", c);
    a = b;
    b = c;
  }
}

// Función para imprimir una serie de números pares
void proceso3(int n) {
  int i;
  for (i = 2; i <= n; i += 2) {
    printf("[Proceso-3] %d\n", i);
  }
}

// Función para imprimir una serie de números impares
void proceso4(int n) {
  int i;
  for (i = 1; i <= n; i += 2) {
    printf("[Proceso-4] %d\n", i);
  }
}

int main() {
  int pid1, pid2;
  char nombre[100];

  // Leer el nombre completo del usuario
  printf("Ingrese su nombre completo: ");
  fgets(nombre, sizeof(nombre), stdin);
  nombre[strcspn(nombre, "\n")] = 0; // Eliminar el carácter de nueva línea de fgets

  // Calcular la longitud del nombre completo
  int longitud = strlen(nombre);

  // Realizar la operación módulo 2
  int modulo = longitud % 2;

  // Implementar el modelo jerárquico de procesos
  if (modulo == 0) {
    // Crear el primer proceso
    pid1 = fork();
    if (pid1 < 0) {
      perror("Error al crear el proceso 1");
      exit(1);
    }

    // Si estamos en el proceso 1
    if (pid1 == 0) {
      proceso1(50);
      exit(0);
    }

    // Crear el segundo proceso
    pid2 = fork();
    if (pid2 < 0) {
      perror("Error al crear el proceso 2");
      exit(1);
    }

    // Si estamos en el proceso 2
    if (pid2 == 0) {
      proceso2(10);
      exit(0);
    }

    // Esperar a que los procesos terminen
    wait(NULL);
    wait(NULL);
  } else {
    // Modelo Jerárquico 2

    // Crear el tercer proceso
    pid1 = fork();
    if (pid1 < 0) {
      perror("Error al crear el proceso 3");
      exit(1);
    }

    // Si estamos en el proceso 3
    if (pid1 == 0) {
      proceso3(50);
      exit(0);
    }

    // Crear el cuarto proceso
    pid2 = fork();
    if (pid2 < 0) {
      perror("Error al crear el proceso 4");
      exit(1);
    }

    // Si estamos en el proceso 4
    if (pid2 == 0) {
      proceso4(50);
      exit(0);
    }

    // Esperar a que los procesos terminen
    wait(NULL);
    wait(NULL);
  }

  return 0;
}

