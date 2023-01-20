#include <stdio.h>
// #include <sys/types.h>
#include <unistd.h>
// #include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
// #include <sys/stat.h>
#include <fcntl.h>

void separate();
void count();
char cmd[80],token1[20],token2[20],token3[20],token4[20],ch;
int n,fp,m,lc,wc,cc;
pid_t pid;
void separate(){
	strcpy(token1,"\0");
	strcpy(token2,"\0");
	strcpy(token3,"\0");
	strcpy(token4,"\0");
	n = sscanf(cmd,"%s%s%s%s",token1,token2,token3,token4);
}

int main(){
	while(1){
		printf("\nMySHell $");
		fgets(cmd,80,stdin);
		separate();
		if(strcmp(token1,"exit")==0)
			exit(0);
		pid = fork();
		if(pid==-1)
			printf("\n Child Process Not Created ");
		else if(pid==0)
		{
			if(strcmp(token1,"count")==0)
				count();
			else
			{
				switch(n){
					case 1: 
						execlp(token1,token1,NULL);
						break;
					case 2: 
						execlp(token1,token1,token2,NULL);
						break;
					case 3: 
						execlp(token1,token1,token2,token3,NULL);
						break;
					case 4: 
						execlp(token1,token1,token2,token3,token4,NULL);
						break;
				}
			}
		}
		else
			wait(NULL);
	}
	return 0;
}

void count(){
	lc = 0;
	wc = 0;
	cc = 0;
	fp = open(token3,O_RDONLY);
	if(fp==-1){
		printf("\nfile %s not opened",token3);
	}
	else{
			while(read(fp,&ch,1))
			{
				if(ch!=' ' && ch != '\t' && ch !='\n'){
					cc++;
				}
				else if(ch == ' ' || ch =='\t'){
					wc++;
				}
				else{
					wc++;
					lc++;
				}
			}
		}
		if(strcmp(token2,"w")==0)
			printf("\n words count is :%d",wc);
		if(strcmp(token2,"l")==0)
				printf("\n line count is:%d ",lc);
		if(strcmp(token2,"c")==0)
					printf("\n Character count is:%d ",cc);
					
				close(fp);
}
