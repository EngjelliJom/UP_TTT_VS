#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    string playerXName, playerOName;
    int scoreX, scoreO, draws;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        scoreX = scoreO = draws = 0;
    }

    void getPlayerNames() {
        cout << "Enter name for Player X: ";
        getline(cin, playerXName);
        cout << "Enter name for Player O: ";
        getline(cin, playerOName);
    }

    void resetBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "Current Board:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----" << endl;
        }
    }

    bool placeMark(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    string getCurrentPlayerName() {
        return (currentPlayer == 'X') ? playerXName : playerOName;
    }

    void updateScore(char winner) {
        if (winner == 'X') scoreX++;
        else if (winner == 'O') scoreO++;
        else draws++;
    }

    void displayScores() {
        cout << "\nScoreboard:" << endl;
        cout << playerXName << " (X): " << scoreX << endl;
        cout << playerOName << " (O): " << scoreO << endl;
        cout << "Draws: " << draws << endl;
    }

    void playGame() {
        getPlayerNames();
        char playAgain = 'y';

        while (playAgain == 'y' || playAgain == 'Y') {
            resetBoard();
            int row, col;
            bool gameEnded = false;

            for (int turn = 0; turn < 9; turn++) {
                displayBoard();
                cout << getCurrentPlayerName() << " (" << currentPlayer << "), enter your move (row and column): ";
                cin >> row >> col;

                if (placeMark(row, col)) {
                    if (checkWin()) {
                        displayBoard();
                        cout << getCurrentPlayerName() << " (" << currentPlayer << ") wins!" << endl;
                        updateScore(currentPlayer);
                        gameEnded = true;
                        break;
                    }
                    switchPlayer();
                } else {
                    turn--; // Retry turn on invalid input
                }
            }

            if (!gameEnded) {
                displayBoard();
                cout << "It's a draw!" << endl;
                updateScore('D');
            }

            displayScores();
            cout << "\nDo you want to play again? (y/n): ";
            cin >> playAgain;
            cin.ignore(); // consume newline character
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
