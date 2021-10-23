#include <stdio.h>
#define WORDLIST 500


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
int CompareString(char* string1, char* string2)

void PrintString(struct mapping string[WORDLIST], int matrix[WORDLIST][WORDLIST]);




int main()
{
    struct mapping string[WORDLIST];  
    CreateMapping("wordlist.txt",string);
    
    int matrix[WORDLIST][WORDLIST];
    CreateAbJMartix(string,matrix);

    PrintString(string,matrix);


    
}

void CreateMapping(char* filename, struct mapping string[WORDLIST])
{
    FILE *fp;
    fp = fopen(filename,"r");
    int i = 0;
    
    while(fscanf(fp, "%s", string[i].word)!=EOF) // store the string to the struct mapping
    { 
        string[i].key = i; // set the key to the string to be it's index 
        i ++;  
    }  
    fclose(fp);

}

int CompareString(char* string1, char* string2)
{   int count = 0;
    for(int letter = 0 ; letter<5; letter++)
    {   
        if (string1[letter] != string2[letter]){
            count+=1;
        }

        if (count > 1){
            return 100;
        }
    }
    
    return count; 
}

void CreateAbJMartix (struct mapping string[WORDLIST], int matrix[WORDLIST][WORDLIST])
{   
    
    
    for(int i = 0; i < WORDLIST ; i++)
    {  
        for(int j = 0; j<WORDLIST; j++)
        {
            int count = CompareString(string[i].word,string[j].word);
            if (count == 1){
                matrix[i][j] = 1; 
            }
            else 
            {
                matrix[i][j] = 0;
            }
               

        }
        
    }


}

void PrintString(struct mapping string[WORDLIST], int matrix[WORDLIST][WORDLIST])
{
    for(int a = 0 ; a<WORDLIST; a++ ){
        if (a != 0){
		   printf("\n");
       }
       printf("%s ",string[a].word);
       for (int b = 0; b<WORDLIST; b++){
           if (matrix[a][b]== 1){
               printf("Connects to\t %s ",string[b].word);

           }
           

       }
    }
}
