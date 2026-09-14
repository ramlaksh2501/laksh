#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>


#define MAX_INPUT 1000

int main(int argv, char ** argc){
	int i=0;
	while(1){
	printf(">");
	char input[MAX_INPUT];
	scanf("%s",input);
	printf("%s\n",input);
	input[strcspn(input,"\n")]=0;
	char **token=tokenize(input);
	if(strcmp(input,"exit")==0) return 0;
	int id=fork();
	if(id==0){
	   execvp(token[0],token);
	}
	wait(NULL);
	printf("job done\n");
	}
	return 0;}
