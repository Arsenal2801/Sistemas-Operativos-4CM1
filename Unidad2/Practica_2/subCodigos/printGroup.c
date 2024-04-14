#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();
    pid_t pgid = getpgid(pid);

    printf("ID del proceso: %d\n", pid);
    printf("ID del grupo del proceso: %d\n", pgid);
    return 0;
}
