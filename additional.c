// random assigments 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int  floor;
    struct Node* next;
};

//Creates new node wtih new_floor value and adds to head_ref
void append(struct Node** head_ref, int new_floor);
//Moves through list at given node and prints floor values
void printList(struct Node *node);
//Creates linked list of random size < capacity with floor numbers
//  < than max_floors, returns the head of this list
void scenario1(int capacity, int max_floors, struct Node *lists);
void scenario2(int capacity, int max_floors, struct Node *lists[]);
void scenario3(int capacity, int max_floors, int maxFloor1, struct Node *lists[]);


void main(){
    //Initialize a node to hold the head value
    struct Node* sc1;
    //Call the function and create the head to the linked list

    printf("Scenario 1 Values:\n");
    scenario1(18,20, sc1);
    //Check the values of the list
    printList(sc1);

    printf("\nScenario 2 Values:\n");
    struct Node* sc2[2];
    scenario2(18,20, sc2);
    printList(sc2[0]);
    printf("\n");
    printList(sc2[1]);

    printf("\nScenario 3 Values:\n");
    struct Node* sc3[2];
    scenario3(18,20, 10,sc3);
    printList(sc3[0]);
    printf("\n");
    printList(sc3[1]);

}

void scenario1(int capacity, int max_floors, struct Node *lists) {
    srand ( time(NULL) );

    //Randomly generates passenger number 
    int number_passenger = (rand() % capacity)+1;
    struct Node* head = NULL;

    for(int i = 0; i < number_passenger; i++) {
        //Randomly generates floor values and adds to list.
        append(&head, (rand() % max_floors)+1);
    }
    *lists = *head;
    //return head;

}

void scenario2(int capacity, int max_floors, struct Node *lists[]) {
    srand ( time(NULL) );

    //Randomly generates passenger number 
    int number_passenger = (rand() % capacity)+1;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int listNum;
    for(int i = 0; i < number_passenger; i++) {
        //Randomly generates floor values and adds to list.
        listNum = rand()%2+1;
        if (listNum == 1) {
            append(&head1, (rand() % max_floors)+1);
        } else {
            append(&head2, (rand() % max_floors)+1);
        }
        
    }
    //printList(head1);
    //printf("\n");
    //printList(head2);
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

void printList(struct Node *node) {
//loop through linked list and print the floor values
  while (node != NULL)
  {
     printf(" %d ", node->floor);
     node = node->next;
  }
}
