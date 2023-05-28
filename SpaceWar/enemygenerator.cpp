#include "enemygenerator.h"
#include <QRandomGenerator>

EnemyGenerator::EnemyGenerator()
{

}

Enemy* EnemyGenerator::generateEnemy(EnemyType type, int xPos){
    Enemy* newEnemy = nullptr;
    switch(type)
    {
        case EnemyType::EnemyType1:
            newEnemy = new EnemyType1();
            break;
        default:
            qFatal("fatal error");
    }
    QRandomGenerator *rg = QRandomGenerator::global();
    int section = rg->bounded(0, INT_MAX) % 11;
    int width = 980 - newEnemy->image_.height();
    int randomHeight = rg->bounded(static_cast<int>((width * 1.0 / 11) * section),
                                   (static_cast<int>(width * 1.0 / 11) * (section + 1)));
    newEnemy->x_coordinate_ = xPos;
    newEnemy->y_coordinate_ = randomHeight;
    return newEnemy;
}
