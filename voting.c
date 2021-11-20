#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

int * getData(char* fn, int *numC, int *numB);
void printData(int numC, int numB, int *data);
void makeMatrix(int *data, int numC, int numB, float matrix[numC][numC]);
void printMatrix(int numC, float matrix[numC][numC]);
void printResults(int numC, float matrix[numC][numC], float victories[numC], int dFlag);
void makeBeatpath(int numC, float matrix[numC][numC]);
void findVictor(int numC, float matrix[numC][numC], float victories[numC]);

int main (int argc, char *argv[]) {
    int dFlag = -1;
    if (argc < 3) {
        printf("Please provide all necessary inputs (voting method and ballot summary txt file).\n");
    } else if (strcmp(argv[1],"-p")==0) {
        printf("***Pairwise Comparison***\n");
        int numC = 0;
        int numB = 0;
        int *data = getData(argv[2],&numC,&numB);
        float matrix[numC][numC];
        float victories[numC];

        makeMatrix(data, numC, numB, matrix);
        findVictor(numC, matrix, victories);
        printResults(numC, matrix, victories, 1);

        free(data);
    } else if (strcmp(argv[1],"-s")==0) {
        printf("***Schulze's beatpath***\n");
        int numC = 0;
        int numB = 0;
        int *data = getData(argv[2],&numC,&numB);
        float matrix[numC][numC];
        float victories[numC];

        makeMatrix(data, numC, numB, matrix);
        makeBeatpath(numC, matrix);
        findVictor(numC, matrix, victories);
        printResults(numC,matrix,victories, 1);
        
        free(data);
    } else {
        printf("Please select one of the available methods.\n");   
    }
}

void makeBeatpath(int numC, float matrix[numC][numC]) {
    int newWeight = 0;
    int temp = 0;
    for (int hops = 1; hops <= numC; hops++) {
        for (int cr = 0; cr < numC; cr++) {
            for (int cc = 0; cc < numC; cc++) {
                if (cr != cc) {
                    newWeight = 0;
                    temp = 0;
                    for (int i = 0; i < numC; i++) {
                        if (matrix[cr][i]!=0 & matrix[i][cc]!=0) {
                            if (matrix[cr][i] < matrix [i][cc]) {
                                temp = matrix[cr][i];
                            } else {
                                temp = matrix[i][cc];
                            }
                            if (temp > matrix[cr][cc]) {
                                matrix[cr][cc] = temp;
                            }
                        }
                    }
                }
            }
        }
    }
}

void findVictor(int numC, float matrix[numC][numC], float victories[numC]) {
    for (int c = 0; c < numC; c++) {
        victories[c] = 0;
    }
    for (int cr = 0; cr < numC; cr++) {
        for (int cc = (cr+1); cc < numC; cc++) {
            if (matrix[cr][cc] > matrix[cc][cr]) {
                victories[cr] = victories[cr] + 1;
            } else if (matrix[cr][cc] < matrix[cc][cr]) {
                victories[cc] = victories[cc] + 1;
            } else {
                victories[cr] = victories[cr] + 0.5;
                victories[cc] = victories[cc] + 0.5;
            }
        }
    }
}

void printResults(int numC, float matrix[numC][numC], float victories[numC], int dFlag) {
    float maxVics = 0;
    int winners[numC];
    for (int i = 0; i < numC; i++) {
        winners[i] = 0;
        if (maxVics < victories[i]) {
            maxVics = victories[i];
        } 
    }
    
    int numWinners = 0;

    for (int i = 0; i < numC; i++) {
        if (victories[i] == maxVics) {
            winners[numWinners] = i;
            numWinners++;
        }
    }
    if (numWinners > 1) {
        printf("There is a %d-way tie between candidates ", numWinners);
        for (int i = 0; i < (numWinners-1); i++) {
            printf("%d, ", winners[i]);
        }
        printf("and %d.\n",winners[numWinners-1]);
    } else {
        printf("Candidate %d is the winner.\n", winners[0]);
    }

    if (dFlag == 1) {
        printf("Final matrix:\n");
        printMatrix(numC, matrix);
        printf("Points gained:\n");
        for (int i = 0; i < numC; i++) {
            printf("C%d: %.1f\n", i, victories[i]);
        }
    }

}

void makeMatrix(int *data, int numC, int numB, float matrix[numC][numC]) {
    for (int i = 0; i < numC; i++) {
        for (int j = 0; j < numC; j++) {
            matrix[i][j] = 0.0;
        }
    }
    int c1rank = -1;
    int c2rank = -1;
    int c1ballots = 0; 
    int c2ballots = 0;
    
    for (int c1 = 0; c1 < (numC-1); c1++) {
        for (int c2 = c1+1; c2 < (numC); c2++) {
            c1ballots = 0;
            c2ballots = 0;
            for (int b = 0; b < numB; b++) {
                c1rank = data[b*numC+c1];
                c2rank = data[b*numC+c2];
                if (c1rank < c2rank) {
                    c1ballots ++;
                } else if (c2rank < c1rank) {
                    c2ballots ++;
                } 
            }
            if (c1ballots > c2ballots) {
                matrix[c1][c2] = c1ballots-c2ballots;
            } else if (c2ballots > c1ballots) {
                matrix[c2][c1] = c2ballots-c1ballots;
            } 
        }
    }
}

int * getData(char* fn, int *numC, int *numB) {
    FILE *fp = fopen(fn, "r");
    int *data; 
    if(!fp) {
        printf("Fix File Name.");
    } else {
        char buff[1024];
        int row = 0;
        int column = 0;

        while (fgets(buff, 1024, fp)) {
            column = 0;
            char* values = strtok(buff, " ");

            if (row ==0) {
                *numC = atoi(values);
                values = strtok(NULL, " ");
                *numB = atoi(values);
                data = malloc((*numC)*(*numB));
            } else {
                while(values) {
                    data[(row-1)*(*numC)+column] = atoi(values);
                    values = strtok(NULL," ");
                    column ++;
                }
            }
            row++;
        }
    }
    return data;
}

void printData(int numC, int numB, int *data) {
    for (int b = 0; b < numB; b ++) {
        for (int c =0; c < numC; c++) {
            printf("%d ", data[b*numC+c]);
        }
        printf("\n");
    }
}

void printMatrix(int numC, float matrix[numC][numC]) {
    printf("\n     ");
    for (int i = 0; i < numC; i++) {
        printf("C%d:  ", i);
    }
    printf("\n");
    for (int i = 0; i < numC; i++) {
        printf("C%d:  ", i);
        for(int j = 0; j < numC; j++) {
            printf("%.1f  ",matrix[i][j]);

        }
        printf("\n");
    }
}