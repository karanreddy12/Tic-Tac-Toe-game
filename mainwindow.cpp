// mainwindow.cpp
#include "mainwindow.h"
#include <QStatusBar>
#include <QGridLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initializeBoard();
    currentPlayer = "X";

    // Create and configure the label to display current player
    currentPlayerLabel = new QLabel("Current Player: " + currentPlayer);
    statusBar()->addWidget(currentPlayerLabel);

    // Create and configure the restart button
    restartButton = new QPushButton("Restart");
    statusBar()->addWidget(restartButton);
    connect(restartButton, &QPushButton::clicked, this, &MainWindow::restartGame);
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeBoard()
{
    QGridLayout *layout = new QGridLayout;
    for (int i = 0; i < 3; ++i) {
        QVector<QPushButton*> row;
        for (int j = 0; j < 3; ++j) {
            QPushButton *button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setFont(QFont("Arial", 20));
            row.append(button);
            layout->addWidget(button, i, j);
            connect(button, &QPushButton::clicked, this, &MainWindow::buttonClicked);
        }
        board.append(row);
    }
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::clearBoard()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j]->setText("");
            board[i][j]->setEnabled(true);
        }
    }
}

void MainWindow::buttonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        button->setText(currentPlayer);
        button->setEnabled(false);
        if (checkWin()) {
            QMessageBox::information(this, "Tic Tac Toe", "Player " + currentPlayer + " wins!");
            restartGame();
        } else if (checkDraw()) {
            QMessageBox::information(this, "Tic Tac Toe", "It's a draw!");
            restartGame();
        } else {
            currentPlayer = (currentPlayer == "X") ? "O" : "X";
            updateCurrentPlayerLabel();
        }
    }
}

void MainWindow::updateCurrentPlayerLabel()
{
    currentPlayerLabel->setText("Current Player: " + currentPlayer);
}

bool MainWindow::checkWin()
{
    for (int i = 0; i < 3; ++i) {
        if (board[i][0]->text() == currentPlayer &&
            board[i][1]->text() == currentPlayer &&
            board[i][2]->text() == currentPlayer) {
            return true; // Horizontal win
        }
        if (board[0][i]->text() == currentPlayer &&
            board[1][i]->text() == currentPlayer &&
            board[2][i]->text() == currentPlayer) {
            return true; // Vertical win
        }
    }
    if (board[0][0]->text() == currentPlayer &&
        board[1][1]->text() == currentPlayer &&
        board[2][2]->text() == currentPlayer) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2]->text() == currentPlayer &&
        board[1][1]->text() == currentPlayer &&
        board[2][0]->text() == currentPlayer) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool MainWindow::checkDraw()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j]->text().isEmpty()) {
                return false; // If any cell is empty, game is not draw
            }
        }
    }
    return true; // All cells filled and no winner, game is draw
}

void MainWindow::restartGame()
{
    clearBoard();
    currentPlayer = "X";
    updateCurrentPlayerLabel();
}
