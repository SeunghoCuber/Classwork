#include <stdio.h>
#include <cs50.h>

/*

Seungho Lee
Restaurant Code

1. ask user for bill, tax, tip, and # of ppl
2. change tax and tip from percentage to amount of money using (percent_to_money) function
3. calculate total after tax and tip
4. print all the bills using another function (print_total)

*/

float get_total(float bill, float tax, float tip);
void print_total(float bill, float tax, float tip, float ppl, float tot);

int main() {
    float bill, tax, tip, ppl, tot;

    bill = get_float("Please enter the bill amount: ");
    tax = get_float("Please enter the tax percentage: ");
    tip = get_float("Please enter the tip percentage: ");
    ppl = get_float("Please enter the number of people: ");

    tax = percent_to_money(bill, tax);
    tip = percent_to_money(bill, tip);

    tot = bill + tax + (float)tip;

    print_total(bill, tax, tip, ppl, tot);
}

float percent_to_money(float bill, float percent) {
    return (bill * percent / 100.0);
}

void print_total(float bill, float tax, float tip, float ppl, float tot) {
    printf("\n-------------TOTAL BILL-------------\n");
    printf("BILL--------------------------$%.2f\n", bill);
    printf("TAX---------------------------$%.2f\n", tax);
    printf("TIP---------------------------$%.2f\n", tip);
    printf("TOTAL-------------------------$%.2f\n", tot);
    printf("Per Person--------------------$%.2f\n\n", (tot/ppl));
}
