#ifndef COMMANDS_H
#define COMMANDS_H

int exec_command(const char *command, int argc, char *argv[]);
int tig_init();
int tig_delete();

#endif // COMMANDS_H