#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 *
 * Supported commands:
 * - init: creates a repository
 * 
 */

int exec_command(const char *command, int argc, char *argv[]) {

    if (strcmp(command, "init") == 0) {
        return tig_init();
    }

    return 0;
}


int tig_init() {

    // create hidden .tig folder
    if (system("mkdir .tig") == -1) {
        perror("Failed to create tig repository in .tig\n");
        return 1;
    }

    // make hidden
    if (system("attrib +h .tig") == -1) {
        perror("Failed to set .tig folder to hidden\n");
        return 1;
    }
    
}