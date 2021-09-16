#include <stdio.h>
#include "elevator.h"
#include <unistd.h>


// returns the average, min, and max times for every scenario
int analysis(){
    // Initialize a node to hold the head value
    struct Node sc1 = {-1,NULL};
    

   
    // struct Node first_Node = {-1,NULL};
    // struct Node second_Node = {-1,NULL};

    
    // struct Node sc2[2] = {first_Node,second_Node};
    // struct Node sc3[2] = {first_Node,second_Node};

    
    // scenario2(18,20, &sc2);
    // scenario3(18,20, 10, &sc3);
    // iterateList(&sc2[0]);
   


   

    int n = 0;
    double average = 0;
    double maximum = 0;
    double minimum = 0;

    while(n < 1000){
        
        printf("\nSec 1\n");
        scenario1(18,20,&sc1,n);
        iterateList(&sc1);

        

        n++;

    }
    return 0;

    


}

int main(){
   
    

   
    analysis();
    return 0;

}

