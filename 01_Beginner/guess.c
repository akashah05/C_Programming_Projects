#include <stdio.h>

int main(void) {
    int correct_number = 5;
    int guess_number;

    printf("Enter a Guess Number: \n");
    if (scanf("%d", &guess_number) != 1) {
        printf("Invalid Input! Please Enter a Number only.");
    }

    int range = 3;
    if (guess_number == correct_number) {
        printf("Correct Guessed: %d\n", correct_number);
    } else if (guess_number > correct_number) {
        if (guess_number - correct_number <= range) {
            printf("High But Near.\n");
        } else {
            printf("Too High\n");
        }
    } else {
        if (correct_number - guess_number <= range) {
            printf("Low But Near.\n");
        } else {
            printf("Too Low\n");
        }
    }

    return 0;
}