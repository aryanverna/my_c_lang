#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include<sys/wait.h>
#include <fcntl.h>
#include <string.h>

char cmd[80], token1[20], token2[20], token3[20], token4[20], ch;
int i, n;

pid_t pid;

void separated()
{
    strcpy(token1, "\0");
    strcpy(token2, "\0");
    strcpy(token3, "\0");
    strcpy(token4, "\0");
    n = sscanf(cmd, "%s%s%s%s", token1, token2, token3, token4);
}

int main()
{
    while (1)
    {
        printf("\nMyShell");
        fgets(cmd, 80, stdin);
        separated();
        if (strcmp(token1, "exit") == 0)

            exit(0);

        pid = fork();
        if (pid == -1)
        {
            printf("No Process is Created");
        }
        else if (pid == 0)
        {
            if (strcmp(token1, "count") == 0)
            {
                count();
            }
            else
            {
                switch (n)
                {
                case 1:
                    execlp(token1, token1, NULL);
                    break;
                case 2:
                    execlp(token1, token1, token2, NULL);
                    break;
                case 3:
                    execlp(token1, token1, token2, token3, NULL);
                    break;
                case 4:
                    execlp(token1, token1, token2, token3, token4, NULL);
                    break;
                }
            }
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}

void count()
{
    lc = 0;
    wc = 0;
    cc = 0;
}