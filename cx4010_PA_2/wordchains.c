#include <stdio.h>
#include <stdlib.h>
#include "wordchains.h"

#define WORDLIST 500


int main (int argc, char **argList) {
    
    //Read in arguments
    int start,end;
    start = atoi(argList[1]);
    end = atoi(argList[2]);
    
    //Create a map from the input list
    struct mapping string[WORDLIST];  
    CreateMapping("wordlist.txt",string);
    
    //Convert the map and structures into a matrix
    int matrix[WORDLIST][WORDLIST];
    CreateAbJMartix(string,matrix);
    
    //Initialize a path and run the path finding algorithm
    struct Node path = {-1,NULL};
    pathFind(&path, *matrix, end, start);
    
    //Print the results of the path finding.
    if (path.wordIdx == -1) {
        printf("No path available.");
    } else {
        printlList(string,matrix,&path,end);
    }

    return 1;
}
