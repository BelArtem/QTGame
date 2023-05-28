#include "gameovermenu.h"

GameOverMenu::GameOverMenu(QWidget* parent) : QWidget(parent)
{
    layout_ = new QGridLayout();
    //buttons_layout_ = new QVBoxLayout();
    restart_button_ = new QPushButton();
    menu_button_ = new QPushButton();

    QObject::connect(restart_button_, &QPushButton::clicked, this, &GameOverMenu::restartButtonClicked);
    QObject::connect(menu_button_, &QPushButton::clicked, this, &GameOverMenu::menuButtonClicked);
    this->setUpWidget();
}

void GameOverMenu::setUpWidget(){
    restart_button_->setText("Restart");
    restart_button_->setMinimumSize(250,50);
    restart_button_->setStyleSheet("background-color: #010327;"
                                   "color: #74c8ff;"
                                   "border-style: outset;"
                                   "border-width: 2px;"
                                   "border-radius: 20px;"
                                   "border-color: beige;"
                                   "font: bold 30px;"
                                   //"min-width: 10em;"
                                   "padding: 6px;"
                                   );
    menu_button_->setText("Main menu");
    menu_button_->setMinimumSize(250,50);
    menu_button_->setStyleSheet("background-color: #010327;"
                                "color: #74c8ff;"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 20px;"
                                "border-color: beige;"
                                "font: bold 30px;"
                                //"min-width: 10em;"
                                "padding: 6px;"
                                );
    layout_->setVerticalSpacing(40);
    layout_->addWidget(restart_button_, 0,0);
    layout_->addWidget(menu_button_, 1,0);
    //buttons_layout_->setAlignment(Qt::AlignBottom);

    this->setLayout(layout_);
    //int a = this->height();
    this->setAttribute(Qt::WA_TranslucentBackground);
    //    QWidget::setAttribute(Qt::WA_TranslucentBackground);
    //widget_->move(0,0);
    //widget_.
    //widget_->show();
    //    widget_->move(0,0);
    //    widge
}

void GameOverMenu::restartButtonClicked(){
    emit restartGameSignal();
}

void GameOverMenu::menuButtonClicked(){
    emit setUpMainMenuSignal();
}

GameOverMenu::~GameOverMenu(){
    QObject::disconnect(restart_button_, &QPushButton::clicked, this, &GameOverMenu::restartButtonClicked);
    QObject::disconnect(menu_button_, &QPushButton::clicked, this, &GameOverMenu::menuButtonClicked);
    delete layout_;
    delete restart_button_;
    delete menu_button_;
}
