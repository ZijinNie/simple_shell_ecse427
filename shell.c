#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"

int parse(char* userInput) {
	char tmp[200];
	int a, b;
	char * words[100] ;

	for(int i = 0; i< 100; i++){
		words[i] = (char*) calloc(1, sizeof(char*));
	}

	int w = 0;
	for(a = 0; userInput[a] == ' '&& a <1000; a++);

	while(userInput[a] != '\0' && userInput[a]!= '\n' && a<1000){
		for (b = 0; userInput[a]!= '\0' && (userInput[a] != ' ') && userInput[a]!= '\n' && a < 1000; a++, b++){
			tmp[b] = userInput[a];
		}
		tmp[b] = '\0';
		words[w] = strdup(tmp);

		if(userInput[a]== '\0' || userInput[a]== '\n') break;

		a++; w++;
	}
	return interpreter(words);
}

int main () {
	printf("Welcome to the Zijin Nie shell!\n");
	printf("Version 1.0 Created Janurary 2020\n");
	
	char prompt[100] = {'$','\0'};
	char userInput[1000];
	int errorCode;
	errorCode = initializeMemory();
	while (1){
		printf("%s ", prompt);
		fgets(userInput, 999, stdin);

		errorCode = parse(userInput);
		if(errorCode == -1) exit(99);
	}
	return 0;
}


