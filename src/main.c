#include <stdio.h>

// Libraries below are for getpid()
#include <sys/types.h>
#include <unistd.h>

// Library for waitpid()
#include <sys/wait.h>

// Library for exit
#include <stdlib.h>
int main() {
    printf("GridLite starting...\n");

    printf("PID of main process: %d\n", getpid());

    pid_t pid;
    pid = fork();

    if (pid > 0) {
      printf("the parent is running\n");
      int status;
      //waitpid(pid, &status, 0);

      //printf("[END] Child ended with %d\n", status);

    } else if (pid < 0) {
      // child could not be made
    } else if (pid == 0) {
      printf("the child is running\n");

      char *args[] = {"ls", "-l", NULL};
      execvp("ls", args);

      // TODO - There is a problem.
      // It let's me do an extra command.
      // I remember I had this problem last summer but i don't remember why it happened
      // ahora que use waitpid ya no tengo el problema... mmm. idk why.
      perror("execvp failed.");
      exit(1);
    }

    return 0;
}
