#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NEAR_RANGE 3

int checkGuess(int guessNumber, int correctNumber) {
    if (guessNumber == correctNumber) {
        printf("Correct Guessed: %d\n", correctNumber);
        return 1;
    }
    if (guessNumber > correctNumber) {
        printf(guessNumber - correctNumber <= NEAR_RANGE ? "High but Near.\n" : "Too High.\n");
    } else {
        printf(correctNumber - guessNumber <= NEAR_RANGE ? "Low but Near.\n" : "Too Low.\n");
    }
    return 0;
}

void playGame(int correctGuess) {
    int guess;
    int tries = 0;
    const int maxTries = 7;
    while (tries < maxTries) {
        printf("Try %d/%d. Enter your guess: ", tries + 1, maxTries);

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        tries++;
        if (checkGuess(guess, correctGuess)) {
            printf("You won in %d tries!\n", tries);
            return;
        }
    }
    printf("Game Over! The number was %d.\n", correctGuess);
}


int main(void) {
    srand(time(NULL));
    char choice;

    do {
        int max;
        do {
            printf("Enter Maximum Length of Guess (must be > 1): ");
            if (scanf("%d", &max) != 1 || max <= 1) {
            printf("Invalid Input.\n");
            while (getchar() != '\n');
            }
        } while (max <= 1);
        

        int correctGuess = rand() % max + 1;
        playGame(correctGuess);

        printf("\nWould you like to play again? (y/n): ");
        while (getchar() != '\n'); 
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");
    

    return 0;
}