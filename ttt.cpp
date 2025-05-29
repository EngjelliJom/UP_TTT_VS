#include <iostream>
#include <vector>
#include <stdexcept>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        std::cout << "Current Board:\n";
        for (const auto& row : board) {
            for (const auto& cell : row) {
                std::cout << cell << " | ";
            }
            std::cout << "\n---------\n";
        }
    }

    void makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            throw std::out_of_range("Move out of bounds. Please choose a valid position.");
        }
        if (board[row][col] != ' ') {
            throw std::invalid_argument("Cell already taken. Please choose another cell.");
        }
        board[row][col] = currentPlayer;
    }

    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
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

    void playGame() {
        int row, col;
        for (int turn = 0; turn < 9; ++turn) {
            printBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            try {
                makeMove(row, col);
                if (checkWin()) {
                    printBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    return;
                }
                switchPlayer();
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                --turn; // Do not count this turn
            }
        }
        printBoard();
        std::cout << "It's a draw!\n";
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}