#ifndef MODEL_H
#define MODEL_H
#include <enemy.h>
#include <enemytype1.h>
#include <hero.h>
#include <QVector>
#include <random>
#include <QTimer>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>

enum class EnemyType{
    EnemyType1 = 0

};

class Model: public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model() = default;

    Hero& getHero();
    //QVector<Enemy*> getEnemies();
    //void generateEnemy(EnemyType type,int posX, int posY);
    QVector<QGraphicsPixmapItem*> getEnemiesPixmapItems();
    void updateEnemiesCoordinates(int interval);
    void clearEnemies();
    void setRandomizerAreaHeight(int height);
    void setAreaWidth(int width);
    size_t getEnemiesAmount();

private:
    QVector<Enemy*> enemies_;
    Hero hero_;
    QTimer* spawn_enemy_timer_;
    int randomizer_area_height_;
    int area_width_;

private slots:
    void spawnEnemyTimerEvent();

};

#endif // MODEL_H
