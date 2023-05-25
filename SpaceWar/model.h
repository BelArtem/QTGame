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
    //QVector<Bullet*>* getAllEnemyBullets();
    //void getAllEnemyBullets(QVector<Bullet*>& vec);
    BulletManager* getBulletManager();
    QVector<Enemy*>& getEnemies();
    void stopAllEvents();



private:
    BulletManager bullet_manager_;



    QVector<Enemy*> enemies_;
    Hero hero_;
    QTimer* spawn_enemy_timer_;
    int randomizer_area_height_;
    int area_width_;
    EnemyGenerator generator_;
    //QTimer* getBulletsTimer_;

private slots:
    void spawnEnemyTimerEvent();
    //void

public slots:
    void increaseSpawnSpeed(int millisec);
signals:
    //void enemyPassed();

};

#endif // MODEL_H
