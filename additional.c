// random assigments 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"



//Creates linked list of random size < capacity with floor numbers
//  < than max_floors, returns the head of this list
struct Node *generatePassengers(int capacity, int max_floors) {
    srand ( time(NULL) );

    //Randomly generates passenger number 
    int number_passenger = (rand() % capacity)+1;
    struct Node* head = NULL;

    for(int i = 0; i < number_passenger; i++) {
        //Randomly generates floor values and adds to list.
        append(&head, (rand() % max_floors)+1);
    }
    return head;
}

//Creates new node wtih new_floor value and adds to head_ref
void append(struct Node** head_ref, int new_floor)
{
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


//Moves through list at given node and prints floor values
void printList(struct Node *node)
{
//loop through linked list and print the floor values
  while (node != NULL)
  {
     printf(" %d\n ", node->floor);
     node = node->next;
  }
}
