#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*

USES ONE FUNCTION

1. get user input
2. get the length of each numbers from conversion function and store in variables
3. in each conversion function, keep dividing number by the base until "n" is 0
    i. store each digit in the array
    ii. keep track of how many digits there are
4. print digits in the opposite order using the length
5. ask user to repeat

*/


int count = 0;
char alph[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; //array for hex characters

int * convert(int n, int base);
string ask_repeat();

int main() {
    //string for asking user if they want to repeat
    string repeat = "";

    //while loop for asking converting multiple numbers
    do {
        //get user input
        int n = get_int("Please enter a decimal number: ");
        int base = get_int("Please enter the base to convert to: ");


        //get the length of the new base number + convert to new base
        int * digits = convert(n, base);

        //print the new base number in a reverse order
        printf("Base %d: ", base);
        for (int i = count - 1; i >= 0; i--) {
            if (digits[i] > 9) {
                printf("%c", alph[digits[i] - 10]);
            }else {
                printf("%d", digits[i]);
            }
        }
        printf("\n");


        //ask user if they want to repeat
        repeat = ask_repeat();

    } while (!strcmp(repeat, "yes"));
}

int * convert(int n, int base) {
    static int digits[100]; //array that stores digits of each number
    count = 0;
    while (n > 0) { //keep dividing n by "base" until n == 0
        //store each digit in the array + update count
        digits[count++] = n % base;
        n /= base;
    }
    return digits;
}

string ask_repeat() {
    string repeat;
    do {
        repeat = get_string("Would you like to convert again? (yes or no) ");
    } while (strcmp(repeat, "yes") && strcmp(repeat, "no"));
    return repeat;
}
