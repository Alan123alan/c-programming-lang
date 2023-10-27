#include <stdio.h>
#include <stdlib.h>

#define COLS 20
#define ROWS 10

void init_matrix(int **matrix, int col_count, int row_count);
void print_matrix(int **matrix, int col_count, int row_count);


int main(int argc, char *argv[]){
    //creating a pointer to int pointers
    int **matrix = malloc(sizeof(int*)*ROWS);
    for(int i = 0; i < ROWS; i++){
        //setting the pointer to int pointers to the address provided by malloc
        matrix[i] = malloc(sizeof(int)*COLS);
    }
    init_matrix(matrix, COLS, ROWS);
    print_matrix(matrix, COLS, ROWS);
}


void init_matrix(int **matrix, int col_count, int row_count){
    //since matrix is now a pointer to int pointers
    //containing two dimensions means we can use double indexing?
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < col_count; j++)
        {
            matrix[i][j] = j;
        }
        
    }
}

void print_matrix(int **matrix, int col_count, int row_count){
    printf("[\n");
    for (int i = 0; i < row_count; i++)
    {
        printf("[");
        for (int j = 0; j < col_count; j++)
        {
            printf("%d", matrix[i][j]);
            if(j < col_count-1){
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("]\n");
}
