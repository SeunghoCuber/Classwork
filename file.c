#include <stdio.h>
int main() {
        FILE * fp;
        char c;
        printf("File Handling\n");
        //open a file
        fp = fopen("demo.txt", "w");
        //writing operation
        while ((c = getchar()) != EOF) {
            putc(c, fp);
        }
        //close file
        fclose(fp);
        printf("\nData Entered:\n");

        //reading
        fp = fopen("demo.txt", "r");
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        printf("\n");
        fclose(fp);

        //Printing line numbers
        fp = fopen("demo.txt", "r");
        char buff[255];
        c = getc(fp);
        int index = 0, l_count = 0;
        while (c != EOF ) {
            if (c != '\n'){
                buff[index++] = c;
            }else {
                buff[index] = '\0';
                printf ("%i: %s\n", ++l_count, buff);
                index = 0;
            }
            c = getc (fp);
        }
        fclose(fp);
        return 0;
    }
