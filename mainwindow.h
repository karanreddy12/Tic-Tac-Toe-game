// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

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
    void clearBoard();
    bool checkWin();
    bool checkDraw();
    void updateCurrentPlayerLabel();

    QVector<QVector<QPushButton*>> board;
    QString currentPlayer;
    QLabel *currentPlayerLabel;
    QPushButton *restartButton;
};

#endif // MAINWINDOW_H
