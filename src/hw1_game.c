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

    //Testing Generate Board
    //generate_medium(argv[3], num_rows, num_cols);

    //Testing solve function
    // int *num_x = malloc(sizeof(int));
    // int *num_o = malloc(sizeof(int));

    // printf("%d\n", solve(argv[3], num_rows, num_cols, num_x, num_o));
    // print_board(num_rows, num_cols);
    // printf("x's: %d, o's: %d\n", *num_x, *num_o);

    // free(num_x);
    // free(num_o);

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
            if (scanf("%d", &row_choice) == 0 || row_choice > num_rows || row_choice < 0 ){
                getchar();
                printf("Invalid choice. ");
            } else {
                choosing = 0;
            }
        }

        //Loop until made valid choice
        choosing = 1;
        while(choosing){
            printf("Choose a column (0-%d): ", num_cols-1);
            if (scanf("%d", &column_choice) == 0 || column_choice > num_cols || column_choice < 0 ){
                getchar();
                printf("Invalid choice. ");
            } else {
                choosing = 0;
            }
        }
        // char input[3];

        // choosing = 1;
        // while (choosing) {
        //     printf("Choose a piece (x or o) or q to quit: ");
        //     if (fgets(input, sizeof(input), stdin) != NULL) {
        //         piece_choice = input[0];  // Take the first character from input
        //         if (piece_choice == 'q') {
        //             return 0;
        //         } else if (piece_choice != 'x' && piece_choice != 'o') {
        //             printf("Invalid choice. ");
        //         } else {
        //             choosing = 0;
        //         }
        //     } else {
        //         printf("Invalid choice. ");
        //     }
        // }

        // choosing = 1;
        // while (choosing) {
        //     printf("Choose a row (0-%d): ", num_rows - 1);
        //     if (fgets(input, sizeof(input), stdin) != NULL) {
        //         if(input[0] == '0'){
        //             row_choice = 0;
        //         } else if(atoi(input) == 0){
        //             row_choice = -1;
        //         } else {
        //             row_choice = atoi(input);  // Convert string input to integer
        //         }
        //         if (row_choice >= num_rows || row_choice < 0) {
        //             printf("Invalid choice. ");
        //         } else {
        //             choosing = 0;
        //         }
        //     } else {
        //         printf("Invalid choice. ");
        //     }
        // }

        // // Loop until made valid choice for column
        // choosing = 1;
        // while (choosing) {
        //     printf("Choose a column (0-%d): ", num_cols - 1);
        //     if (fgets(input, sizeof(input), stdin) != NULL) {
        //         if(input[0] == '0'){
        //             column_choice = 0;
        //         } else if(atoi(input) == 0){
        //             column_choice = -1;
        //         } else {
        //             column_choice = atoi(input);  // Convert string input to integer
        //         }
        //         if (column_choice >= num_cols || column_choice < 0) {
        //             printf("Invalid choice. ");
        //         } else {
        //             choosing = 0;
        //         }
        //     } else {
        //         printf("Invalid choice. ");
        //     }
        // }

        int space_valid = check_and_insert(piece_choice, row_choice, column_choice);
        if(!space_valid) {
            printf("Invalid choice. That space is already occupied.\n");
            continue;
        }

        int connect_valid = (! four_in_a_row(num_rows, num_cols));
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
