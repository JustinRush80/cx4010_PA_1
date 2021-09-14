
/*
    @param: struct Node *: The next floor that the elevator will go
            int new_floor: A passenger floor
            int capacity : The max amount of passenger per elevator
            int max_floor: The max amount of floors serivces by the elevator
    @return:int: prints the all the floors of the passengers
*/



struct Node  // the struct for the linked list 
{
    int  floor;
    struct Node* next;
};

void append(struct Node** head_ref, int new_floor);
void printList(struct Node *node);
struct Node *generatePassengers(int capacity, int max_floors);