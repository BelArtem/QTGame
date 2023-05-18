#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include <QGraphicsScene>

class Bullet
{
public:
    Bullet();
    virtual ~Bullet() = default;

    QPixmap image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int x_coordinate_;
    int y_coordinate_;

    virtual QPolygon getHitbox() = 0;

    //virtual void clearBullets(QGraphicsScene* scene) = 0;
};

#endif // BULLET_H
