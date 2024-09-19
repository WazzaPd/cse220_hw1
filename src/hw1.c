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

    for (int i = 0; i < num_cols*num_rows; i++){
        //printf("%c\n", initial_state[i]);
        if(initial_state[i] != 'x' && initial_state[i] != 'o' && initial_state[i] != '-'){
            return INITIAL_BOARD_INVALID_CHARACTERS;
        }
    }

    char *token1, *token2, *token3, *token4;

    while(! full_board(num_rows, num_cols)){
        int next_cycle = 0;

        print_board(num_rows, num_cols);
        printf("\n");

        //check horizontal
        for (int row = 0; row<num_rows; row++){
            for(int col = 0; col<num_cols-3; col++){
                
                token1 = &board[row][col];
                token2 = &board[row][col+1];
                token3 = &board[row][col+2];
                token4 = &board[row][col+3];

                if(three_equal_and_one_dash(token1, token2, token3, token4)) next_cycle = 1;
                if(four_in_a_row_for_single_token(num_rows, num_cols, row, col)) return INITIAL_BOARD_NO_SOLUTION;
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
                if(four_in_a_row_for_single_token(num_rows, num_cols, row, col)) return INITIAL_BOARD_NO_SOLUTION;
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
                if(four_in_a_row_for_single_token(num_rows, num_cols, row, col)) return INITIAL_BOARD_NO_SOLUTION;
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
                if(four_in_a_row_for_single_token(num_rows, num_cols, row, col)) return INITIAL_BOARD_NO_SOLUTION;
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

// int four_in_a_row_for_single_token(const char *initial_state, int num_rows, int num_cols, int row, int col){
int four_in_a_row_for_single_token(int num_rows, int num_cols, int row, int col){

    //initialize_board(initial_state, num_rows, num_cols);
    
    // diagonals read from left to right. EX: A diagonal down would start from top-left to bottom-right
    int vertical_row_start, vertical_row_end, horizontal_col_start, horizontal_col_end,
    diagonal_down_row_start, diagonal_down_row_end, diagonal_down_col_start, diagonal_down_col_end, 
    diagonal_up_row_start, diagonal_up_row_end, diagonal_up_col_start, diagonal_up_col_end;

    int check_diagonal_down = 0, check_diagonal_up = 0;
    // print_board(num_rows, num_cols);
    // printf("\n");

    // Compute Vertical limits
    if(row > 2){
        vertical_row_start = row-3;
    } else {
        vertical_row_start = 0;
    }
    if(row < num_rows-3){
        vertical_row_end = row+3;
    } else {
        vertical_row_end = num_rows-1;
    }

    // Compute Horizontal limits
    if(col > 2){
        horizontal_col_start = col-3;
    } else {
        horizontal_col_start = 0;
    }
    if(col < num_cols-3){
        horizontal_col_end = col+3;
    } else {
        horizontal_col_end = num_cols-1;
    }

    // Compute Diagonal down right limits
    //compute starts
    if(row <= col){
        if(row > 2){
            diagonal_down_row_start = row-3;
            diagonal_down_col_start = col-3;
        } else {
            diagonal_down_row_start = 0;
            diagonal_down_col_start = col-row;
        }
    } else{
        if(col > 2){
            diagonal_down_col_start = col-3;
            diagonal_down_row_start = row-3;
        } else {
            diagonal_down_col_start = 0;
            diagonal_down_row_start = row-col;
        }
    }
    //compute ends
    if((num_rows-row) <= (num_cols-col)){
        if(row < num_rows-3){
            diagonal_down_row_end = row+3;
            diagonal_down_col_end = col+3;
        } else {
            diagonal_down_row_end = num_rows-1;
            diagonal_down_col_end = col+((num_rows-1)-row);
        }
    } else{
        if(col < num_cols-3){
            diagonal_down_col_end = col+3;
            diagonal_down_row_end = row+3;
        } else {
            diagonal_down_col_end = num_cols-1;
            diagonal_down_row_end = row+((num_cols-1)-col);
        }
    }

    // Compute Diagonal up right limits ("inverting board so we can reuse code": row = (num_rows-1)-row )
    //compute starts
    int distance_from_end = (num_rows-1)-row;

    if( distance_from_end <= col){
        if(distance_from_end > 2){
            diagonal_up_row_start = row+3;
            diagonal_up_col_start = col-3;
        } else {
            diagonal_up_row_start = num_rows-1;
            diagonal_up_col_start = col-distance_from_end;
        }
    } else{
        if(col > 2){
            diagonal_up_col_start = col-3;
            diagonal_up_row_start = row+3;
        } else {
            diagonal_up_col_start = 0;
            diagonal_up_row_start = row+col;
        }
    }
    //compute ends
    if(row <= ((num_cols-1)-col)){
        if(row > 2){
            diagonal_up_row_end = row-3;
            diagonal_up_col_end = col+3;
        } else {
            diagonal_up_row_end = 0;
            diagonal_up_col_end = col+row;
        }
    } else{
        if(col < num_cols-3){
            diagonal_up_col_end = col+3;
            diagonal_up_row_end = row-3;
        } else {
            diagonal_up_col_end = num_cols-1;
            diagonal_up_row_end = row-((num_cols-1)-col);
        }
    }

    if(diagonal_down_col_end - diagonal_down_col_start >= 0){
        check_diagonal_down = 1;
    }

    if(diagonal_up_col_end - diagonal_down_col_start >= 0){
        check_diagonal_up = 1;
    }

    char *token1, *token2, *token3, *token4;

    diagonal_down_row_end = diagonal_up_row_end;
    diagonal_up_row_end = diagonal_down_row_end;

    for(int i = vertical_row_start; i<=vertical_row_end-3; i++){
        token1 = &board[i][col];
        token2 = &board[i+1][col];
        token3 = &board[i+2][col];
        token4 = &board[i+3][col];

        if (*token1 == *token4 && *token2 == *token4 && *token3 == *token4) return 1;
        //if(three_equal_and_one_dash(token1, token2, token3, token4)) found = 1;
        //if(four_in_a_row(num_rows, num_cols)) return INITIAL_BOARD_NO_SOLUTION;
    }

    for(int i = horizontal_col_start; i<=horizontal_col_end-3; i++){
        token1 = &board[row][i];
        token3 = &board[row][i+1];
        token4 = &board[row][i+2];
        token2 = &board[row][i+3];
        if (*token1 == *token4 && *token2 == *token4 && *token3 == *token4) return 1;
    }

    if(check_diagonal_down){
        for(int i = diagonal_down_col_start; i<=diagonal_down_col_end-3; i++){
            token1 = &board[diagonal_down_row_start][i];
            token3 = &board[diagonal_down_row_start+1][i+1];
            token4 = &board[diagonal_down_row_start+2][i+2];
            token2 = &board[diagonal_down_row_start+3][i+3];

            diagonal_down_row_start++;

            if (*token1 == *token4 && *token2 == *token4 && *token3 == *token4) return 1;
        }
    }

    if(check_diagonal_up){
        for(int i = diagonal_up_col_start; i<=diagonal_up_col_end-3; i++){
            token1 = &board[diagonal_up_row_start][i];
            token3 = &board[diagonal_up_row_start-1][i+1];
            token4 = &board[diagonal_up_row_start-2][i+2];
            token2 = &board[diagonal_up_row_start-3][i+3];

            diagonal_up_row_start--;

            if (*token1 == *token4 && *token2 == *token4 && *token3 == *token4) return 1;
        }
    }
    
    return 0;
}

char* generate_medium(const char *final_state, int num_rows, int num_cols) { 
    char *board_string = malloc(num_rows*num_cols*sizeof(char));

    char *boardcopy = malloc(num_rows*num_cols*sizeof(char));
    
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
            boardcopy[i] = medium_board[row][col];
            i++;
        }
    }

    initialize_board(board_string, num_rows, num_cols);

    int *num_x = malloc(sizeof(int));
    int *num_o = malloc(sizeof(int));   
    //get rid of a token
    for (int row = 0; row<num_rows; row++){

        for(int col = 0; col<num_cols; col++){
            char store = medium_board[row][col];
            medium_board[row][col] = '-';
            board_string[(row*num_cols)+col] = '-';
            boardcopy[(row*num_cols)+col] = '-';
            
            initialize_board(board_string, num_rows, num_cols);

            // printf("after switch\n");
            // print_board(num_rows, num_cols);
            // printf("\n");

            //solve
            int code = solve(board_string, num_rows, num_cols, num_x, num_o);
            //int code = solve_for_single_token(boardcopy, num_rows, num_cols, row, col);

            boardcopy[(row*num_cols)+col] = store;

            if(code != FOUND_SOLUTION){
                medium_board[row][col] = store;
                board_string[(row*num_cols)+col] = store;
            }
        }
    }
    free(num_x);
    free(num_o);

    free(boardcopy);

    return board_string;
}
