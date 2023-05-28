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

class BulletManager: public QObject {
    Q_OBJECT
public:
    //BulletManager(QObject* parent = 0);
    BulletManager();
    //~BulletManager() = default;
    virtual ~BulletManager() {};

    void addBullet(BulletType type,int posX, int posY);
    //void addEnemyBullet(Bullet* bulet);
    //QGraphicsItemGroup* getBulletsItemGroup();
    QVector<QGraphicsPixmapItem*> getBulletsPixmapItems();
    void updateBulletsCoordinates(int interval);
    void clearUnusedBullets(QGraphicsScene* scene);
    void clearAllBullets();
    size_t getHeroBulletsAmount();
    size_t getEnemyBulletsAmount();
    QVector<Bullet*>& getHeroBullets();
    QVector<Bullet*>& getEnemyBullets();
    //QVector<Bullet*> hero_bullets_;

    //QVector<Bullet*> hero_bullets_;
    //QVector<Bullet*> enemy_bullets_;


private:
    QVector<Bullet*> hero_bullets_;
    QVector<Bullet*> enemy_bullets_;
    //QTimer* bulletsClearTimer_;

public slots:
    //void updateBulletsCoordinates();
    //void heroBulletRemove();
    void addBulletEvent(BulletType type,int posX, int posY);
};

#endif // BULLETMANAGER_H
