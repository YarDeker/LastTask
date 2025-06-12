#include <stdio.h>
#include <stdlib.h> 

#define SIZE 3

char board[SIZE][SIZE];  

void initBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n  ");
    for (int i = 0; i < SIZE; i++) printf(" %d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("  ---+---+---\n");
    }
    printf("\n");
}

char checkWinner() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return board[i][0];

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return board[0][i];
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return board[0][0];

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

int isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    system("chcp 65001 > nul"); 
    char currentPlayer = 'X';
    int row, col;
    char winner;

    initBoard();

    while (1) {
        printBoard();
        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Try again.\n");
            clearInputBuffer();
            continue;
        }

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            printf("Invalid move. Cell is already taken or out of bounds.\n");
            continue;
        }

        board[row][col] = currentPlayer;
        winner = checkWinner();

        if (winner != ' ') {
            printBoard();
            printf("Player %c wins!\n", winner);
            break;
        } else if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
