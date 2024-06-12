# Tic-Tac-Toe-game

Project Overview


This project is a simple implementation of the classic Tic Tac Toe game using Qt for the graphical user interface. The game allows two players to take turns marking spaces in a 3x3 grid, with the goal of placing three of their marks in a horizontal, vertical, or diagonal row. The application includes features such as a current player display and a restart button to reset the game.

# Instructions to Compile and Run the Program

# Prerequisites

Qt 5 or later
Qt Creator (optional, but recommended for easy development)


# Steps to Compile and Run

Clone the Repository

git clone <repository-url>

cd Tic-Tac-Toe

# Open the Project in Qt Creator

Launch Qt Creator.

Open the tic-tac-toe.pro file.

# Build the Project

Click on the "Build" button or press Ctrl+B.

# Run the Project

Click on the "Run" button or press Ctrl+R.



# Description of the Game Rules
Objective:  The goal is to be the first player to get three of your marks in a row (horizontally, vertically, or diagonally).

Players: The game is played by two players. One player uses "X" and the other uses "O".

Gameplay: Players take turns placing their marks in empty squares.
The current player is indicated at the bottom of the window.
The game continues until one player has three marks in a row or all squares are filled.
Winning the Game: A player wins by placing three of their marks in a horizontal, vertical, or diagonal row.

Draw: The game is a draw if all squares are filled and neither player has three in a row.

Restart: Players can restart the game at any time by clicking the "Restart" button.

# Additional Notes or Known Issues
UI Scaling: The UI is designed to be responsive, but scaling issues might occur on very high-resolution displays.


Concurrency: The game currently does not handle simultaneous clicks gracefully. It is designed for sequential turns.


Code Modularity: The current implementation focuses on simplicity and readability. Further refactoring might be needed for larger or more complex games.

Error Handling: Basic input validation is in place, but more extensive error handling and user feedback could be added.

Feel free to contribute to the project by opening issues or submitting pull requests to address any bugs or enhance functionality.
