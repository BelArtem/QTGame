#ifndef ENEMYTYPE1_H
#define ENEMYTYPE1_H
#include <enemy.h>

class EnemyType1: public Enemy
{
public:
    EnemyType1();
    EnemyType1(int xPos, int yPos, int horizontalSpeed = -800);
    ~EnemyType1() = default;
    QPolygon getHitbox() override;

};

#endif // ENEMYTYPE1_H
