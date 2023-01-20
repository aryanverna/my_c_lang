#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// #include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
// #include <dirent.h>

void separate();
void search();
char cmd[80], token1[20], token2[20], token3[20], token4[20], ch;
int n, fp;
pid_t pid;

void separate()
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
        printf("\nMySHell $");
        fgets(cmd, 80, stdin);
        separate();
        if (strcmp(token1, "exit") == 0)
            exit(0);
        pid = fork();
        if (pid == -1)
            printf("\n Child Process Not Created ");
        else if (pid == 0)
        {
            if (strcmp(token1, "search") == 0)
                search();
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
            wait(NULL);
    }
    return 0;
}

void search()
{
    char s[80];
    int i = 0, cnt = 0, lc = 1;
    fp = open(token3, O_RDONLY);
    if (fp == -1)
    {
        printf("\nfile not found");
        return;
    }
    while (read(fp, &ch, 1))
    {
        if (ch == '\n')
            lc++;
        if (ch == '\n' || ch == '\t' || ch == ' ')
        {
            s[i] = '\0';
            i = 0;
            if (strstr(s, token4))
            {
                if (strcmp(token2, "f") == 0)
                {
                    printf("pattern \"%s\" found in \"%s\" at line no :%d\n", token4, s, lc);
                    break;
                }

                if (strcmp(token2, "c") == 0)
                {
                    cnt++;
                    printf("\nTotal occurences of given pattern=%d", cnt);
                }
                if (strcmp(token2, "a") == 0)
                {
                    printf("pattern \"%s\" found in \"%s\" at line no :%d\n", token4, s, lc);
                }
            }
        }
        else
        {
            s[i] = ch;
            i++;
        }
    }
}