#include <stdio.h>
// #include <sys/types.h>
#include <unistd.h>
// #include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
// #include <sys/stat.h>
#include <fcntl.h>

void separate();
void typeline();
char cmd[80],token1[20],token2[20],token3[20],token4[20],ch;
int n,fp,m,lc;
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
			if(strcmp(token1,"typeline")==0)
				typeline();
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

void typeline(){
	lc = 0;
	fp = open(token3,O_RDONLY);
	while(read(fp,&ch,1)){
		if(ch=='\n')
		lc++;
	}
	lc = lc + 1;
	lseek(fp,0,SEEK_SET);
	if(strcmp(token2,"a")==0){
		while(read(fp,&ch,1)){
			printf("%c",ch);
			}
		}
	else{
			n = atoi(token2);
			if(n>0){
				while(read(fp,&ch,1)){
					printf("%c",ch);
					if(ch=='\n')
					n--;
				if(n==0)
					break;
				}
			}
			else{
				n = n-n;
				m =lc-n;
				while(read(fp,&ch,1)){
					if(ch=='\n')
					m--;
				if(m==0)
					break;
				}
				while(read(fp,&ch,1)){
					printf("%c",ch);
				}
			}	
		}
		close(fp);
	}
