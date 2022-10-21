#include <stdio.h>
#include <cs50.h>

/*

1. first for loop to control rows
2. second for loop to control columns

*/

int main(void) {
    //number of rows and column
    int n;

    do { //keep asking the user for a positive number n
        n = get_int("Please give a positive number: ");
    } while (n <= 0);

    for (int i = 0; i < n; i++) { //for loop for rows
        for (int j = 0; j <= i; j++) { //for loops for columns
            printf("# ");
        }
        printf("\n");
    }
}
