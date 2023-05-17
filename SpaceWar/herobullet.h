#ifndef HEROBULLET_H
#define HEROBULLET_H
#include <bullet.h>
#include <QGraphicsScene>

class HeroBullet : public QObject, public Bullet
{
    Q_OBJECT
public:
    HeroBullet();
    HeroBullet(int xPos, int yPos, int horizontalSpeed = 800);
    virtual ~HeroBullet() {};

    //bool isNeededToBeDeleted(QGraphicsScene* scene);
//signals:
//    void destroyHeroBullet(this);
};

#endif // HEROBULLET_H
