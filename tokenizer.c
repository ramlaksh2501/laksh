#include<stddef.h>
extern char** tokenize(char *input){
	char *copy=malloc(sizeof(char)*strlen(input)+1);
	strcpy(copy,input);
	char* tok=strtok(input," ");
	int tok_count=0;
	while(tok){
		tok_count++;
		tok=strtok(NULL," ");
		}
	char **tokens=(char**)malloc(sizeof(char*)*tok_count+1);
	tok=strtok(copy," ");
	int i=0;
	while(tok!=NULL){
		tokens[i]=(char*)malloc(sizeof(char)*strlen(tok)+1);
		strcpy(tokens[i],tok);
		tok=strtok(NULL," ");
		i++;
		}
		tokens[i]=malloc(sizeof(char));
		tokens[i][0]=(char)NULL;
		free(copy);
		return (char**)tokens;


}

