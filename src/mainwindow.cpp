#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlackJack::Scene(this);
    scene->setSceneRect(0, 0, 400, 400);

    BlackJack::Game game({BlackJack::User("copycat", 1000)}, "mytexture");
    game.Start();

    for (auto card : game.GetDealer()->GetHand())
        scene->addItem(card);

    ui->dealersHand->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hitButton_clicked()
{
    qDebug() << "Button clicked!";
}
