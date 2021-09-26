#include <limits.h>
/*
    @param: struct Node *: The next floor that the elevator will go
            int new_floor: A passenger floor
            int capacity : The max amount of passenger per elevator
            int max_floor: The max amount of floors serivces by the elevator
    @return:int: prints the all the floors of the passengers
*/

struct Node
{
    int  floor;
    struct Node* next;
};


//Creates new node wtih new_floor value and adds to head_ref
void append(struct Node** head_ref, int new_floor);

//Moves through list at given node and prints floor values
int iterateList(struct Node *node);

//Creates linked list of random size < capacity with floor numbers
//  < than max_floors, returns the head of this list
void scenario1(int capacity, int max_floors,struct Node *lists);
void scenario2(int capacity, int max_floors, struct Node *lists[]);
void scenario3(int capacity, int max_floors, int maxFloor1, struct Node *lists[]);

void AnalysisSec1(struct Node* scenario);
void AnalysisSec2(struct Node* scenario[]);
int AnalysisSec3(int maxFloor1,struct Node* scenario[]);