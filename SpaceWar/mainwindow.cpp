#include "mainwindow.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      game_over_menu_ (new GameOverMenu(this)),
      //scene_ (new QGraphicsScene(this)),
      main_menu_ (new MainMenu(this)),
      scene_ (new Scene(this)),
      view_ (new QGraphicsView(this))
    //view_ (new QGraphicsView(this))
    //, ui(new Ui::MainWindow)
{
    resize(1920,980);
    this->setMinimumSize(1920, 980);
    this->setMaximumSize(1920, 980);
    //this->setMinimumSize(600,600);


    //    view_->setScene(scene_);
    view_->setScene(main_menu_);

    //int a = this->height();
    scene_->setSceneRect(0,0,this->width() - 2,this->height() - 2);
    main_menu_->setSceneRect(0,0,this->width() - 2,this->height() - 2);
    //QPixmap im (":/images/sources/images/background.jpg");
    //QGraphicsPixmapItem image (im);
    view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_->setGeometry(0,0,this->width(),this->height());
    QObject::connect(main_menu_, &MainMenu::startGameSignal, this, &MainWindow::startGame);
    QObject::connect(main_menu_, &MainMenu::closeGameSignal, this, &MainWindow::closeGame);
    QObject::connect(scene_, &Scene::restartGameSignal, this, &MainWindow::startGame);
    QObject::connect(scene_, &Scene::ShowMainMenuSignal, this, &MainWindow::showMainMenu);



    //    moveHeroTimer_->setInterval(1000/60);
    //    moveHeroTimer_->start();
    //    connect(moveHeroTimer_, SIGNAL(&QTimer::timeout), scene_, SLOT(&Scene::moveHeroTimerEvent));
    //    qDebug() <<"22";
    //scene_->setSceneRect(0,0,this->width(),this->height());
    //scene_->addPixmap(im);

    //scene_->addLine()
    //ui->setupUi(this);

    //    QBrush greenBrush(Qt::green);
    //        QBrush blueBrush(Qt::blue);
    //        QPen outlinePen(Qt::black);
    //        outlinePen.setWidth(2);

    //        rectangle = scene_->addRect(100, 0, 80, 100, outlinePen, blueBrush);

    //        // addEllipse(x,y,w,h,pen,brush)
    //        ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

    //        text = scene->addText("bogotobogo.com", QFont("Arial", 20) );
    //        // movable text
    //        text->setFlag(QGraphicsItem::ItemIsMovable);
    //    resize(800, 800);
    //        //paint_widget_->setGeometry(0,0,600,600);
    //        view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //        view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //         view_->setGeometry(0,0,600,600);
    //         scene_->setSceneRect(0,0,600,600);
    //        view_->setScene(scene_);
    //        scene_->addLine(QLine(0,0, 600,600));

}

//void MainWindow::resizeEvent(QResizeEvent *event) {
//    Q_UNUSED(event);
//    scene_->resizeScene();
//}
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

