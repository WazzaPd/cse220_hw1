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

// return 1 if four in a row
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

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1; 
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

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1;
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

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1;
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

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1;
        }
    }

    return 0;
}

void print_board(int num_rows, int num_cols) {
    int row_size = num_cols;
    int col_size = num_rows;
    for (int row = 0; row < row_size; row++) {
        for (int col = 0; col < col_size; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
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

char opposite_piece(char piece){
    if(piece == 'x'){
        return 'o';
    }
    return 'x';
}

//function for implementing the heuristic, 1 for success 0 for no replacement
int three_equal_and_one_dash(char *token1, char *token2, char *token3, char* token4){
    if (*token1 == *token2 && *token1 == *token3 && *token1 != *token4 && *token4 == '-'){
        //replacing token 4
        *token4 = opposite_piece(*token1);
        return 1;
    } 
    else if (*token1 == *token2 && *token1 == *token4 && *token1 != *token3 && *token3 == '-'){
        //replacing token 3
        *token3 = opposite_piece(*token1);
        return 1;
    } 
    else if (*token1 == *token3 && *token1 == *token4 && *token1 != *token2 && *token2 == '-'){
        //replacing token 2
        *token2 = opposite_piece(*token1);
        return 1;
    }
    else if (*token2 == *token3 && *token2 == *token4 && *token2 != *token1 && *token1 == '-'){
        //replacing token 1
        *token1 = opposite_piece(*token2);
        return 1;
    }
    return 0;
}


int solve(const char *initial_state, int num_rows, int num_cols, int *num_x, int *num_o) {   

    initialize_board(initial_state, num_rows, num_cols);

    printf("Solve this board\n");
    print_board(num_rows, num_cols);
    printf("\n");

    if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_FOUR_IN_A_ROW;

    const char* iterator = initial_state;
    while (*iterator!='\0'){
        if(*iterator != 'x' && *iterator != 'o' && *iterator != '-'){
            return INITIAL_BOARD_INVALID_CHARACTERS;
        }
        iterator++;
    }

    int row_size = num_cols;
    int col_size = num_rows;
    char *token1, *token2, *token3, *token4;


    while(! full_board(num_rows, num_cols)){
        int next_cycle = 0;

        //check horizontal
        for (int row = 0; row<row_size; row++){
            for(int col = 0; col<col_size; col++){
                
                token1 = &board[row][col];
                token2 = &board[row][col+1];
                token3 = &board[row][col+2];
                token4 = &board[row][col+3];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        //vertical checks
        for (int row = 0; row<row_size-3; row++){
            for(int col = 0; col<col_size; col++){
                
                token1 = &board[row][col];
                token2 = &board[row+1][col];
                token3 = &board[row+2][col];
                token4 = &board[row+3][col];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        //downright diagonals
        for (int row = 0; row<row_size-3; row++){
            for(int col = 0; col<col_size-3; col++){
                
                token1 = &board[row][col];
                token1 = &board[row+1][col+1];
                token3 = &board[row+2][col+2];
                token4 = &board[row+3][col+3];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        //upright diagonals
        for (int row = 3; row<row_size; row++){
            for(int col = 0; col<col_size-3; col++){
                
                token1 = &board[row][col];
                token2 = &board[row-1][col+1];
                token3 = &board[row-2][col+2];
                token4 = &board[row-3][col+3];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        if(next_cycle){
            continue;
        }

        return HEURISTICS_FAILED;
    }

    int countx = 0;
    int counto = 0;

    for (int row = 0; row<row_size; row++){
            for(int col = 0; col<col_size; col++){
                char current = board[row][col];
                if (current == 'x') countx++;
                else counto++;
        }
    }

    *num_x = countx;
    *num_o = counto;

    return FOUND_SOLUTION;
}

// brute force random tokens to create a valid board (helper to prove generate_medium works)
char* populate_board(char **medium_board, int num_rows, int num_cols){
    int row_size = num_cols;
    int col_size = num_rows;
    char *board_string = malloc(row_size*col_size*sizeof(char));

    while(true){
        int i = 0;
        for (int row = 0; row<row_size; row++){
            for(int col = 0; col<col_size; col++){
                int random_piece = rand() % 2;
                if(random_piece) medium_board[row][col] = 'x';
                else medium_board[row][col] = 'o';

                board_string[i] = medium_board[row][col];
                i++;
            }
        }

        //check if current board is valid
        initialize_board(board_string, num_rows, num_cols);
        if(! four_in_a_row(num_rows, num_cols)) break;
    }

    return board_string;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 
    int row_size = num_cols;
    int col_size = num_rows;
    char *board_string = malloc(row_size*col_size*sizeof(char));
    
    char **medium_board = malloc(num_rows*sizeof(char *));
    for (int i = 0; i < num_rows; i++){
        medium_board[i] = malloc(num_cols*sizeof(char));
    }

    // populate_board(medium_board, num_rows, num_cols);

    int i = 0;
    for (int row = 0; row<row_size; row++){
        for(int col = 0; col<col_size; col++){
            medium_board[row][col] = final_state[(row*row_size) + col];
            board_string[i] = medium_board[row][col];
            i++;
        }
    }

    initialize_board(board_string, num_rows, num_cols);

    //get rid of a token
    for (int row = 0; row<num_cols; row++){
        for(int col = 0; col<num_rows; col++){
            char store = medium_board[row][col];
            medium_board[row][col] = '-';
            board_string[row*row_size+col] = '-';

            //solve
            int *num_x = malloc(sizeof(int));
            int *num_o = malloc(sizeof(int));   
            int code = solve(board_string, num_rows, num_cols, num_x, num_o);
            free(num_x);
            free(num_o);
            printf("code: %d\n", code);

            if(code == INITIAL_BOARD_NO_SOLUTION || code == HEURISTICS_FAILED){
                medium_board[row][col] = store;
                board_string[row*row_size+col] = store;
            }
        }
    }

    for (int freeIndex = 0; freeIndex < num_rows; freeIndex++){
        free(medium_board[freeIndex]);
    }
    free(medium_board);

    return board_string;
}
