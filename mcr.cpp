#include <iostream>
using namespace std;

bool isWin(char game[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && (game[i][0] == 'X' || game[i][0] == 'O')) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (game[0][j] == game[1][j] && game[1][j] == game[2][j] && (game[0][j] == 'X' || game[0][j] == 'O')) {
            return true;
        }
    }
    // Check diagonals
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) ||
        (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O'))) {
        return true;
    }
    return false;
} 

int main() {
    int i, j;  
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Initialize Tic-tac-toe
    char player1 = 'X'; 
    char player2 = 'O'; 
    bool turn = false; // false for player 1's turn, true for player 2's turn. Player 1 first.
    cout << "X = Player 1" << endl << "O = Player 2" << endl;

    for (int n = 0; n < 9; n++) {
        cout << "Current board:" << endl;
        cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
        cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
        cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;

        if (turn == false) 
            cout << "Player 1 (X): "; 
        else
            cout << "Player 2 (O): "; 
        cout << "Which cell to mark? i:[1..3], j:[1..3]: "; 
        cin >> i >> j;

        // Adjust for 0-based index
        i--; 
        j--; 

        // Check for valid input
        if (i < 0 || i > 2 || j < 0 || j > 2 || game[i][j] != ' ') {
            cout << "Invalid move, try again." << endl;
            n--; // Do not count this as a turn
            continue;
        }

        game[i][j] = turn ? player2 : player1; // Mark the cell

        if (isWin(game)) {
            cout << "Current board:" << endl;
            cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
            cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
            cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
            cout << "Player " << (turn ? "2 (O)" : "1 (X)") << " wins!" << endl;
            return 0; // End the game
        } 

        turn = !turn; // Switch turns
    }

    // If all cells are filled and no winner
    cout << "It's a tie!" << endl;
    return 0; 
}

//1. The game board is initialized properly to ensure all cells are empty
//2.Added checks to ensure that players cannot overwrite cells or select invalid indices.
//3.Winning Condition Check
