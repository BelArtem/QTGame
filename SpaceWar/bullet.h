#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include <QGraphicsScene>

class Bullet
{
public:
    Bullet();
    ~Bullet() = default;

    QPixmap image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int x_coordinate_;
    int y_coordinate_;

    //virtual void clearBullets(QGraphicsScene* scene) = 0;
};

#endif // BULLET_H
