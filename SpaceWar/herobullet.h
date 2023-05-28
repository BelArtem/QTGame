#ifndef HEROBULLET_H
#define HEROBULLET_H
#include <bullet.h>
#include <QGraphicsScene>

class HeroBullet : public QObject, public Bullet
{
    Q_OBJECT
public:
    HeroBullet();
    HeroBullet(int xPos, int yPos, int horizontalSpeed = 1000);
    virtual ~HeroBullet() {};
    QPolygon getHitbox() override;
};

#endif // HEROBULLET_H
