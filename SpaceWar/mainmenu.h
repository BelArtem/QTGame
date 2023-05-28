#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMediaPlaylist>


class MainMenu : public QGraphicsScene
{
    Q_OBJECT

public:
    MainMenu(QObject* parent = 0);
    virtual ~MainMenu();

    void startMusic();

private:
    void setUpScene();

private:
    QWidget* widget_;
    QGridLayout* layout_;
    //QVBoxLayout* buttons_layout_;
    QPushButton* start_button_;
    QPushButton* exit_button_;

    QMediaPlayer* menu_music_;
    QMediaPlaylist* menu_playlist_;

private slots:
    void startButtonClicked();
    void exitButtonClicked();

signals:
    void startGameSignal();
    void closeGameSignal();
};

#endif // MAINMENU_H
