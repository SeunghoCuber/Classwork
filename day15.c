#include <cs50.h>
#include <stdio.h>

int get_size();
void get_array(int size);
void print_array(int size, int arr[]);
void get_avg(int size, int arr[]);

int main(void) {
    int size = get_size();
    printf("Size: %d\n", size);
    get_array(size);
}

//function to get the size of the array
int get_size() {
    int n;
    do {
        n = get_int("How many numbers? ");
    } while (n < 0 || n > 1000);
    return n;
}

//function to get array elements
void get_array(int size) {
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = get_int("Please enter a number: ");
    }
    print_array(size, arr);
    get_avg(size, arr);
}

//function to print all elements in the array
void print_array(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

//function to get average value of all elements
void get_avg(int size, int arr[]) {
    float avg = 0;
    for (int i = 0; i < size; i++) {
        avg += arr[i];
    }
    avg = avg/size;
    printf("Average: %.2f\n", avg);
}
