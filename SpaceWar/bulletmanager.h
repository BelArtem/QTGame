#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include <bullet.h>
#include <herobullet.h>
#include <enemybullet.h>
#include <QVector>
#include <QTimer>
#include <QDebug>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>

enum class BulletType{
    Hero = 0,
    EnemyType1
};


///TODO:
/// delete bullets, whick are out of map

class BulletManager: public QObject {
    Q_OBJECT
public:
    //BulletManager(QObject* parent = 0);
    BulletManager();
    //~BulletManager() = default;
    virtual ~BulletManager() {};

    void addBullet(BulletType type,int posX, int posY);
    //QGraphicsItemGroup* getBulletsItemGroup();
    QVector<QGraphicsPixmapItem*> getBulletsPixmapItems();
    void updateBulletsCoordinates(int interval);
    void clearBullets(QGraphicsScene* scene);


private:
    QVector<Bullet*> hero_bullets_;
    QVector<Bullet*> enemy_bullets_;
    //QTimer* bulletsClearTimer_;

public slots:
    //void updateBulletsCoordinates();
    //void heroBulletRemove();
};

#endif // BULLETMANAGER_H
