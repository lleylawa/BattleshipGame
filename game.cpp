#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <chrono> 
#include <thread> 
 
using namespace std; 
 
const int boardSize = 6; 
char board[boardSize][boardSize]; 
int shipHits = 0; 
int totalShots = 0; 
 
struct Player { 
    string name; 
    int shots; 
}; 
 
void initializeBoard() { 
    srand(time(0)); 
    for (int i = 0; i < boardSize; ++i) 
        for (int j = 0; j < boardSize; ++j) 
            board[i][j] = ' '; 
 
    int x, y; 
 
    // Place a ship of length 3 
    x = rand() % (boardSize - 2); 
    y = rand() % boardSize; 
    for (int i = 0; i < 3; i++) 
        board[x + i][y] = 'S'; 
 
    // Place two ships of length 2 
    for (int i = 0; i < 2; i++) { 
        x = rand() % boardSize; 
        y = rand() % (boardSize - 1); 
        for (int j = 0; j < 2; j++) 
            board[x][y + j] = 'S'; 
    } 
 
    // Place four ships of length 1 
    for (int i = 0; i < 4; i++) { 
        do { 
            x = rand() % boardSize; 
            y = rand() % boardSize; 
        } while (board[x][y] == 'S'); 
        board[x][y] = 'S'; 
    } 
} 
 
void printBoard() { 
    cout << "  "; 
    for (int j = 0; j < boardSize; ++j) 
        cout << j << ' '; 
    cout << endl; 
 
    for (int i = 0; i < boardSize; ++i) { 
        cout << i << ' '; 
        for (int j = 0; j < boardSize; ++j) 
            cout << (board[i][j] == 'X' ? 'X' : (board[i][j] == '*' ? '*' : '.')) << ' '; 
        cout << endl; 
    } 
} 
 
bool isValidMove(int row, int col) { 
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] != '*' && board[row][col] != 'X'; 
} 
 
bool isGameOver() { 
    return shipHits == 11; 
} 
 
void clearScreen() { 
    cout << "\033[2J\033[H"; 
} 
 
void playGame(const string& playerName) { 
    initializeBoard(); 
 
    while (!isGameOver()) { 
        int row, col; 
        clearScreen(); 
        printBoard(); 
 
        cout << playerName << ", enter your guess (row, col): "; 
        cin >> row >> col; 
        totalShots++; 
 
        while (!isValidMove(row, col)) { 
            cout << "Invalid move! Please enter a new guess (row, col): "; 
            cin >> row >> col; 
            totalShots++; 
        } 
 
        if (board[row][col] == 'S') { 
            cout << "Hit!" << endl; 
            board[row][col] = 'X'; 
            shipHits++; 
 
            if (shipHits == 11) { 
                clearScreen(); 
                printBoard(); 
                cout << "Sunk!" << endl; 
                this_thread::sleep_for(chrono::milliseconds(400)); 
            } 
            else { 
                this_thread::sleep_for(chrono::milliseconds(400)); 
            } 
        } 
        else { 
            cout << "Miss!" << endl; 
            board[row][col] = '*'; 
            this_thread::sleep_for(chrono::milliseconds(400)); 
        } 
    } 
 
    cout << "Congratulations, " << playerName << "! You sank all the ships. Total shots: " << totalShots << endl; 
} 
 
int main() { 
    vector<Player> players; 
 
    do { 
        string playerName; 
        cout << "Enter your name: "; 
        cin >> playerName; 
        playGame(playerName); 
 
        Player currentPlayer = {playerName, totalShots}; 
        players.push_back(currentPlayer); 
 
        shipHits = 0; 
        totalShots = 0; 
 
    } while (true); 
    return 0; 
}
