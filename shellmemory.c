#include <stdio.h>
#include <stdlib.h>
#include "shellmemory.h"

struct NODE * shellMemory [1000] ;

int length = 0;

int initializeMemory(){
    for (int i =0; i< 1000; i++){
        shellMemory[i] = NULL;
    }
    return 1;
}

unsigned long hashCode(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    // printf("hash code is %d\n", hash);
    if(hash < 0){
        return -1 * hash;
    }
    return hash;
}

int insert(char * variable, char * value){
    // printf("Var %s Val %s \n",variable, value);
    int errorCode = 0;

    if(length >= 1000){
        printf("Shell memory full");
        return 0;
    }

    int index = hashCode(variable) %1000;
    // printf("index is %d",index);
    if( shellMemory[index] == NULL){
        printf("Hit empty\n");
        struct NODE * newNode = (struct NODE *)malloc (sizeof(struct NODE));
        newNode -> var = strdup (variable);
        newNode -> val = strdup (value);
        shellMemory[index] = newNode;
        length++;
        // printf("Var %s Val %s is inserted\n",variable, value);
    }
    else {
        struct NODE * node = shellMemory[index];

        while( node != NULL){

            if( strcmp(variable, (node  -> var)) ==0){
                node -> val = strdup (value);
                return 1;
            }
            index  = (++index)% 1000;
            node = shellMemory[index];
            // printf("Var %s Val %s has been replaced\n",variable, value);
        }
        
        struct NODE * newNode = (struct NODE *)malloc (sizeof(struct NODE));
        newNode -> var = strdup (variable);
        newNode -> val = strdup (value);
        shellMemory[index] = newNode;
        length++;
        // printf("Var %s Val %s is inserted\n",variable, value);    
        
    }

    // printf("Finished\n");
    return 1;

}

char* get (char* var){
    char * result = NULL;
    int index =  hashCode(var) % 1000;
    
    if(shellMemory[index] != NULL) {
        printf("Hit\n");
        struct NODE * node = shellMemory[index];
        while( node != NULL){
            // printf("Var is %s, current is %s\n",var, node->var);
            if(strcmp(var, (node -> var) ) == 0){
                printf("Found it\n");
                result = strdup (node -> val);
                break;
            }
            index  = (++index)% 1000;
            node = shellMemory[index];
        }
    }
    return result;
}


