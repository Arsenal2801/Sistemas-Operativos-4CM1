#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void captura(int s) {
    if (s == SIGALRM) {
        printf("Pasaron 2 segundos, señal: %d\n", s);
    } else if (s == SIGFPE) {
        printf("Error punto flotante, señal: %d\n", s);
    } else if (s == SIGINT) {
        printf("Recibí interrupción por teclado, señal: %d\n", s);
        exit(0);
    }
}

int main() {
    int pid, estado;
    struct sigaction capturadorSenial;

    memset(&capturadorSenial, 0, sizeof(capturadorSenial));
    capturadorSenial.sa_handler = captura;

    sigaction(SIGALRM, &capturadorSenial, NULL);
    sigaction(SIGFPE, &capturadorSenial, NULL);
    sigaction(SIGINT, &capturadorSenial, NULL);


    while(1){
        printf("\n");
        pid = fork();  
        if (pid == 0) {
            sleep(2);
            kill(getppid(), SIGFPE);
            kill(getppid(), SIGALRM);
            printf("Envié dos señales \n");
            _exit(255);
        } 
        printf("Id del proceso receptor: %d\n", getpid());
        printf("Esperando...\n");
        pause();
        pid = wait(&estado);
        if (WIFEXITED(estado)) {
            printf("Terminó el hijo %d con estado %d\n", pid, WEXITSTATUS(estado));
        }
    }
    
}

