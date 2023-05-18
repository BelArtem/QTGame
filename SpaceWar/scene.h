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
private:
    Model model_;
    BulletManager bullet_manager_;
    QGraphicsItem* hero_item_;
    QGraphicsItemGroup* bullets_group_;
    QGraphicsItemGroup* enemies_group_;
    QVector<QGraphicsPixmapItem*> bullet_pixmaps_;
    QVector<QGraphicsPixmapItem*> enemy_pixmaps_;



    QTimer* move_hero_timer_;
    QMap<int, bool> keys_;
    QTimer* bullets_refresh_timer_;
    QTimer* shooting_limit_timer_;
    QTimer* enemies_refrest_timer_;
    //bool is_first_shot_;
    //Hero hero;

    //QGraphicsLineItem* itemToDraw;
private slots:
    void moveHeroTimerEvent();
    void manageBulletsTimerEvent();
    void heroShootTimerEvent();
    void manageEnemiesTimerEvent();
};

#endif // SCENE_H
