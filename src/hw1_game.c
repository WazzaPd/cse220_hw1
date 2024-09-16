#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hw1.h"

int main(int argc, char **argv) {
    assert(argc == 4);

    int num_rows = (int)strtoul(argv[1], NULL, 10);
    int num_cols = (int)strtoul(argv[2], NULL, 10);

    initialize_board(argv[3], num_rows, num_cols);

    char piece_choice;
    int row_choice;
    int column_choice;
    int choosing;

    //Loop until the board is filled = Win
    while(! full_board(num_rows, num_cols)){

        print_board(num_rows, num_cols);

        //Loop until quit or made a valid choice
        choosing = 1;
        while(choosing){
            printf("Choose a piece (x or o) or q to quit: ");
            if (scanf(" %c", &piece_choice) == 0){
                printf("Invalid choice. ");
            }else if (piece_choice == 'q'){
                return 0;
            } else if (piece_choice != 'x' && piece_choice != 'o'){
                printf("Invalid choice. ");
            } else {
                choosing = 0;
            }
        }

        //Loop until made valid choice
        choosing = 1;
        while(choosing){
            printf("Choose a row (0-%d): ", num_rows-1);
            if (scanf(" %d", &row_choice) == 0 || row_choice > 4 || row_choice < 0 ){
                printf("Invalid choice. ");
            } else {
                choosing = 0;
            }
        }

        //Loop until made valid choice
        choosing = 1;
        while(choosing){
            printf("Choose a column (0-%d): ", num_cols-1);
            if (scanf(" %d", &column_choice) == 0 || column_choice > 4 || column_choice < 0 ){
                printf("Invalid choice. ");
            } else {
                choosing = 0;
            }
        }

        int space_valid = check_and_insert(piece_choice, row_choice, column_choice);
        if(!space_valid) {
            printf("Invalid choice. That space is already occupied.\n");
            continue;
        }

        int connect_valid = four_in_a_row(num_rows, num_cols);
        if(!connect_valid) {
            insert_token('-', row_choice, column_choice);
            printf("Invalid choice. You have created 4-in-a-row.\n");
            continue;
        }
    }
    printf("Congratulations, you have filled the board with no 4-in-a-rows!\n");
    print_board(num_rows, num_cols);
    return 0;
}
