#ifndef ENEMY_H
#define ENEMY_H
#include <QImage>
#include <bullet.h>

class Enemy
{
public:
    Enemy();
    ~Enemy() = default;

    QImage image_;
    QPolygon hitBox_;
    double speed_;

};

#endif // ENEMY_H
