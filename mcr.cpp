

#include <iostream>
using namespace std;

bool isWin(char game[3][3]) {
    bool win = false; 
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true; 
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true; 
    // column
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true; 
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true; 
    // diagonal 
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true; 
    return win;
} 

int main() {
    int i, j;  
    char game[3][3] = {' '}; // Tic-tac-toe
    char player1 = 'X'; 
    char player2 = 'O'; 
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    cout << "X = Player 1" << endl << "O = Player 2" << endl;
    for (int n = 0; n < 9; n++) {
        turn = !turn; // use the not-operator to change true to false or false to true.
        if (turn == false) 
            cout << "Player 1: "; 
        else
            cout << "Player 2: "; 
        cout << "Which cell to mark? i:[1..3], j:[1..3]: "; 
        cin >> i >> j;
        i--; // Adjust for 0-based index
        j--; // Adjust for 0-based index

        if (turn == false) 
            game[i][j] = 'X';
        else 
            game[i][j] = 'O'; 

        if (isWin(game)) {
            cout << "Win!" << endl;
            break; // need to terminate the problem
        } 
    } 
    if (i == 3) // all celles with i=0 to 2 have been inputted above but no winner yet
        cout << "Tie!" << endl;

    // show the game to console
    cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
    cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
    cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
    return 0; 
}

//未检查输入有效性：在输入 i 和 j 后，没有检查这些输入是否在合法范围内（0到2），也没有检查该单元格是否已被占用。需要在进行标记之前添加有效性检查
