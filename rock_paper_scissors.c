#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const char* getChoiceName(int choice) {
    switch (choice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "Invalid";
    }
}


void determineWinner(int user, int computer) {
    if (user == computer) {
        printf("It's a draw!\n");
    } else if ((user == 0 && computer == 2) ||
               (user == 1 && computer == 0) ||
               (user == 2 && computer == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}


void clearBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    int userChoice, computerChoice;
    char playAgain;

    srand(time(NULL)); 

    do {
        printf("\n===== Rock, Paper, Scissors =====\n");
        printf("0: Rock\n1: Paper\n2: Scissors\n");
        printf("Enter your choice (0-2): ");

        if (scanf("%d", &userChoice) != 1 || userChoice < 0 || userChoice > 2) {
            printf("Invalid input. Please enter 0, 1, or 2.\n");
            clearBuffer();
            continue;
        }

        computerChoice = rand() % 3;

        printf("You chose: %s\n", getChoiceName(userChoice));
        printf("Computer chose: %s\n", getChoiceName(computerChoice));
        determineWinner(userChoice, computerChoice);

        clearBuffer();  
        printf("Play again? (y/n): ");
        scanf("%c", &playAgain);
        clearBuffer();  

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
