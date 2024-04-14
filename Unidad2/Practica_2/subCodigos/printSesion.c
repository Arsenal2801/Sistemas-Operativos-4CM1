#include <stdio.h>
#include <unistd.h> // Incluye la biblioteca que contiene sid_t

int main() {
    pid_t pid = getpid();
    pid_t sid = getsid(pid);

    printf("ID del proceso: %d\n", pid);
    printf("ID de la sesión del proceso: %d\n", sid);

    // Podemos imprimir más información si es necesario, como el ID del proceso líder de la sesión.
    printf("ID del líder de sesión: %d\n", getsid(0));
  return 0;
}
