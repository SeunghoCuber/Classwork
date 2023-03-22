#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>

//a structure to handle the scoreboard sorting
struct pair {
    int first;
    int second;
};

//making this variable true allows you to see the word
const bool DEV = false;

const int TURNS = 10;
const int EASY_COUNT = 7;
const int HARD_COUNT = 7;
int score_mult;

//arrays to choose the words
string easy[] = {"hello", "chair", "table", "phone", "zebra", "pencil", "night"};
string hard[] = {"projector", "processor", "copyright", "passport", "difficult", "computation", "illumination"};

string menu();
bool in_word(string w, string s, char a);
void update_word(string w, char *s, char a);
void print_score();
void sort(struct pair arr[], int n);

//main function to deal with looping the game and menu process
int main() {
    srand(time(NULL));
    bool exit = false;
    int score = 0;

    //if the user does not exit, continue giving menu option
    while (!exit) {
        string word = menu();

        //if the user doesn't choose the playing options, skip it
        if (!strcmp(word, "exit")) exit = true;
        if (!strcmp(word, "exit") || !strcmp(word, "instruct")) continue;

        char show_user[strlen(word)+1];
        for (int i = 0; i < strlen(word); i++) show_user[i] = '_';
        show_user[strlen(word)] = '\0';

        int turn = TURNS;

        //the loop where player guesses the word
        while (turn && strcmp(word, show_user)) {
            printf("Turn: %d\n", turn);
            char alph = get_char("Enter your guess: ");
            while (!isalpha(alph)) {
                alph = get_char("Please enter an alphabet: ");
            }
            if (in_word(word, show_user, alph)) {
                update_word(word, show_user, alph);
            }else {
                turn--;
            }
            printf("%s\n", show_user);
        }
        if (!strcmp(word, show_user)) {
            printf("You win!\n");
            //calculate the score
            score += strlen(word) * score_mult;
        }else {
            printf("You lose\n");
        }
    }

    //upon exiting, save the user in the scoreboard
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //open the file
    FILE *file = fopen("score.txt", "a");

    //print out the score
    printf("Your score: %d\n", score);

    //save date into a string
    int d = tm.tm_mon*1000000 + tm.tm_mday*10000 + tm.tm_hour*100 + tm.tm_min;
    char date[8];
    sprintf(date, "%d", d);
    printf("Date: %s\n", date);

    //ask for user name
    string user_name = get_string("Please enter your name: ");

    //convert score into string
    char result[10];
    sprintf(result, "%d", score);

    //save by separating with "\t" and end with "\n"
    char save[100];
    strcpy(save, result);
    strcat(save, "\t");
    strcat(save, user_name);
    strcat(save, "\t");
    strcat(save, date);
    strcat(save, "\n\0");

    //Save the variable into score.txt file
    if (score > 0) {
        fwrite(&save, strlen(save), 1, file);
        printf("Saved: %s", save);
    }else {
        printf("Error: Must have score greater than 0 to save");
    }

    //close the file
    fclose(file);
}

//function to handle user menu
string menu() {
    printf("___________________\n");
    printf("|1. Intructions    |\n");
    printf("|2. Easy           |\n");
    printf("|3. Hard           |\n");
    printf("|4. Scoreboard     |\n");
    printf("|5. Exit           |\n");
    printf("|__________________|\n");

    string ret = "";

    int mode = get_int("Enter your command: ");
    while (mode < 1 || mode > 5) {
        mode = get_int("Please enter a number 1-5: ");
    }

    if (mode == 1) {
        printf("Every turn, enter an alphabet, guess in %d turns\n", TURNS);
        ret = "instruct";
    }else if (mode == 2) {
        ret = easy[rand() % EASY_COUNT];
        score_mult = 10;
    }else if (mode == 3) {
        ret = hard[rand() % HARD_COUNT];
        score_mult = 20;
    }else if (mode == 4) {
        ret = "instruct";
        print_score();
    }else {
        ret = "exit";
    }
    if (DEV) printf("word = %s\n", ret);
    return ret;
}

//function to check if the guessed letter is in the word
bool in_word(string w, string s, char a) {
    for (int i = 0; i < strlen(w); i++) {
        if (w[i] == a) {
            if (s[i] == a) {
                printf("Already used!\n");
                return false;
            }
            printf("Correct!\n");
            return true;
        }
    }
    printf("Incorrect\n");
    return false;
}

//function to keep track of what letters users have guessed
void update_word(string w, char *s, char a) {
    for (int i = 0; i < strlen(w); i++) {
        if (w[i] == a) {
            s[i] = a;
        }
    }
}

//function to print the scoreboard
void print_score() {
    //now read all of the scores and create a top 5 list
    FILE *file = fopen("score.txt", "r");

    struct pair p[100];
    char name_arr[100][20];

    int char_count = 0, word_count = 0, line_count = 0, user_score= 0;
    char user_name[20];
    uint8_t buffer;
    char str[20];
    while (fread(&buffer, sizeof(uint8_t), 1, file)) {
        if (buffer == '\t') {
            str[char_count++] = '\0';
            if (word_count == 0) {
                user_score = atoi(str);
            }else {
                strncpy(user_name, str, 20);
            }
            word_count++;
            char_count = 0;
            for (int i = 0; i < 20; i++) str[i] = ' ';
        }else if (buffer == '\n') {
            str[char_count++] = '\0';
            word_count = 0;

            for (int i = 0; i < 20; i++) str[i] = ' ';
            char_count = 0;

            strncpy(name_arr[line_count], user_name, 20);

            struct pair np = {.first = user_score, .second = line_count};
            p[line_count++] = np;
        }else {
            str[char_count++] = (char)buffer;
        }
    }

    sort(p, line_count);

    printf("----------SCORE BOARD----------\n");

    for (int i = 0; i < 3 && i < line_count; i++) {
        printf("#%d:\t%d\t%s\n", i+1, p[i].first, name_arr[p[i].second]);
    }

    fclose(file);
}

//function to sort the scoreboard (bubble sort)
void sort(struct pair arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].first < arr[j + 1].first) {
                struct pair tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
