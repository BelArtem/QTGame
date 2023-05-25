#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>
#include <QTimer>
#include <bulletmanager.h>
#include <bullet.h>

enum class EnemyType{
    EnemyType1 = 0

};

class Enemy: public QObject
{
    Q_OBJECT
public:
    Enemy();
    virtual ~Enemy() {delete shoot_timer_;};

    QPixmap image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int x_coordinate_;
    int y_coordinate_;
    bool is_eliminated_;
    QTimer* shoot_timer_;
    int hp_;
    //QVector<Bullet*> bullets_;


    //virtual void clearBullets() = 0;
    virtual QPolygon getHitbox() = 0;
    //virtual QVector<Bullet*>& getBullets() = 0;
//public slots:
//    void getTimerEvent();
//signals:
//    virtual void bulletInfo (BulletType type,int posX, int posY) = 0;
};

#endif // ENEMY_H
