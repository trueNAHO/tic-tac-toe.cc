# Tic Tac Toe

This minimalistic version of Tic Tac Toe was created with the sole intention to try out C++ and get used to it. It can have any number of players and the field size is also variable. The game can restart itself, without having to restart the application itself. This mini-game makes use of pointers, classes and simple templates I created. It also tries to handle possible errors the user input could provoke. The code is also mostly refactored.

The `main` file was compiled on my personal laptop. Feel free to clone this repo and compile it yourself.

Here is an example:
```
Enter number of players: 3

Player #1 enter your name: Player_1
Player #1 enter your sign: A

Player #2 enter your name: Player_2
Player #2 enter your sign: B

Player #3 enter your name: Player_3
Player #3 enter your sign: C

Enter in space seperated formated the number of rows and columns for the board: 2 4
---------
| | | | |
---------
| | | | |
---------

>>> Player_1's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 1 1
---------
|A| | | |
---------
| | | | |
---------

>>> Player_2's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 2 2
---------
|A| | | |
---------
| |B| | |
---------

>>> Player_3's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 3 3
[#1] Invalid rows or columns index. Try again: 0 0
[#2] Invalid rows or columns index. Try again: 1 1
[#3] Field already occupied by 'Player_1'. Try again.
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 2 2
[#4] Field already occupied by 'Player_2'. Try again.
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 21
1
[#5] Invalid rows or columns index. Try again: 2 1
---------
|A| | | |
---------
|C|B| | |
---------

>>> Player_1's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 1 2
---------
|A|A| | |
---------
|C|B| | |
---------

>>> Player_2's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 2 3
---------
|A|A| | |
---------
|C|B|B| |
---------

>>> Player_3's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 2 4
---------
|A|A| | |
---------
|C|B|B|C|
---------

>>> Player_1's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 1 3
---------
|A|A|A| |
---------
|C|B|B|C|
---------

>>> Player_2's turn
Enter rows (1 to 2) and colums (1 to 4) position in space seperated format: 1 4
---------
|A|A|A|B|
---------
|C|B|B|C|
---------

>>> DRAW

Play again? [y/n] n
```
