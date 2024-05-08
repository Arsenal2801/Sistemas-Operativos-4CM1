// Ayala Fuentes Sunem Gizeht
// Campos Zeron Salvador

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

#define SEM_HIJO 0
#define SEM_PADRE 1



void procesoHijo(int idHijo) {
    int numeroUsuario;
  switch (idHijo) {
    case 1:
      // Tarea del proceso hijo 1: Calcular la suma de 1 a 100
      printf("Soy el proceso hijo %d. Calculo la suma de 1 a 100.\n", idHijo);
      int suma = 0;
      for (int i = 1; i <= 100; i++) {
        suma += i;
      }
      printf("La suma de 1 a 100 es: %d\n", suma);
      break;

    case 2:
      // Tarea del proceso hijo 2: Calcular el factorial de 5
      printf("Soy el proceso hijo %d. Calculo el factorial de 5.\n", idHijo);
      int factorial = 1;
      for (int i = 5; i > 0; i--) {
        factorial *= i;
      }
      printf("El factorial de 5 es: %d\n", factorial);
      break;

    case 3:
      // Tarea del proceso hijo 3: Imprimir un mensaje cada segundo durante 5 segundos
      printf("Soy el proceso hijo %d. Imprimo un mensaje cada segundo durante 5 segundos.\n", idHijo);
      for (int i = 0; i < 5; i++) {
        printf("Mensaje %d\n", i + 1);
        sleep(1);
      }
      break;

    case 4:
      // Tarea del proceso hijo 4: Buscar el número primo más grande menor que 100
      printf("Soy el proceso hijo %d. Busco el número primo más grande menor que 100.\n", idHijo);
      int primoMayor = 2;
      for (int i = 3; i < 100; i += 2) {
        int esPrimo = 1;
        for (int j = 3; j * j <= i; j += 2) {
          if (i % j == 0) {
            esPrimo = 0;
            break;
          }
        }
        if (esPrimo) {
          primoMayor = i;
        }
      }
      printf("El número primo más grande menor que 100 es: %d\n", primoMayor);
      break;

    case 5:
      // Tarea del proceso hijo 5: Verificar si un número es par o impar (ingresado por el usuario)
      printf("Soy el proceso hijo %d. Verifico si un número es par o impar.\n", idHijo);
      printf("Ingrese un número: ");
      scanf("%d", &numeroUsuario);

      if (numeroUsuario % 2 == 0) {
        printf("%d es un número par.\n", numeroUsuario);
      } else {
        printf("%d es un número impar.\n", numeroUsuario);
      }
      break;

    case 6:
      // Tarea del proceso hijo 6: Elevar un número a una potencia (ingresados por el usuario)
      printf("Soy el proceso hijo %d. Elevo un número a una potencia.\n", idHijo);
      int base, exponente;
      printf("Ingrese la base: ");
      scanf("%d", &base);
      printf("Ingrese el exponente: ");
      scanf("%d", &exponente);

      int potencia = 1;
      for (int i = 0; i < exponente; i++) {
        potencia *= base;
      }
      printf("%d elevado a la potencia %d es: %d\n", base, exponente, potencia);
      break;

    case 7:
      // Tarea del proceso hijo 7: Calcular el valor absoluto de un número (ingresado por el usuario)
      printf("Soy el proceso hijo %d. Calculo el valor absoluto de un número.\n", idHijo);
      printf("Ingrese un número: ");
      scanf("%d", &numeroUsuario);

      int valorAbsoluto;
      if (numeroUsuario >= 0) {
        valorAbsoluto = numeroUsuario;
      } else {
        valorAbsoluto = -numeroUsuario;
      }
      printf("El valor absoluto de %d es: %d\n", numeroUsuario, valorAbsoluto);
      break;

    case 8:
      // Tarea del proceso hijo 8: Convertir una temperatura de Celsius a Fahrenheit (ingresada por el usuario)
      printf("Soy el proceso hijo %d. Convierto una temperatura de Celsius a Fahrenheit.\n", idHijo);
      float temperaturaCelsius;
      printf("Ingrese la temperatura en Celsius: ");
      scanf("%f", &temperaturaCelsius);

      float temperaturaFahrenheit = (temperaturaCelsius * 9.0 / 5.0) + 32.0;
      printf("%.2f grados Celsius equivalen a %.2f grados Fahrenheit.\n", temperaturaCelsius, temperaturaFahrenheit);
      break;

    case 9:
      // Tarea del proceso hijo 9: Calcular el área y perímetro de un cuadrado (ingresados por el usuario)
      printf("Soy el proceso hijo %d. Calculo el área y perímetro de un cuadrado.\n", idHijo);
      float ladoCuadrado;
      printf("Ingrese el lado del cuadrado: ");
      scanf("%f", &ladoCuadrado);

      float areaCuadrado = ladoCuadrado * ladoCuadrado;
      float perimetroCuadrado = 4.0 * ladoCuadrado;
      printf("El área del cuadrado es: %.2f unidades cuadradas.\n", areaCuadrado);
      printf("El perímetro del cuadrado es: %.2f unidades.\n", perimetroCuadrado);
      break;

    case 10:
      // Tarea del proceso hijo 10: Jugar un juego de adivinanzas con el usuario
      printf("Soy el proceso hijo %d. Juego un juego de adivinanzas contigo.\n", idHijo);
      int numeroAleatorio = rand() % 100 + 1; // Generar un número aleatorio entre 1 y 100

      printf("Adivina un número entre 1 y 100: ");
      scanf("%d", &numeroUsuario);

      int intentos = 0;
      while (numeroUsuario != numeroAleatorio && intentos < 5) {
        if (numeroUsuario < numeroAleatorio) {
          printf("Tu número es demasiado bajo. Intenta de nuevo.\n");
        } else {
          printf("Tu número es demasiado alto. Intenta de nuevo.\n");
        }

        intentos++;
        printf("Adivina un número (te quedan %d intentos): ", 5 - intentos);
        scanf("%d", &numeroUsuario);
      }

      if (numeroUsuario == numeroAleatorio) {
        printf("¡Felicidades! Adivinaste el número en %d intentos.\n", intentos);
      } else {
        printf("Lo siento, te quedaste sin intentos. El número era %d.\n", numeroAleatorio);
      }
      break;

    default:
      printf("Soy el proceso hijo %d. No tengo una tarea específica.\n", idHijo);
  }
}

int main(int argc, char const *argv[]) {
  int i=10, semid, pid;
  struct sembuf operacion;
  key_t llave;

  /*Petición de un identificador con dos semáforos*/
  llave = ftok (argv[0], 'K');
  if ((semid =semget (llave, 2, IPC_CREAT | 0600)) == -1){
    perror ("semget");
    exit (-1);
  }

  /*Inicialización de dos semáforos*/

  /*Cerramos el semáforo del proceso hijo*/
  semctl (semid, SEM_HIJO,SETVAL,0);

  /*Abrimos el semáforo del proceso padre*/
  semctl (semid,SEM_PADRE,SETVAL,1);

  /*Creación del proceso hijo*/
  if ((pid=fork()) == -1){
    perror ("fork");
    exit (-1);
  } else if (pid ==0){ //Código del proceso hijo
    while (i) {
      /* Cerramos el semáforo del proceso hijo */
      operacion.sem_num = SEM_HIJO;
      operacion.sem_op = -1; //Operación P
      operacion.sem_flg = 0;
      semop (semid, &operacion, 1);
      procesoHijo(i);
      i--;
      printf("\n");
      /*Abrimos semáforo del proceso padre*/
      operacion.sem_num =SEM_PADRE;
      operacion.sem_op =1;
      semop (semid, &operacion,1);
    }
    /*Borrado del semáforo*/
    semctl (semid,0, IPC_RMID,0);
  }else { /*Código del proceso padre*/
    operacion.sem_flg =0;
    while (i) {
      /* cerramos el semáforo del proceso padre */
      operacion.sem_num =SEM_PADRE;
      operacion.sem_op = -1;
      semop (semid, &operacion, 1);
      printf("Proceso Padre: %d\n", i--);
      /* Abrimos el semáforo del proceso hijo */
      operacion.sem_num = SEM_HIJO;
      operacion.sem_op = 1; //Operación v
      semop (semid, &operacion, 1);
    }
    /*Borramos el semáforo*/
    semctl (semid,0,IPC_RMID,0);
  }
  return 0;
}
