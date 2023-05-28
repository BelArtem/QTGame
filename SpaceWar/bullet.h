#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include <QGraphicsScene>

class Bullet
{
public:
    Bullet();
    virtual ~Bullet() = default;

    virtual QPolygon getHitbox() = 0;

    QPixmap image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int x_coordinate_;
    int y_coordinate_;
    bool is_eliminated_;
    int damage_;
};

#endif // BULLET_H
