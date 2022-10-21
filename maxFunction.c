#include <stdio.h>
#include <cs50.h>

/*
1. ask user for name, age, hourly pay
2. print it
*/

string name;
int age;
float hourly;

void printName(string n, int a, float p);

int main(void) {
    //ask user for name, age, and salary
    name = get_string("Please enter your name: ");
    age = get_int("Please enter your age: ");
    hourly = get_float("Please enter your hourly wage: ");

    //print the user input
    printName(name, age, hourly);
    return 0;
}

//print the user input
void printName(string n, int a, float p) {
    printf("You are %s, %d year old, and make $%.2f hourly\n", n, a, p);
}
