#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include"tokenize.h"
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
	int got_quotes=0;
	char *qoute_tok;
	while(tok!=NULL){
		if(tok[0]=='\"'){
			got_quotes=1;
			if(tok[strlen(tok)-1]=='\"'){
				got_quotes=0;
			}
			else{
				qoute_tok=malloc(sizeof(char)*strlen(tok)+1);
				qoute_tok=strcpy(qoute_tok,tok+1);
				strcat(qoute_tok," ");
				tok=strtok(NULL,"\"");
				if(tok!=NULL){
					qoute_tok=realloc(qoute_tok,sizeof(char)*(strlen(tok)+strlen(qoute_tok)));
					strcat(qoute_tok,tok);
					tokens[i]=(char*)malloc(sizeof(char)*strlen(qoute_tok)+1);
					strcpy(tokens[i],qoute_tok);
					tok=(char*)strtok(NULL," ");
					free(qoute_tok);
					i++;
					continue;
				}
				else{
					return ERR_ENDQOT;
				}


			}
			}
		
		//	if else(got_qoutes && tok[1]!=NULL && (tok[1][strlen(tok[1])-1]!='\"')){
		//		strcat(tok[0],tok[1]);
		//	}
		//	if else(got_qoutes && tok[1]!=NULL && (tok[1][strlen(tok[1])-1]=='\"')){
		//		strcat(tok[0],tok[1]);
		//		got_qoutes=0;
		//	}
		tokens[i]=(char*)malloc(sizeof(char)*strlen(tok)+1);
		strcpy(tokens[i],tok);
		tok=(char*)strtok(NULL," ");
		i++;
		}
		tokens[i]=NULL;
		free(copy);
		return (char**)tokens;


}

