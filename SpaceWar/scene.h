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
    //enum Mode {NoMode, SelectObject, DrawLine};
    Scene(QObject* parent = 0);
    //~Scene();
    virtual ~Scene() {};
    //void setMode(Mode mode);
protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //void addItem (Hero)S
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



    QTimer* moveHeroTimer_;
    QMap<int, bool> keys_;
    QTimer* bulletsRefreshTimer_;
    QTimer* shootingLimitTimer_;
    //Hero hero;

    //Mode sceneMode;
    //QPointF origPoint;
    //QGraphicsLineItem* itemToDraw;
    //void makeItemsControllable(bool areControllable);
private slots:
    void moveHeroTimerEvent();
    void manageBulletsTimerEvent();
    void heroShootTimerEvent();
};

#endif // SCENE_H
