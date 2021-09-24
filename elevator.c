#include <stdio.h>
#include "elevator.h"
#include <time.h>


  
// return the optimum max floor number for secanrio3
int GetOptimum(struct Node* scenario3[]){
                                          
    int maximum = INT_MAX;
    int maxFloor1 = 0;
    
    for(int i=6; i <= 13; i++ ){
        int max = AnalysisSec3(i,scenario3);
        if ( maximum > max){
            maximum = max;
            maxFloor1 = i;
        }
        
    }
    printf("%d",maxFloor1);

    return maxFloor1;
}



int main(){
    
    struct Node sc1 = {-1,NULL};
    struct Node* sc2[2] = {NULL,NULL};
    struct Node* sc3[2] = {NULL,NULL};
    
    // GetOptimum(sc3); 
    AnalysisSec1(&sc1);
    AnalysisSec2(sc2);
    AnalysisSec3(11,sc3);

   
    
    return 0;

}

