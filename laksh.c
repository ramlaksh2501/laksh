#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include"tokenize.h"


#define MAX_INPUT 1000
#define MAX_PATH 1000

int main(int argv, char ** argc){
	int i=0;
	while(1){
	printf(">");
	char input[MAX_INPUT];
	fgets(input,MAX_INPUT,stdin);
	input[strcspn(input,"\n")]=0;
	if(strcmp(input,"exit")==0) return 0;
	char **token=tokenize(input);
	if(strcmp(token[0],"cd")==0 && token[2]==NULL){

		if(chdir(token[1])!=0){
			printf("no such path\n");
		}
		else{
		   char *buffer=(char*)malloc(sizeof(char)*MAX_PATH);
		   if(getcwd(buffer,MAX_PATH)!=NULL){
		   printf("switched to: %s\n",buffer);
		   }
		   free(buffer);
		}
		
		}
  	int id=fork();
	if(id==0){
		if(strcmp(token[0],"cd")==0 && token[2]==NULL){
		return 0;
		}
		if(token==ERR_ENDQOT){
			printf("Error: no end quotes\n");
			return 0;
			}
		if(execvp(token[0],token)<0){
			printf("No such cmd as \"%s\"\n",token[0]);
			return 0;
			}
	}
	wait(NULL);
	}
	return 0;}
