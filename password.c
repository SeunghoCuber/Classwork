#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool verify(string p);

/*



*/

int main() {
    string password;
    bool rep = 1;

    do {
        password = get_string("Enter your password: ");

        if (verify(password)) {
            printf("Your password is valid!\n");
            rep = 0;
        }else {
            printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
        }
    } while (rep);
}

bool verify(string p) {
    int length = (int)strlen(p);

    int symbol = 0, upper = 0, lower = 0, number = 0;

    for (int i = 0; i < length; i++) {
        int ascii = (int)p[i];
        if (isupper(ascii)) {
            upper++;
        }else if (islower(ascii)) {
            lower++;
        }else if (isdigit(ascii)) {
            number++;
        }else if (33 <= ascii && ascii <= 126) {
            symbol++;
        }
    }

    return upper && lower && symbol && number;
}
