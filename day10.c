#include <stdio.h>
#include <cs50.h>

/*
Seungho Lee
Prime Number Code

1. Ask user for min number and max number and store in variables
2. Have a for loop that goes through the range of number (variable i)
3. Inside, go have another for loop from 2 to the (max - 1) (variable j)
    - Chack if the i % j is 0
    - if yes, print the number as it is prime
*/

int main(void) {
    int min = get_int("Please enter the min number: ");
    int max = get_int("Please enter the max number: ");

    for (int i = min; i <= max; i++) {
        bool div = false;
        if (i < 2) div = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                div = true;
                break;
            }
        }
        if (!div) printf("%d, ", i);
    }
    printf("\n");
}
