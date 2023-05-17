#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <bullet.h>

class EnemyBullet : public Bullet
{
public:
    EnemyBullet();
    EnemyBullet(int xPos, int yPos, int horizontalSpeed = 1000);
    ~EnemyBullet() = default;
};

#endif // ENEMYBULLET_H
