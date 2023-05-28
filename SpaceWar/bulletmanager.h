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

class BulletManager: public QObject
{
    Q_OBJECT
public:
    BulletManager();
    virtual ~BulletManager() {};

    void addBullet(BulletType type,int posX, int posY);
    QVector<QGraphicsPixmapItem*> getBulletsPixmapItems();
    void updateBulletsCoordinates(int interval);
    void clearUnusedBullets(QGraphicsScene* scene);
    void clearAllBullets();
    size_t getHeroBulletsAmount();
    size_t getEnemyBulletsAmount();
    QVector<Bullet*>& getHeroBullets();
    QVector<Bullet*>& getEnemyBullets();

private:
    QVector<Bullet*> hero_bullets_;
    QVector<Bullet*> enemy_bullets_;

public slots:
    void addBulletEvent(BulletType type,int posX, int posY);
};

#endif // BULLETMANAGER_H
