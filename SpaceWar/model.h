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
#include <enemygenerator.h>
#include <bullet.h>
#include <bulletmanager.h>


class Model: public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model();

    Hero& getHero();
    QVector<QGraphicsPixmapItem*> getEnemiesPixmapItems();
    void updateEnemiesCoordinates(int interval);
    void clearUnusedEnemies();
    void clearAllEnemies();
    void setRandomizerAreaHeight(int height);
    void setAreaWidth(int width);
    size_t getEnemiesAmount();
    BulletManager* getBulletManager();
    QVector<Enemy*>& getEnemies();
    void stopAllEvents();
    void startSpawnTimer();
    void stopSpawnTimer();

private:
    BulletManager bullet_manager_;
    QVector<Enemy*> enemies_;
    Hero hero_;
    QTimer* spawn_enemy_timer_;
    int randomizer_area_height_;
    int area_width_;
    EnemyGenerator generator_;

private slots:
    void spawnEnemyTimerEvent();

public slots:
    void increaseSpawnSpeed(int millisec);
};

#endif // MODEL_H
