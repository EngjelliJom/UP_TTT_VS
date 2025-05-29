
# Tic-Tac-Toe (C++) Console Game

This is a simple implementation of the classic **Tic-Tac-Toe** game written in **C++**. Two players take turns marking spaces on a 3×3 grid, attempting to get three of their marks in a row—horizontally, vertically, or diagonally—before the other.

## Features

- Two-player mode (no AI)
- Turn-based gameplay
- Input validation
- Win detection (rows, columns, diagonals)
- Draw detection (when board is full with no winner)
- Console display of the game board after every move

---

## How to Compile and Run

To compile the code using `g++`, run:

```bash
g++ -o tic_tac_toe tic_tac_toe.cpp
./tic_tac_toe
```

Make sure your compiler supports C++11 or later.

---

## How to Play

1. The game starts automatically when run.
2. The board is displayed in the console. It is a 3x3 grid indexed from `0` to `2` for both rows and columns.
3. Players take turns. Player `X` always starts first, followed by Player `O`.
4. When prompted, enter your move as two integers separated by a space — the **row** and **column** where you want to place your mark.
   - Example: `1 2` means row 1, column 2.
5. If a player tries to move to an occupied or out-of-bounds space, the move is rejected and the same player is asked to try again.
6. After each move, the board is updated and displayed.
7. The game ends when:
   - One player gets **three marks in a row** (horizontal, vertical, or diagonal).
   - All spaces are filled without a winner (draw).

---

## Game Layout Example

The board starts empty:

```
 | | 
-----
 | | 
-----
 | | 
```

After a few moves:

```
X|O| 
-----
 |X| 
-----
 | |O
```

If Player `X` makes a line across, down, or diagonally, a message like this will display:

```
Player X wins!
```

If the board fills without a winner:

```
It's a draw!
```

---

## Code Overview

### Class: `TicTacToe`

#### Private Members:
- `vector<vector<char>> board`  
  Represents the 3×3 game board initialized with spaces `' '`.

- `char currentPlayer`  
  Keeps track of whose turn it is: `'X'` or `'O'`.

#### Public Methods:

- `TicTacToe()`  
  Constructor that initializes the board and sets the starting player to `'X'`.

- `void displayBoard()`  
  Displays the current state of the board in the console.

- `bool placeMark(int row, int col)`  
  Attempts to place the current player's mark at the given position. Returns `false` if invalid.

- `bool checkWin()`  
  Checks if the current player has a winning combination on the board.

- `void switchPlayer()`  
  Changes the current player from `'X'` to `'O'` or vice versa.

- `void playGame()`  
  Main game loop that handles turns, input, win/draw logic, and displays the final result.

### `main()`

Creates a `TicTacToe` object and starts the game.

---

## Input Notes

- Input is taken via `std::cin`.
- Always enter valid integers between `0` and `2` for rows and columns.
- Invalid inputs (out of bounds or occupied cells) will prompt the same player to try again.

---

## Example Gameplay (Sample Session)

```
Current Board:
 | | 
-----
 | | 
-----
 | | 
Player X, enter your move (row and column): 0 0

Current Board:
X| | 
-----
 | | 
-----
 | | 
Player O, enter your move (row and column): 1 1

Current Board:
X| | 
-----
 |O| 
-----
 | | 
Player X, enter your move (row and column): 0 1

... (game continues)

Player X wins!
```

---

## Customization Ideas

- Add a score counter for multiple rounds.
- Allow players to enter names.
- Add an AI opponent using minimax algorithm.
- Make the board size dynamic (e.g., 4x4 or NxN).

---

## License

This code is open source and free to use for educational or personal projects :) 
