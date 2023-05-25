#ifndef HEROBULLET_H
#define HEROBULLET_H
#include <bullet.h>
#include <QGraphicsScene>

class HeroBullet : public QObject, public Bullet
{
    Q_OBJECT
public:
    HeroBullet();
    HeroBullet(int xPos, int yPos, int horizontalSpeed = 1300);
    virtual ~HeroBullet() {};
    QPolygon getHitbox() override;

    //bool isNeededToBeDeleted(QGraphicsScene* scene);
//signals:
//    void destroyHeroBullet(this);
};

#endif // HEROBULLET_H
