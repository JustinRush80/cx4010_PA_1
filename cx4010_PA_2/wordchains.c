#include <stdio.h>
#include <stdlib.h>

int numWords = 7;

struct Node
{
    int  wordIdx;
    struct Node* next;
};

void printList(int list[]);
void append(struct Node** head_ref, int nextWord);
void printlList(struct Node *node);
void pathFind(struct Node* path, int* adjMat, int start, int end);

int main (int argc, char **argList) {
    int start,end;
    start = atoi(argList[1]);
    end = atoi(argList[2]);

    int adjMat[7][7] = {{1, 1, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 1, 0, 1}, {1, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 1}};
    //printf("%d,%d",start,end);

    struct Node path = {-1,NULL};
    pathFind(&path, *adjMat, end, start);
    printlList(&path);

    if (path.wordIdx == -1) {
        printf("No path available.");
    }

    return 1;
}

void printList(int list[]) {
    for(int i = 0; i < numWords; i++) {
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

void printlList(struct Node *node) {
//loop through linked list and print the floor values
  while (node != NULL)
  {
     printf(" %d ", node->wordIdx);
     node = node->next;
  }
}

void pathFind(struct Node* path, int* adjMat, int start, int end) {
    path->wordIdx = end;

    int checking[numWords];
    int chSt = 0;
    int chEnd = 0;

    int visited[numWords];

    for(int i = 0; i < numWords; i++) {
        checking[i] = -1;
        visited[i] = -1;
    }

    checking[0] = start;
    visited[start] = 1;
    chEnd = 1;

    int pathFound = 0; 
    int linked = 0;
    
    while ((chEnd-chSt)>0 && pathFound == 0) {
        for(int i = 0; i < numWords; i++) {
            
            linked = *(adjMat+i+checking[chSt]*numWords);
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