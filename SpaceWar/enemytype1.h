#ifndef ENEMYTYPE1_H
#define ENEMYTYPE1_H
#include <enemy.h>
#include <QTimer>

class EnemyType1: public Enemy
{
    Q_OBJECT
public:
    EnemyType1();
    EnemyType1(int xPos, int yPos, int horizontalSpeed = -500);
    ~EnemyType1() = default;
    QPolygon getHitbox() override;

public slots:
    void getTimerEvent();

signals:
    void bulletInfo (BulletType type,int posX, int posY);
};

#endif // ENEMYTYPE1_H
