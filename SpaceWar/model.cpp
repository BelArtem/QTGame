#include "model.h"

Model::Model()
{
    hero_ = Hero();
    enemies_ = QVector<Enemy*>(0);
}

Hero& Model::getHero(){
    return hero_;
}

QVector<Enemy*> Model::getEnemies(){
    return enemies_;
}
