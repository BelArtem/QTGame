#ifndef MODEL_H
#define MODEL_H
#include<enemy.h>
#include<hero.h>
#include<QVector>

class Model
{
public:
    Model();
    ~Model() = default;

    Hero& getHero();
    QVector<Enemy*> getEnemies();

private:
    QVector<Enemy*> enemies_;
    Hero hero_;

};

#endif // MODEL_H
