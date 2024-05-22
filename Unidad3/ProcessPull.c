#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

// Elaboraron:
//    - Ayala Fuentes Sunem Gizeht
//    - Campos Zeron Salvador

#define MAX_PROCESOS 10 

// Estructura para almacenar información de los procesos
typedef struct {
    pid_t pid;
    int activo;
} Process;

// Función para realizar la operación P en un semáforo específico
void operacion_P(int semid, int sem_num) {
    struct sembuf operacion;
    operacion.sem_num = sem_num;
    operacion.sem_op = -1; 
    operacion.sem_flg = 0;
    semop(semid, &operacion, 1);
}

// Función para realizar la operación V en un semáforo específico
void operacion_V(int semid, int sem_num) {
    struct sembuf operacion;
    operacion.sem_num = sem_num;
    operacion.sem_op = 1;
    operacion.sem_flg = 0;
    semop(semid, &operacion, 1);
}

void tabla_multiplicar(int num) {
    printf("\n[Proceso %d]: ",num);
    printf("Caluclando tabla del %d\n", num);
    for (int i = 1; i <= 10; ++i) {
        printf("\t[Proceso %d]: %d x %d = %d\n", num, num, i, num * i);
    }
}

void manejador(int sig) {}

int main(int argc, char const *argv[]) {
    int semid;
    key_t key;
    Process procesos[MAX_PROCESOS] = {{0}};
    int num_procesos = 0;
    int opt;

    key = ftok(argv[0], 'K');
    if ((semid = semget(key, MAX_PROCESOS, IPC_CREAT | 0600)) == -1) { 
        perror("semget");
        exit(-1);
    }

    for (int j = 0; j < MAX_PROCESOS; ++j) {
        semctl(semid, j, SETVAL, 0); 
    }

    signal(SIGUSR1, manejador);

    while (1) {
        printf("\nMenú de opciones:\n");
        printf("\t1. Crear nuevo proceso\n");
        printf("\t2. Eliminar un proceso\n");
        printf("\t3. Imprimir el número de procesos activos\n");
        printf("\t4. Ejecutar un proceso\n");
        printf("\t5. Salir\n\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                if (num_procesos < MAX_PROCESOS) {
                    
                    int indice_inactivo = -1;
                    for (int i = 0; i < MAX_PROCESOS; ++i) {
                        if (!procesos[i].activo) {
                            indice_inactivo = i;
                            break;
                        }
                    }
                    if (indice_inactivo != -1) {
                        pid_t pid = fork();
                        if (pid == 0) { 
                            signal(SIGUSR1, manejador);
                            while (1) {
                                pause();
                                tabla_multiplicar(indice_inactivo + 1);
                                kill(getppid(), SIGUSR1);
                            }
                        } else if (pid > 0) {
                            procesos[indice_inactivo].pid = pid;
                            procesos[indice_inactivo].activo = 1;
                            printf("Proceso %d creado con PID %d\n", indice_inactivo + 1, pid);
                            num_procesos++;
                        } else {
                            perror("fork");
                        }
                    } else {
                        printf("No se pueden crear más procesos\n");
                    }
                } else {
                    printf("No se pueden crear más procesos\n");
                }
                break;
            case 2:
                printf("Ingrese el número del proceso a eliminar: ");
                int eliminar;
                scanf("%d", &eliminar);
                if (eliminar > 0 && eliminar <= MAX_PROCESOS && procesos[eliminar - 1].activo) {
                    kill(procesos[eliminar - 1].pid, SIGTERM);
                    procesos[eliminar - 1].activo = 0;
                    printf("Proceso %d eliminado\n", eliminar);
                    num_procesos--;
                } else {
                    printf("Número de proceso inválido o proceso no activo\n");
                }
                break;
            case 3:
                printf("Número de procesos activos: ");
                int activos = 0;
                for (int i = 0; i < MAX_PROCESOS; ++i) {
                    if (procesos[i].activo) {
                        activos++;
                    }
                }
                printf("%d\n", activos);
                break;
            case 4:
                printf("Ingrese el número del proceso a ejecutar: ");
                int ejecutar;
                scanf("%d", &ejecutar);
                if (ejecutar > 0 && ejecutar <= MAX_PROCESOS && procesos[ejecutar - 1].activo) {
                    kill(procesos[ejecutar - 1].pid, SIGUSR1); 
                    pause();
                } else {
                    printf("Número de proceso inválido o proceso no activo\n");
                }
                break;
            case 5:
                
                for (int i = 0; i < MAX_PROCESOS; ++i) {
                    if (procesos[i].activo) {
                        kill(procesos[i].pid, SIGTERM);
                    }
                }
                
                semctl(semid, 0, IPC_RMID, 0);
		printf("\nSaliendo...");
                exit(0);
            default:
                printf("Opción no válida\n");
                break;
        }
    }

    return 0;
}
