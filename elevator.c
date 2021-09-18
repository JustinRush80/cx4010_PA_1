#include <stdio.h>
#include "elevator.h"
#include <limits.h>


// returns the average, min, and max times for every scenario
int analysis(){
    // Initialize a node to hold the head value
    struct Node sc1 = {-1,NULL};
    

   
    // struct Node first_Node = {-1,NULL};
    // struct Node second_Node = {-1,NULL};

    
    struct Node sc2[2];
    struct Node sc3[2];

    
    // scenario2(18,20, &sc2);
    // scenario3(18,20, 10, &sc3);
    // iterateList(&sc2[0]);
   


   

    int n = 0;
    int total = 0;
    int maximum = 0;
    int minimum = INT_MAX;
    double average = 0;
    


    while(n < 1000){
        
        
       
        scenario1(18,20,&sc1,n);
        scenario2(18,20, &sc2); 
        int sec = iterateList(&sc1);
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
    printf("%d\n",maximum );
    printf("%d\n",minimum );
    printf("%f", average);


    return 0;


}

int main(){
   
    

   
    analysis();
    return 0;

}

