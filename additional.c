// random assigments 

#include <stdio.h>
#include <stdlib.h>

int main(){
    // //Floors 
    // int max = 20;
    // for(int i =0 ; i <= 100;i++){
    //     printf("%d\n", (rand() % max)+1);
    // }

    // //people
    // int max= 18; 
    // for(int i =0 ; i <= 100;i++){
    //     printf("%d\n", (rand() % max)+1);
    // }
    
    int number_passenger = (rand() % 18)+1;
    int i  = 0;
    int floors[number_passenger]; /* not good practice */
    while (i <= number_passenger-1)
    {   
        floors[i] = (rand() % 20)+1;
        i++;
        

        
        
    }
    


}
