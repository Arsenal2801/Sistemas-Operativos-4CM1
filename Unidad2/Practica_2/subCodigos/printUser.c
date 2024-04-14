#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    uid_t uid = getuid();
    gid_t gid = getgid();

    printf("ID del usuario que ejecutó el proceso: %d\n", uid);
    printf("ID del grupo del usuario que ejecutó el proceso: %d\n", gid);
    return 0;
}
