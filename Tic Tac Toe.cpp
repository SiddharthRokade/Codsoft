#include <iostream>
using namespace std;


void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char switchPlayer(char currentPlayer) {
    if (currentPlayer == 'X') {
        return 'O';
    }
    else {
        return 'X';
    }
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    bool gameOver = false;
    int row, col;

    while (!gameOver) {
    
        displayBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        if (board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;
        }
        else {
            cout << "That space is already taken. Try again." << endl;
            continue;
        }

        
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
       
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw." << endl;
            gameOver = true;
        }
        
        else {
            currentPlayer = switchPlayer(currentPlayer);
        }
    }


    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    }

    return 0;
}
