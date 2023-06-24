#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new BlackJack::Scene(this);
    scene->setSceneRect(0, 0, 400, 400);

    BlackJack::Card card(2, BlackJack::Hearts, ":/resources/resources/mytexture/hearts/2.png");
    scene->addItem(card.GetImg());


    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
