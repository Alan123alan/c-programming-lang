#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

void print_matrix(int *matrix, int col_count, int row_count);
void init_matrix(int *matrix, int col_count, int row_count);

int main(int argc, char *argv[]){
    int *matrix = malloc(sizeof(int)*ROWS*COLS);
    if(matrix == NULL){
        perror("Failed to allocate memory for matrix.");
        exit(-1);
    }
    init_matrix(matrix, COLS, ROWS);
    print_matrix(matrix, COLS, ROWS);
    return 0;
}

void init_matrix(int *matrix, int col_count, int row_count){
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < col_count; j++)
        {
            matrix[i*COLS+j] = i*COLS+j;
        }
        
    }
}

void print_matrix(int *matrix, int col_count, int row_count){
    printf("[\n");
    for (int i = 0; i < row_count; i++)
    {
        printf("[");
        for (int j = 0; j < col_count; j++)
        {
            printf("%d", matrix[i*COLS+j]);
            if((i*COLS+j) < (ROWS*COLS)-1){
                printf(", ");
            }
        }
        printf("]\n");
        
    }
    printf("]\n");
}
