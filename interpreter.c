#include <stdio.h>
#include <unistd.h>
#include "shellmemory.h"
#include "shell.h"


int help(){
	printf("The available commands are \n   help\n   quit\n   set VAR STRING\n   print VAR\n   run SCRIPT.txt\n");
	return 0;
}

int quit(){
	printf("Bye!");
	sleep(3);
	return -1;
}

int set(char *words[]){
	printf("setting\n");
	char* var = strdup(words[1]);
	char* val = strdup(words[2]);
	return insert(var, val);
}

int print(char *words[]){
	char *var = strdup(words[1]);
	char * val = get(var);
	if(!val){
		printf("Variable does not exist\n");
		return 0;
	}
	printf("%s", val);
	return 0;
}

int run(char *words[]){
	int errorCode;
	char * fileName = strdup(words[1]);
	FILE * file = fopen(fileName, "r");
	if(!file){
		printf("Script not found");
		errorCode = 0;
		return errorCode;
	}
	char line[1000] ;

	while(fgets(line, 999, file)){
		errorCode = parse(line);
	}
	
	return errorCode;	
}

int interpreter(char *words[]){
	int errCode = 1;
	
	if(strcmp(words[0],"help") == 0) 	{
		printf("interpreted words is help\n");
		errCode = help();
	}
	else if (strcmp(words[0], "quit\n")==0) {
		errCode = quit();
	}
	else if (strcmp(words[0], "set")==0) 	{
		printf("interpreted word is set\n");
		errCode = set(words);
	}
	else if (strcmp(words[0], "print")==0) {
		printf("interpreted word is print\n");
		errCode = print(words);
	}
	else if (strcmp(words[0], "run")==0) 	{
		printf("interpreted word is run\n");
		errCode = run(words);
	}
	else {
		errCode = 0;
		printf("Unknown command\n");
	}
	return errCode;
}