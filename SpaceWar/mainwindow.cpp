#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      game_over_menu_ (new GameOverMenu(this)),
      main_menu_ (new MainMenu(this)),
      scene_ (new Scene(this)),
      view_ (new QGraphicsView(this))
{
    resize(1920,980);
    this->setMinimumSize(1920, 980);
    this->setMaximumSize(1920, 980);
    view_->setScene(main_menu_);

    scene_->setSceneRect(0,0,this->width() - 2,this->height() - 2);
    main_menu_->setSceneRect(0,0,this->width() - 2,this->height() - 2);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setGeometry(0,0,this->width(),this->height());
    QObject::connect(main_menu_, &MainMenu::startGameSignal, this, &MainWindow::startGame);
    QObject::connect(main_menu_, &MainMenu::closeGameSignal, this, &MainWindow::closeGame);
    QObject::connect(scene_, &Scene::restartGameSignal, this, &MainWindow::startGame);
    QObject::connect(scene_, &Scene::ShowMainMenuSignal, this, &MainWindow::showMainMenu);
}

MainWindow::~MainWindow()
{
    delete game_over_menu_;
    delete main_menu_;
    delete scene_;
    delete view_;
}

void MainWindow::startGame(){
    view_->setScene(scene_);
    scene_->startGame();
}
void MainWindow::closeGame(){
    emit closeGameSignal();
}

void MainWindow::showMainMenu(){
    view_->setScene(main_menu_);
    main_menu_->startMusic();
}
