#include "mainmenu.h"

MainMenu::MainMenu(QObject* parent) : QGraphicsScene(parent)
{
    widget_ = new QWidget();
    layout_ = new QGridLayout();
    start_button_ = new QPushButton();
    exit_button_ = new QPushButton();
    menu_music_ = new QMediaPlayer();
    menu_playlist_ = new QMediaPlaylist();

    this->setSceneRect(0,0,1920,980);
    QObject::connect(start_button_, &QPushButton::clicked, this, &MainMenu::startButtonClicked);
    QObject::connect(exit_button_, &QPushButton::clicked, this, &MainMenu::exitButtonClicked);
    this->setUpScene();
}

void MainMenu::startMusic(){
    menu_music_->play();
}

void MainMenu::setUpScene(){
    QPixmap im (":/images/sources/images/menu_background.jpg");
    QGraphicsPixmapItem image (im);
    this->addPixmap(im);
    start_button_->setText("Start");
    start_button_->setMinimumSize(450,70);
    start_button_->setStyleSheet("background-color: #010327;"
                                 "color: #74c8ff;"
                                 "border-style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 20px;"
                                 "border-color: beige;"
                                 "font: bold 30px;"
                                 "padding: 6px;"
                                 );
    exit_button_->setText("Exit");
    exit_button_->setMinimumSize(450,70);
    exit_button_->setStyleSheet("background-color: #010327;"
                                "color: #74c8ff;"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 20px;"
                                "border-color: beige;"
                                "font: bold 30px;"
                                "padding: 6px;"
                                );
    layout_->setVerticalSpacing(60);
    layout_->addWidget(start_button_, 0,0);
    layout_->addWidget(exit_button_, 1,0);

    widget_->setLayout(layout_);
    widget_->move((this->width() - start_button_->width()) / 2 + 100,
                  this->height()/ 2);
    widget_->setAttribute(Qt::WA_TranslucentBackground);
    this->addWidget(widget_);

    menu_playlist_->addMedia(QUrl("qrc:/music/sources/music/menu_music.mp3"));
    menu_playlist_->setPlaybackMode(QMediaPlaylist::Loop);
    menu_music_->setPlaylist(menu_playlist_);
    menu_music_->setVolume(100);
    menu_music_->play();
}

void MainMenu::startButtonClicked(){
    menu_music_->stop();
    emit startGameSignal();
}

void MainMenu::exitButtonClicked(){
    emit closeGameSignal();
}

MainMenu::~MainMenu(){
    QObject::disconnect(start_button_, &QPushButton::clicked, this, &MainMenu::startButtonClicked);
    QObject::disconnect(exit_button_, &QPushButton::clicked, this, &MainMenu::exitButtonClicked);
    delete widget_;
    delete layout_;
    delete start_button_;
    delete exit_button_;
    delete menu_music_;
    delete menu_playlist_;
}
