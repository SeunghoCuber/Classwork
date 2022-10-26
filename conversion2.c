#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

/*

CONVERTS FROM OTHER BASE TO DECIMAL

1. get user input
2. convert number to decimal by adding all powers of the base
4. print the decimal number
5. ask user to repeat

*/


int digits[100]; //array that stores digits of each number
char alph[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; //array for hex characters

int convert(int n, int base);
string ask_repeat();

int main() {
    //string for asking user if they want to repeat
    string repeat = "";

    //while loop for asking converting multiple numbers
    do {
        //get user input
        int n = get_int("Please enter a number to convert to decimal: ");
        int base = get_int("What is the base of your number?: ");


        //convert the number to decimal
        int decimal = convert(n, base);

        //print the new decimal number
        printf("Decimal: %d\n", decimal);

        //ask user if they want to repeat
        repeat = ask_repeat();

    } while (!strcmp(repeat, "yes"));
}

int convert(int n, int base) {
    int decimal = 0;
    for (int i = 0; n > 0; i++) {
        //store each digit in the array + update count
        decimal += (int)pow(2, i) * (n % 10);
        n /= 10;
    }
    return decimal;
}

string ask_repeat() {
    string repeat;
    do {
        repeat = get_string("Would you like to convert again? (yes or no) ");
    } while (strcmp(repeat, "yes") && strcmp(repeat, "no"));
    return repeat;
}
