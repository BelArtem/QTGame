#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include <enemy.h>
#include <enemytype1.h>

class EnemyGenerator
{
public:
    EnemyGenerator();
    ~EnemyGenerator() = default;

    Enemy* generateEnemy(EnemyType type, int xPos);
};

#endif // ENEMYGENERATOR_H
