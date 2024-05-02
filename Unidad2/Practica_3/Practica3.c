#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX 256

int tuberia_emisor_receptor[2];
int tuberia_receptor_emisor[2];
char mensaje[MAX];
int pid, estado;
struct sigaction capturadorSenial;

static void captura(int s) {
    if (s == SIGINT) {
        printf("Recibí interrupción por teclado, señal: %d\n", s);
        exit(0);
    } else if (s == SIGTERM) {
        printf("Señal de termino, señal: %d\n", s);
        exit(0);
    } else if (s == SIGUSR1) {
        printf("Señal SIGUSR1, señal: %d\n", s);
        printf("Proceso receptor. MENSAJE:%s\n",mensaje);
        printf("Proceso emisor. Introduce el mensaje:\n");
        fgets (mensaje,sizeof (mensaje),stdin);
        write(tuberia_receptor_emisor[1],mensaje,strlen(mensaje)+1);
    }
}

int main(int argc, char const *argv[]) {
    if (pipe (tuberia_emisor_receptor)==-1 || pipe (tuberia_receptor_emisor)==-1 ){
        perror ("pipe");
        exit (-1);
    }
    if(signal(SIGTERM, captura) == SIG_ERR || signal(SIGUSR1, captura) == SIG_ERR || signal(SIGINT, captura) == SIG_ERR){
        perror ("signal");
        exit (-1);
    }
    if ((pid=fork())==-1){
        perror ("fork");
        exit (-1);
    } else if (pid==0){ 
        while (read(tuberia_emisor_receptor[0],mensaje,MAX) > 0 ){
            if(strcmp(mensaje, "FIN\n")==0){
                kill(getpid(), SIGTERM);
                break;
            }
            kill(getpid(), SIGUSR1);
        }
        close (tuberia_emisor_receptor[0]);
        close (tuberia_emisor_receptor[1]);
        close (tuberia_receptor_emisor[1]);
        close (tuberia_receptor_emisor[0]);
        exit (0);
    }else { 
        while (printf("Proceso emisor. Introduce el mensaje:\n")!=0 &&
            fgets (mensaje,sizeof (mensaje),stdin)!=NULL &&
            write(tuberia_emisor_receptor[1],mensaje,strlen(mensaje)+1)>0 &&
            strcmp(mensaje,"FIN\n")!=0 &&
            read(tuberia_receptor_emisor[0],mensaje,MAX)>0 && 
            mensaje != "FIN\n" && 
            printf("Proceso receptor. MENSAJE:%s\n",mensaje)){
                if(strcmp(mensaje, "FIN\n")==0){
                    kill(getpid(), SIGTERM);
                    break;
                }
        }
            
        close (tuberia_emisor_receptor[1]);
        close (tuberia_emisor_receptor[0]);
        close (tuberia_receptor_emisor[1]);
        close (tuberia_receptor_emisor[0]);
        wait(NULL);
        exit (0);
    }
}