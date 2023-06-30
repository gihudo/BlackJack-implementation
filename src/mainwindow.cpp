#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlackJack::Scene(this);
    scene->setSceneRect(0, 0, 400, 400);
    auto bg = new QGraphicsPixmapItem(QPixmap(":/resources/resources/table.png"));
    scene->addItem(bg);
    bg->setScale(5);
    bg->setPos(QPointF(0, 0) - QPointF(bg->boundingRect().width() / 2,
                                      (bg->boundingRect().height() / 2)));


    ui->gameField->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);


    game.Start();

    for (int i = 0; i < game.GetDealer()->GetHand().size(); ++i)
        scene->addItem(game.GetDealer()->GetHand()[i]->Animate(i, QPointF(-125, 0)));

    for (int i = 0; i < game.GetDealer()->GetUsers()[0].GetHand().size(); ++i)
        scene->addItem(game.GetDealer()->GetUsers()[0].GetHand()[i]->Animate(i, QPointF(-100, 250)));
}
