#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "BlackJack/scene.h"
#include "BlackJack/game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    BlackJack::Scene *scene;
    BlackJack::Game game = BlackJack::Game({BlackJack::User("copycat", 1000)}, "mytexture");
};
#endif // MAINWINDOW_H
