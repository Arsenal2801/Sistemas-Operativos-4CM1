#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid_padre = getppid(); // Obtiene el ID del proceso padre
  printf("ID del proceso padre: %d\n", pid_padre);

  return 0;
}
