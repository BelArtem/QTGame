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

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene(QObject* parent = 0);
    virtual ~Scene() {};
protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    void setUpScene();
    //void stopMoving();
    //void checkHits();
private:
    Model model_;
    //BulletManager bullet_manager_;
    QGraphicsItem* hero_item_;
    //QGraphicsItem* score_;
    QGraphicsItemGroup* bullets_group_;
    QGraphicsItemGroup* enemies_group_;
    QVector<QGraphicsPixmapItem*> bullet_pixmaps_;
    QVector<QGraphicsPixmapItem*> enemy_pixmaps_;
    bool block_moving_;


    QTimer* move_hero_timer_;
    QMap<int, bool> keys_;
    QTimer* refresh_timer_;
    //QTimer* bullets_refresh_timer_;
    //QTimer* shooting_timer_;
    //QTimer* enemies_refrest_timer_;
    QTimer* intersections_refresh_timer_;
    bool is_first_shot_;
    QProgressBar* health_bar_;
    //Score score_counter;
    Score* score_;
    //QLabel* score_;

    //Hero hero;

    //QGraphicsLineItem* itemToDraw;

private slots:
    void moveHeroTimerEvent();
    void manageHeroBulletsTimerEvent();
    //void heroShootTimerEvent();
    void manageEnemiesTimerEvent();
    void manageIntersections();

    //void manageEnemyBulletsTimerEvent();
public slots:
    void stopGame();
    //void decreaseScore();
//signals:
//    void makeMoreDifficult();
};

#endif // SCENE_H
