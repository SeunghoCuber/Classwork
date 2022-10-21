#include <stdio.h>
#include <cs50.h>
#include <string.h>

/*

1. get user input
2. get the length of each numbers from conversion functions and store in variables
3. in each conversion function, keep dividing number by the base until "n" is 0
    i. store each digit in the array
    ii. keep track of how many digits there are
4. print digits in the opposite order using the length
5. ask user to repeat

*/


int binary[100], octal[100], hex[100]; //array that stores digits of each number
char alph[6] = {'A', 'B', 'C', 'D', 'E', 'F'}; //array for hex characters

int to_binary(int n);
int to_octal(int n);
int to_hex(int n);
string ask_repeat();

int main() {
    //string for asking user if they want to repeat
    string repeat = "";

    //while loop for asking converting multiple numbers
    do {
        int n = get_int("Please enter a decimal number: ");

        //get the length of the binary number + convert to binary
        int count_b = to_binary(n);

        //get the length of the octal number + convert to octal
        int count_o = to_octal(n);

        //get the length of the hex number + convert to hex
        int count_h = to_hex(n);

        //print the binary number in a reverse order
        printf("Binary: ");
        for (int i = count_b - 1; i >= 0; i--) {
            printf("%d", binary[i]);
        }
        printf("\n");

        //print the octal number in a reverse order
        printf("Octal: ");
        for (int i = count_o - 1; i >= 0; i--) {
            printf("%d", octal[i]);
        }
        printf("\n");

        //print the binary number in a reverse order
        printf("Hex: ");
        for (int i = count_h - 1; i >= 0; i--) {
            if (hex[i] > 9) {
                //if the hex digit is greater than 9, convert to an alphabet and print
                printf("%c", alph[hex[i] - 10]);
            }else {
                printf("%d", hex[i]);
            }
        }
        printf("\n");

        //ask user if they want to repeat
        repeat = ask_repeat();

    } while (!strcmp(repeat, "yes"));
}

int to_binary(int n) {
    int count = 0;
    while (n > 0) { //keep dividing n by 2 until n == 0
        //store each digit in the array + update count
        binary[count++] = n % 2;
        n /= 2;
    }
    return count;
}

int to_octal(int n) {
    int count = 0;
    while (n > 0) { //keep dividing n by 2 until n == 0
        //store each digit in the array + update count
        octal[count++] = n % 8;
        n /= 8;
    }
    return count;
}

int to_hex(int n) {
    int count = 0;
    while (n > 0) { //keep dividing n by 2 until n == 0
        //store each digit in the array + update count
        hex[count++] = n % 16;
        n /= 16;
    }
    return count;
}

string ask_repeat() {
    string repeat;
    do {
        repeat = get_string("Would you like to convert again? (yes or no) ");
    } while (strcmp(repeat, "yes") && strcmp(repeat, "no"));
    return repeat;
}
