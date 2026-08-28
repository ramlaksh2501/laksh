#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argv, char ** argc){
	int i=0;
	while(1){
	int id=fork();
	if(id==0){

	printf(">");
	char input[1000];
	scanf("%s",input);
	printf("%s\n",input);
		execlp(input,NULL);
	}
	wait(NULL);
	printf("job done\n");
	}
	return 0;}
