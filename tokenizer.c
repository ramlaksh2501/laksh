#include<stddef.h>
#include<stdlib.h>
#include<string.h>
extern char** tokenize(char *input){
	char *copy=malloc(sizeof(char)*strlen(input)+1);
	strcpy(copy,input);
	char* tok=(char*)strtok(input," ");
	int tok_count=0;
	while(tok){
		tok_count++;
		tok=(char*)strtok(NULL," ");
		}
	char **tokens=(char**)malloc(sizeof(char*)*tok_count+1);
	tok=(char*)strtok(copy," ");
	int i=0;
	while(tok!=NULL){
		tokens[i]=(char*)malloc(sizeof(char)*strlen(tok)+1);
		strcpy(tokens[i],tok);
		tok=(char*)strtok(NULL," ");
		i++;
		}
		tokens[i]=NULL;
		free(copy);
		return (char**)tokens;


}

