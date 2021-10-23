#define WORDLIST 500

struct Node
{
    int  wordIdx;
    struct Node* next;
};

struct mapping
{
    int key;
    char word[5];
};

// Open the file and intialize the mapping with the word list 
void CreateMapping (char* filename,struct mapping string[WORDLIST]);
// Using the mapping to create a abjactery martix
void CreateAbJMartix (struct mapping string[WORDLIST],int matrix[WORDLIST][WORDLIST]);
//Compare the a string to all the other strings return the difference 
int CompareString(char* string1, char* string2);

void printList(int list[]);
//Adds a node onto a list
void append(struct Node** head_ref, int nextWord);
//Converts the found path of word indices into words and prints to terminal
void printlList(struct mapping string[WORDLIST], int matrix[WORDLIST][WORDLIST], struct Node *node, int end);
//Finds a path between the start and end word indices
void pathFind(struct Node* path, int* adjMat, int start, int end);
