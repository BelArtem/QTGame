#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <model.h>
#include <bulletmanager.h>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <hero.h>
#include <QGraphicsItemGroup>
#include <QDebug>
#include <cmath>
#include <QGraphicsSceneMouseEvent>
#include <QProgressBar>
#include <QLabel>
#include <score.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMediaPlaylist>
#include <gameovermenu.h>
#include <QGraphicsProxyWidget>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject* parent = 0);
    virtual ~Scene();
    void startGame();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void setUpScene();
    void prepareScene();

private:
    Model* model_;
    QGraphicsItem* hero_item_;
    QGraphicsItemGroup* bullets_group_;
    QGraphicsItemGroup* enemies_group_;
    QVector<QGraphicsPixmapItem*> bullet_pixmaps_;
    QVector<QGraphicsPixmapItem*> enemy_pixmaps_;
    QProgressBar* health_bar_;
    bool block_moving_;
    Score* score_;
    QMediaPlayer* main_music_;
    QMediaPlaylist* playlist_;
    QMediaPlayer* shot_sound_;
    GameOverMenu* game_over_menu_;
    QGraphicsProxyWidget* graphics_widget_;

    QTimer* move_hero_timer_;
    QMap<int, bool> keys_;
    QTimer* refresh_timer_;
    QTimer* intersections_refresh_timer_;

private slots:
    void moveHeroTimerEvent();
    void manageHeroBulletsTimerEvent();
    void manageEnemiesTimerEvent();
    void manageIntersections();
    void restartGame();
    void showMainMenu();

public slots:
    void stopGame();

signals:
    void restartGameSignal();
    void ShowMainMenuSignal();
};

#endif // SCENE_H
