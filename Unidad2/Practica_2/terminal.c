// Importaciones externas
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// importaciones propias
#include "subCodigos/banner.c"
#include "subCodigos/help.c"


int main(){
    char valor[]="", *path;
    int pid, estado;
    banner();
    help();
    while(1){
        printf("user@pc$ ");
        scanf("%s", &valor);
        printf("\n");
        if (strcmp(valor, "printPpid")==0){
            path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/printPpid";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else if (strcmp(valor, "printPid")==0){
            path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/printPid";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else if (strcmp(valor, "printGroup")==0){
            path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/printGroup";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else if (strcmp(valor, "printSesion")==0){
             path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/printSesion";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else if (strcmp(valor, "printUser")==0){
             path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/printUser";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else if (strcmp(valor, "PrintSerieFibonacci")==0){
             path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/PrintSerieFibonacci";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else if (strcmp(valor, "help")==0){
            path = "/home/arsenal/Desktop/SO/Unidad2/Practica_2/subCodigos/help";
            pid = fork();
            if(pid == 0){
            estado = execl(path, "a", NULL);
            if (estado==-1)
            {
                perror ("Error 1 en la ejecucion");
                _exit(2);
                }
            }
            wait(&estado);
            if(WIFEXITED(estado)){
                printf("Proceso terminado\n");
                printf("\n");
            }
        }
        else {
            printf("Comando desconocido intente de nuevo\n");
        }
    }
    
    return 0;
}