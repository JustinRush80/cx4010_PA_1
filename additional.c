#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elevator.h"



void scenario1(int capacity, int max_floors, struct Node *lists ) {
    
    
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


// Pushs a node for each passenger and sorts the node in the linked list
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




//loop through linked list and return the sec of each iteration per secenario
int iterateList(struct Node *node) {
    int floor_cur = 0;
    int floor_prev = 0;
    int sec = 0;
    
    struct Node* current = node;

    while (current != NULL){
        floor_cur = current->floor;
        // printf("%d\n", floor_cur);
        
        // for each unqiue floor it will add 15 secs to the time
        if (floor_cur-floor_prev > 0 ){
            sec += 15;
        }   
        sec += (floor_cur-floor_prev)*3;
        // the prev became the current
        floor_prev = current->floor;
        current = current->next;
  }
//   printf("/////////////////////////////////////////////\n");

  return sec;
}

// prints the average, min, and max times for Secenario 1
void AnalysisSec1(struct Node* scenario){
    
    
    int n = 0;
    int total = 0;
    int maximum = 0;
    int minimum = INT_MAX; //start minimum at a large number 
    double average = 0;
    

    while(n < 1000){

        scenario1(18,20,scenario);
        int sec = iterateList(scenario);
        total += sec;

        if (maximum < sec){
            maximum = sec;  
        }
        else if (minimum > sec){
            minimum = sec;
        }
        n++;
    }
    average = total/n;

    printf("\nFor Scenario 1, minimum is %d , the maximum is %d , the average is %.3f\n ", 
                         minimum , maximum , average);

}

// prints the average, min, and max times for Secenario 2
void AnalysisSec2(struct Node* scenario[]){
    
    int n = 0;
    int total = 0;
    int maximum = 0;
    int minimum = INT_MAX;
    double average = 0;

    while(n < 1000){

        scenario2(18,20,scenario);
        int sec = iterateList(scenario[0]);
        int sec2 = iterateList(scenario[1]);
        total += (sec +sec2);
       
        if (maximum < sec){
            maximum = sec;  
        }
        else if (minimum > sec){
            minimum = sec;
        }
        n++;
    }
    average = total/n;

    printf("For Scenario 2, minimum is %d , the maximum is %d , the average is %.3f\n ", 
                         minimum , maximum , average);
    

}


// prints the average, min, and max times for Secenario 3 and return the maximum 
int AnalysisSec3(int maxFloor1,struct Node* scenario[]){
    
    int n = 0;
    int total = 0;
    int maximum = 0;
    int minimum = INT_MAX;
    double average = 0;

    while(n < 1000){

        scenario3(18,20,maxFloor1,scenario);
        int sec = iterateList(scenario[0]);
        int sec2 = iterateList(scenario[0]);
        total += (sec + sec2);
       
        if (maximum < sec){
            maximum = sec;  
        }
        else if (minimum > sec){
            minimum = sec;
        }
        n++;
    }
    average = total/n;

    printf("For Scenario 3, minimum is %d , the maximum is %d , the average is %.3f\n ", 
                         minimum , maximum , average);

    return maximum;
}



