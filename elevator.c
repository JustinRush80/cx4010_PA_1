#include <stdio.h>
#include "elevator.h"

int main(){
    
    struct Node* head;  //Initialize a node to hold the head value
    head = generatePassengers(18,20); //Call the function and create the head to the linked list
    printList(head); //Check the values of the list

}


