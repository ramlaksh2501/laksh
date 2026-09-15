#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include"tokenize.h"


#define MAX_INPUT 1000

int main(int argv, char ** argc){
	int i=0;
	while(1){
	printf(">");
	char input[MAX_INPUT];
	fgets(input,MAX_INPUT,stdin);
	input[strcspn(input,"\n")]=0;
	if(strcmp(input,"exit")==0) return 0;
	int id=fork();
	if(id==0){
		char **token=tokenize(input);
		if(execvp(token[0],token)<0){
			printf("No such cmd as \"%s\"\n",token[0]);
			return 0;
			}
	}
	wait(NULL);
	}
	return 0;}
