This game was created by Rahmatova Leyla.
Battleship Game Instructions:

Game Rules:
1. Objective: Sink all the ships on the board.
2. Ships: There are a total of 7 ships on the board:
   - One ship of length 3.
   - Two ships of length 2.
   - Four ships of length 1.
3. Gameplay:
   - You will be prompted to enter your guess in the format (row, col) where both row and col are integers.
   - After each guess, the board will be displayed showing hits ('X'), misses ('*'), and empty spaces ('.').
   - The game will inform you if your guess is a hit or a miss.
4. Hit:
   - If your guess hits a ship, the board will display "Hit!" and mark the hit with 'X'.
   - The number of ship hits will be tracked.
   - If you sink all ships, the game will end, and you will be declared the winner.
5. Miss:
   - If your guess misses a ship, the board will display "Miss!" and mark the miss with '*'.
   - Total shots taken will be tracked.
6. Invalid Moves:
   - If you enter an invalid move (e.g., a move outside the board or a move already guessed), you will be prompted to enter a new guess.
7. Game Over:
   - The game ends when all ships are sunk.
   - The final board will be displayed.
   - Your total shots taken will be shown.

Note:
- The delay after each move is for visual effect and can be adjusted by modifying the `this_thread::sleep_for` duration in the code.
