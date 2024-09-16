
#include <iostream>
using namespace std;

bool isWin(char game[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if ((game[i][0] == game[i][1] && game[i][1] == game[i][2]) && 
            (game[i][0] == 'X' || game[i][0] == 'O')) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if ((game[0][j] == game[1][j] && game[1][j] == game[2][j]) && 
            (game[0][j] == 'X' || game[0][j] == 'O')) {
            return true;
        }
    }
    
    // Check diagonals
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) &&
        (game[0][0] == 'X' || game[0][0] == 'O')) {
        return true;
    }
    if ((game[0][2] == game[1][1] && game[1][1] == game[2][0]) &&
        (game[0][2] == 'X' || game[0][2] == 'O')) {
        return true;
    }
    
    return false;
}

int main() {
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = 'O';
    bool turn = false; // false for player 1 (X), true for player 2 (O)

    cout << "X = Player 1" << endl << "O = Player 2" << endl;

    for (int n = 0; n < 9; n++) {
        int i, j;
        if (turn == false) {
            cout << "Player 1 (X): ";
        } else {
            cout << "Player 2 (O): ";
        }
        cout << "Choose a cell to mark (i:[1..3], j:[1..3]): ";
        cin >> i >> j;
        i--; // Adjust for 0-based index
        j--; // Adjust for 0-based index

        // Check if the cell is already marked
        if (game[i][j] != ' ') {
            cout << "Cell already marked, try again." << endl;
            n--; // Does not count this round
            continue;
        }

        game[i][j] = turn ? player2 : player1;

        // Check if there's a winner
        if (isWin(game)) {
            cout << (turn ? "Player 2 (O) wins!" : "Player 1 (X) wins!") << endl;
            break; // End the game
        }

        // Check for a draw
        if (n == 8) {
            cout << "Draw!" << endl;
        }

        // Display the current game board
        for (int row = 0; row < 3; row++) {
            cout << game[row][0] << "|" << game[row][1] << "|" << game[row][2] << endl;
            if (row < 2) cout << "-----" << endl; // Separator line
        }

        // Switch turns
        turn = !turn;
    }
    return 0;
}

//Final result
