#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argv, char ** argc){
	int i=0;
	while(1){
	
	printf(">");
	char input[1000];
	scanf("%s",input);
	printf("%s\n",input);
	input[strcspn(input,"\n")]=0;
	if(strcmp(input,"exit")==0) return 0;
	int id=fork();
	if(id==0){
	   char args[]=" hello.txt";
	   execlp(input,args,(char *)NULL);
	}
	wait(NULL);
	printf("job done\n");
	}
	return 0;}
