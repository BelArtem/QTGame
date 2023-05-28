#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <scene.h>
#include <mainmenu.h>
#include <gameovermenu.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    GameOverMenu* game_over_menu_;
    MainMenu* main_menu_;
    Scene* scene_;
    QGraphicsView* view_;

private slots:
    void startGame();
    void closeGame();
    void showMainMenu();
signals:
    void closeGameSignal();
};
#endif // MAINWINDOW_H
