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

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //protected:
    //void resizeEvent(QResizeEvent *event) override;
private:
    //QGraphicsScene* scene_;
    GameOverMenu* game_over_menu_;
    MainMenu* main_menu_;
    Scene* scene_;
    QGraphicsView* view_;
    //QGraphicsRectItem* rectangle;
    //Ui::MainWindow *ui;
private slots:
    void startGame();
    void closeGame();
    void showMainMenu();
signals:
    void closeGameSignal();
};
#endif // MAINWINDOW_H
