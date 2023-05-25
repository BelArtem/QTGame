#ifndef ENEMYTYPE1_H
#define ENEMYTYPE1_H
#include <enemy.h>
#include <QTimer>

class EnemyType1: public Enemy
{
    Q_OBJECT
public:
    EnemyType1();
    EnemyType1(int xPos, int yPos, int horizontalSpeed = -800);
    ~EnemyType1() = default;
    QPolygon getHitbox() override;
    //QVector<Bullet*>& getBullets() override;
    //void clearBullets() override;

//private slots:
//    void addBullet();
//public slots:
//    void getTimerEvent();

public slots:
    void getTimerEvent();
//signals:
//    void BulletInfo (BulletType type,int posX, int posY);
signals:
    void bulletInfo (BulletType type,int posX, int posY);
};

#endif // ENEMYTYPE1_H
