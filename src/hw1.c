#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "hw1.h"

char board[MAX_ROWS][MAX_COLS] = {0};
/*
Hint: Consider adding a global variable to store a string large enough to store a board.
*/

int full_board(int num_rows, int num_cols){
    int row_size = num_cols;
    int col_size = num_rows;

    for (int row = 0; row< row_size; row++){
        for (int col = 0; col< col_size; col++){
            char current_token = board[row][col];
            if (current_token == '-'){
                return 0;
            }
        }
    }
    return 1;
}

void insert_token(char token, int row, int column){
    
    board[row][column] = token;

    return;
}

int check_and_insert(char token, int row, int column){
    char cell_token = board[row][column];

    if(cell_token == '-'){
        board[row][column] = token;
        return 1;
    }   

    return 0;
}

int four_in_a_row(int num_rows, int num_cols){
    int row_size = num_cols;
    int col_size = num_rows;

    char check_token;
    char token1, token2, token3;

    //horizontal checks
    for (int row = 0; row<row_size; row++){
        for(int col = 0; col<col_size-3; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row][col+1];
            token2 = board[row][col+2];
            token3 = board[row][col+3];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 0; 
        }
    }

    //vertical checks
    for (int row = 0; row<row_size-3; row++){
        for(int col = 0; col<col_size; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row+1][col];
            token2 = board[row+2][col];
            token3 = board[row+3][col];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 0;
        }
    }

    //downright diagonals
    for (int row = 0; row<row_size-3; row++){
        for(int col = 0; col<col_size-3; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row+1][col+1];
            token2 = board[row+2][col+2];
            token3 = board[row+3][col+3];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 0;
        }
    }

    //upright diagonals
    for (int row = 3; row<row_size; row++){
        for(int col = 0; col<col_size-3; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row-1][col+1];
            token2 = board[row-2][col+2];
            token3 = board[row-3][col+3];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 0;
        }
    }

    return 1;
}

void print_board(int num_rows, int num_cols){
    int row_size = num_cols;
    int col_size = num_rows;

    char print_row[row_size*2+1];

    for (int row = 0; row<row_size; row++){
        char *iterator = print_row;
        for(int col = 0; col<col_size; col++){
            *iterator = board[row][col];
            iterator++;
            *iterator = ' ';
            iterator++;
        }

        //
        *iterator = '\0';
        printf("%s\n", print_row);
    }

    return;
}

void initialize_board(const char *initial_state, int num_rows, int num_cols) {
    int row_size = num_cols;
    int col_size = num_rows;

    for (int row = 0; row<row_size; row++){
        for(int col = 0; col<col_size; col++){
            board[row][col] = initial_state[(row*row_size) + col];
        }
    }

    return;
}

int solve(const char *initial_state, int num_rows, int num_cols, int *num_x, int *num_o) {   

    return 0;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 

    return 0;
}
