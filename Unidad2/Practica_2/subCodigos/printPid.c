#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid(); // Obtiene el ID del proceso actual
  printf("ID del proceso: %d\n", pid);

  return 0;
}
