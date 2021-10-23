#include <stdio.h>
#include <stdlib.h>
#include "wordchains.h"

#define WORDLIST 500


int main (int argc, char **argList) {
    int start,end;
    start = atoi(argList[1]);
    end = atoi(argList[2]);

    struct mapping string[WORDLIST];  
    CreateMapping("wordlist.txt",string);
    
    int matrix[WORDLIST][WORDLIST];
    CreateAbJMartix(string,matrix);
    struct Node path = {-1,NULL};
    pathFind(&path, *matrix, end, start);
    

    if (path.wordIdx == -1) {
        printf("No path available.");
    } else {
        printlList(string,matrix,&path,end);
    }

    return 1;
}
