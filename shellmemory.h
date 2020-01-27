#include <stdlib.h>
#include <string.h>

struct NODE {
    char * var;
    char * val;
}head;

int insert(char * variable, char * value);
char* get (char* var);
unsigned long hashCode(char *str);
int initializeMemory();




