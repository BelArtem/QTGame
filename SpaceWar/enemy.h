#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>

class Enemy
{
public:
    Enemy();
    virtual ~Enemy() = default;

    QPixmap image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int x_coordinate_;
    int y_coordinate_;

    virtual QPolygon getHitbox() = 0;

};

#endif // ENEMY_H
