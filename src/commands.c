#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "commands.h"


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

    if (strcmp(command, "delete") == 0) {
        return tig_delete();
    }

    return 0;
}


int tig_init() {

    // Create hidden .tig folder
    if (system("mkdir .tig") == -1) {
        perror("Failed to create tig repository in .tig\n");
        return 1;
    }

    // Make hidden
    if (system("attrib +h .tig") == -1) {
        perror("Failed to set .tig folder to hidden\n");
        return 1;
    }

    return 0;
}


int tig_delete() {

    // Check if the .tig folder exists and attempt to delete it
    if (system("attrib -h .tig") == -1) {
        perror("Failed to remove hidden attribute from .tig folder\n");
        return 1;
    }

    if (system("rmdir /S /Q .tig") == -1) {  // `/S` removes all files and subdirectories, `/Q` for quiet mode
        perror("Failed to delete .tig folder\n");
        return 1;
    }

    return 0;

}