#include <iostream>
using namespace std;

const int boardSize = 7;
char board[boardSize][boardSize];

struct Player {
    string name;
    int shots;
};

void initializeBoard() {
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardSize; ++j)
            board[i][j] = ' ';
    board[1][1] = board[1][2] = board[1][3] = 'S';
    board[3][3] = board[3][4] = 'S';
    board[5][5] = 'S';
}

void printBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ';
}

bool isGameOver() {
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardSize; ++j)
            if (board[i][j] == 'S')
                return false;
    return true;
}

void playGame(const string& playerName) {
    initializeBoard();
    int shots = 0;
    while (!isGameOver()) {
        int row, col;
        cout << playerName << ", enter your guess (row, col): ";
        cin >> row >> col;

        if (!isValidMove(row, col)) {
            cout << "Hit! Continue..." << endl;
            continue;
        }
        cout << (board[row][col] == 'S' ? "Hit!" : "Miss!") << endl;
        board[row][col] = (board[row][col] == 'S' ? 'X' : 'O');
        printBoard();
        shots++;
    }

    cout << "Congratulations, " << playerName << "! You sank all the ships in " << shots << " shots." << endl;
}

int main() {
    Player player;
    cout << "Enter your name: ";
    cin >> player.name;

    playGame(player.name);

    return 0;
}