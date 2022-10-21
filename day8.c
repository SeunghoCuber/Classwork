#include <stdio.h> //standard input/output library
#include <cs50.h>

/*

Seungho Lee
09/20/22
1. Ask the user for a number (num variable)
2. check if the number is greater than 0 and less than 2^16
3. create a counter variable
4. make a loop that repeats "num" times (1 -> n)
    a. each iteration, add the iterating variable to the counter variable
5. print the counter variable after the loop

*/

int main(void) {
    int num;
    do {
        num = get_int("Enter an integer: ");
    } while (num < 0 || num >= 65536);

    int count = 0;
    for (int i = 1; i <= num; i++) {
        count += i;
    }

/*
    //this is with while loop
    int i = 0;
    while (i <= num) {
        count += i++;
    }
*/

    printf("Sum: %d\n", count);
}
