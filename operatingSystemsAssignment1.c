#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    // Creating a child process
    pid = fork();
    for (int i = 0; i < 5; i++)
    {
        if (pid < 0)
        {
            // Fork failed
            perror("Fork failed");
            return 1;
        }
        else if (pid == 0)
        {
            // Child process
            printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        }
        else
        {
            // Parent process
            printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        }
    }

    return 0;
}
