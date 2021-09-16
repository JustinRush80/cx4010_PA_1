// random assigments 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"



void scenario1(int capacity, int max_floors, struct Node *lists, int seed) {
    srand ( seed );

    //Randomly generates passenger number 
    int number_passenger = (rand() % capacity)+1;
    struct Node* head = NULL;

    for(int i = 0; i < number_passenger; i++) {
        //Randomly generates floor values and adds to list.
        append(&head, (rand() % max_floors)+1);
    }
    *lists = *head;
    

}

void scenario2(int capacity, int max_floors, struct Node *lists[]) {
    srand ( time(NULL) );

    //Randomly generates passenger number 
    int number_passenger = (rand() % capacity)+1;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int listNum = 0;
    for(int i = 0; i < number_passenger; i++) {
        //Randomly generates floor values and adds to list.
        listNum = rand()%2+1;
        if (listNum == 1) {
            append(&head1, (rand() % max_floors)+1);
        } 
        else {
            append(&head2, (rand() % max_floors)+1);
        }
        
    }
    lists[0] = head1;
    lists[1] = head2;
}

void scenario3(int capacity, int max_floors, int maxFloor1, struct Node *lists[]) {
    srand ( time(NULL) );

    //Randomly generates passenger number 
    int number_passenger = (rand() % capacity)+1;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int newFloor; 
    for(int i = 0; i < number_passenger; i++) {
        //Randomly generates floor values and adds to list.
        newFloor = (rand() % max_floors)+1;
        if (newFloor <= maxFloor1) {
            append(&head1, newFloor);
        } else {
            append(&head2, newFloor);
        }
        
    }

    lists[0] = head1;
    lists[1] = head2;
}

void append(struct Node** head_ref, int new_floor) {
    // Allocate memory for new node and initialize its floor value
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->floor  = new_floor;
    
    
    // Check to see if the head reference is a Null
    // If it is, assign the new node to the head and return
    if (*head_ref == NULL)
    {
        new_node->next = NULL;
       *head_ref = new_node;
       return;
    }

    // Check to see if the floor value of the head is greater than the new one
    // If it is, insert the new node before the original head
    if (((*head_ref) -> floor) > new_floor) {
        new_node ->next = *head_ref; // Gives the new_node the original head as its next value
        *head_ref = new_node; // Reassigns the head value to be the new_node

    //If the head floor value is less than the new one, check with rest of the list
    } else {
        struct Node *previous = *head_ref;  
        struct Node *current = previous ->next;
        
        //Loop through the list while checking for NULL or for a node with 
        //floor value less than the new floor value
        while ((current!=NULL) && (current-> floor < new_floor)) {
            previous = current;
            current = current->next;
        }

        //update the next values of the new node.
        new_node->next = current;
        previous->next = new_node;
        return; 
    }
}

void iterateList(struct Node *node) {
//loop through linked list and print the floor values
  while (node != NULL)
  {
     printf(" %d ", node->floor);
     node = node->next;
  }
}
