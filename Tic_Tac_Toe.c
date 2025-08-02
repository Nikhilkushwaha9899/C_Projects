#include <stdio.h>

char board[3][3];

// Initialize the board with numbers 1-9
void initBoard() {
    char c = '1';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = c++;
}

// Display the board
void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Check if a player has won
int checkWin() {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Check if the board is full (draw)
int checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

int main() {
    int player = 1;
    int choice;
    int row, col;

    initBoard();

    while(1) {
        displayBoard();
        printf("Player %d, enter the number of the cell where you want to place %c: ", player, (player == 1) ? 'X' : 'O');
        scanf("%d", &choice);

        if(choice < 1 || choice > 9) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already taken! Try again.\n");
            continue;
        }

        board[row][col] = (player == 1) ? 'X' : 'O';

        if(checkWin()) {
            displayBoard();
            printf("Player %d wins! Congratulations!\n", player);
            break;
        }

        if(checkDraw()) {
            displayBoard();
            printf("Game is a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
