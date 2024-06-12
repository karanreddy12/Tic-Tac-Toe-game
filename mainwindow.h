// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttonClicked();
    void restartGame();

private:
    void initializeBoard();
    void printBoard(); // Function to display the current state of the board
    bool checkWin(); // Function to check for a win condition
    bool checkDraw(); // Function to check for a draw condition
    void switchPlayer(); // Function to switch turns between players
    void playerMove(QPushButton *button); // Function to handle player's move input and update the board
    void updateCurrentPlayerLabel();

    QVector<QVector<QPushButton*>> board;
    QString currentPlayer;
    QLabel *currentPlayerLabel;
    QPushButton *restartButton;
};

#endif // MAINWINDOW_H
