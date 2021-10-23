#include <stdio.h>
#include <stdlib.h>
#include "wordchains.h"




void printList(int list[]) {
    for(int i = 0; i < WORDLIST; i++) {
        printf("%d ",list[i]);
    }
}

void append(struct Node** head_ref, int nextWord) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->wordIdx  = nextWord;

    if (*head_ref == NULL)
    {
        new_node->next = NULL;
       *head_ref = new_node;
       return;
    }

    struct Node *previous = *head_ref;  
    struct Node *current = previous ->next;
    
    //Loop through the list while checking for NULL or for a node with 
    //floor value less than the new floor value
    while (current!=NULL) {
        previous = current;
        current = current->next;
    }

    new_node->next = current;
    previous->next = new_node;
    return;
}

void printlList(struct mapping string[WORDLIST], int matrix[WORDLIST][WORDLIST], struct Node *node, int end) {
    //loop through linked list and print the floor values
    int wordIdx = -1;
    while (node != NULL)
    {
        wordIdx = node->wordIdx;

        if (wordIdx == end) {
            printf("%s",string[wordIdx].word);  
        } else {
            printf("%s -> ",string[wordIdx].word);
        }

        node = node->next;
    }

}

void pathFind(struct Node* path, int* adjMat, int start, int end) {
    path->wordIdx = end;
    //Initialize two matrixes which will contain information about:
    //  checking: a queue which has information about which nodes need to be checked next
    //  visited: a list which has information about whether a given node has been visited and what its parent node
    int checking[WORDLIST];
    int chSt = 0;
    int chEnd = 0;

    int visited[WORDLIST];

    for(int i = 0; i < WORDLIST; i++) {
        checking[i] = -1;
        visited[i] = -1;
    }

    checking[0] = start;
    visited[start] = 1;
    chEnd = 1;

    int pathFound = 0; 
    int linked = 0;
    
    //While there are items in the queue and the end hasn't been reached, search nodes via breadth first search
    while ((chEnd-chSt)>0 && pathFound == 0) {
        for(int i = 0; i < WORDLIST; i++) {
            
            linked = *(adjMat+i+checking[chSt]*WORDLIST);
            if (linked == 1 && visited[i] == -1 && !pathFound) {
                visited[i] = checking[chSt];
                
                checking[chEnd] = i; 
                chEnd += 1;
                if (i == end) {
                    pathFound = 1;
                }
            }
        }
        chSt += 1;
    }
    
    //Backsolves to find the path from the visited list, which contains parent node information.
    //If no path was found, just returns a linked list of length 1 with value -1
    //Otherwise, updates the given path pointer with the list.
    if (pathFound == 0) {
        path->wordIdx = -1;
    } else {
        int currentWord = end;
    
        while(currentWord != start) {
            currentWord = visited[currentWord];
            append(&path, currentWord);
        }
    }

}

void CreateMapping(char* filename, struct mapping string[WORDLIST])
{
    FILE *fp;
    fp = fopen(filename,"r");
    int i = 0;
    
    while(fscanf(fp, "%s", string[i].word)!=EOF) // store the string to the struct mapping
    { 
        string[i].key = i; // set the key to the string to be it's index 
        i ++;  
    }  
    fclose(fp);

}

int CompareString(char* string1, char* string2)
{   int count = 0;
    for(int letter = 0 ; letter<5; letter++)
    {   
        if (string1[letter] != string2[letter]){
            count+=1;
        }

        if (count > 1){
            return 100;
        }
    }
    
    return count; 
}

void CreateAbJMartix (struct mapping string[WORDLIST], int matrix[WORDLIST][WORDLIST])
{   
    
    
    for(int i = 0; i < WORDLIST ; i++)
    {  
        for(int j = 0; j<WORDLIST; j++)
        {
            int count = CompareString(string[i].word,string[j].word);
            if (count == 1){
                matrix[i][j] = 1; 
            }
            else 
            {
                matrix[i][j] = 0;
            }
               

        }
        
    }


}

