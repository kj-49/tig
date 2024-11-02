#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: tig <command>\n");
        return 1;
    }

    const char *command = argv[1];

    return exec_command(command, argc - 1, argv + 1);
}