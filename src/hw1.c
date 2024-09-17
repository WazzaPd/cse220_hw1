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

    for (int row = 0; row< num_rows; row++){
        for (int col = 0; col< num_cols; col++){
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

    char check_token;
    char token1, token2, token3;

    //horizontal checks
    for (int row = 0; row<num_rows; row++){
        for(int col = 0; col<num_cols-3; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row][col+1];
            token2 = board[row][col+2];
            token3 = board[row][col+3];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1; 
        }
    }

    //vertical checks
    for (int row = 0; row<num_rows-3; row++){
        for(int col = 0; col<num_cols; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row+1][col];
            token2 = board[row+2][col];
            token3 = board[row+3][col];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1;
        }
    }

    //downright diagonals
    for (int row = 0; row<num_rows-3; row++){
        for(int col = 0; col<num_cols-3; col++){
            
            check_token = board[row][col];
            if (check_token == '-') continue;

            token1 = board[row+1][col+1];
            token2 = board[row+2][col+2];
            token3 = board[row+3][col+3];

            if (token1 == check_token && token2 == check_token && token3 == check_token) return 1;
        }
    }

    //upright diagonals
    for (int row = 3; row<num_rows; row++){
        for(int col = 0; col<num_cols-3; col++){
            
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
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void initialize_board(const char *initial_state, int num_rows, int num_cols) {
    for (int row = 0; row<num_rows; row++){
        for(int col = 0; col<num_cols; col++){
            board[row][col] = initial_state[(row*num_cols) + col];
        }
    }
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

    if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_FOUR_IN_A_ROW;

    for (int i = 0; initial_state[i] != 0; i++){
        if(initial_state[i] != 'x' && initial_state[i] != 'o' && initial_state[i] != '-'){
            return INITIAL_BOARD_INVALID_CHARACTERS;
        }
    }
    
    // const char* iterator = initial_state;
    // while (*iterator!='\0'){
    //     if(*iterator != 'x' && *iterator != 'o' && *iterator != '-'){
    //         return INITIAL_BOARD_INVALID_CHARACTERS;
    //     }
    //     iterator++;
    // }
    char *token1, *token2, *token3, *token4;


    while(! full_board(num_rows, num_cols)){
        int next_cycle = 0;

        //check horizontal
        for (int row = 0; row<num_rows; row++){
            for(int col = 0; col<num_cols-3; col++){
                
                token1 = &board[row][col];
                token2 = &board[row][col+1];
                token3 = &board[row][col+2];
                token4 = &board[row][col+3];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        //vertical checks
        for (int row = 0; row<num_rows-3; row++){
            for(int col = 0; col<num_cols; col++){
                
                token1 = &board[row][col];
                token2 = &board[row+1][col];
                token3 = &board[row+2][col];
                token4 = &board[row+3][col];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        //downright diagonals
        for (int row = 0; row<num_rows-3; row++){
            for(int col = 0; col<num_cols-3; col++){
                
                token1 = &board[row][col];
                token2 = &board[row+1][col+1];
                token3 = &board[row+2][col+2];
                token4 = &board[row+3][col+3];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
            }
        }

        //upright diagonals
        for (int row = 3; row<num_rows; row++){
            for(int col = 0; col<num_cols-3; col++){
                
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

        //print_board(num_rows, num_cols);
        return HEURISTICS_FAILED;
    }

    int countx = 0;
    int counto = 0;

    for (int row = 0; row<num_rows; row++){
            for(int col = 0; col<num_cols; col++){
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
    char *board_string = malloc(num_rows*num_cols*sizeof(char));

    while(true){
        int i = 0;
        for (int row = 0; row<num_rows; row++){
            for(int col = 0; col<num_cols; col++){
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
    char *board_string = malloc(num_rows*num_cols*sizeof(char));
    
    char medium_board[num_rows][num_cols];

    // populate_board(medium_board, num_rows, num_cols);

    //check for invalid chars
    // for(int i = 0; i<num_cols*num_rows; i++){
    //     char current = final_state[i];
    //     if (current != 'x' && current != 'o'){
    //         return;
    //     }
    // }

    int i = 0;
    for (int row = 0; row<num_rows; row++){
        for(int col = 0; col<num_cols; col++){
            medium_board[row][col] = final_state[(row*num_cols) + col];
            board_string[i] = medium_board[row][col];
            i++;
        }
    }

    initialize_board(board_string, num_rows, num_cols);

    int *num_x = malloc(sizeof(int));
    int *num_o = malloc(sizeof(int));   
    //get rid of a token
    for (int row = 0; row<num_rows; row++){

        //WHY TF CAN COL = 5
        for(int col = 0; col<num_cols; col++){
            char store = medium_board[row][col];
            medium_board[row][col] = '-';
            board_string[(row*num_cols)+col] = '-';
            
            initialize_board(board_string, num_rows, num_cols);

            // printf("after switch\n");
            // print_board(num_rows, num_cols);
            // printf("\n");

            //solve
            int code = solve(board_string, num_rows, num_cols, num_x, num_o);

            if(code != FOUND_SOLUTION){
                medium_board[row][col] = store;
                board_string[(row*num_cols)+col] = store;
            }
        }
    }
    free(num_x);
    free(num_o);

    return board_string;
}
