#ifndef HERO_H
#define HERO_H
#include <QImage>
#include <QPixmap>
#include <bullet.h>
#include <enemy.h>

class Hero: public QObject
{
    Q_OBJECT
public:
    Hero();
    //    ~Hero() {delete shoot_timer_;};
    ~Hero() {};

    void setHorizontalSpeed(int speed);
    void setVerticalSpeed(int speed);
    void setXCoordinate (int x);
    void setYCoordinate (int y);
    void setEliminated (bool flag);
    void setHP (int newHP);

    //QImage getImage();
    QPixmap getPixmap();
    int getHorizontalSpeed();
    int getVerticalSpeed();
    int getXCoordinate();
    int getYCoordinate();
    QPolygon getHitBox();
    bool getEliminated();
    int getHP();
    //void stopShootingTimer();
    //void startShootingTimer();


private:
    QPixmap image_;
    //QImage image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int vertical_speed_;
    int x_coordinate_;
    int y_coordinate_;
    bool is_eliminated_;
    int hp_;
    //QTimer* shoot_timer_;

signals:
    void isDestroyed();
    //void bulletInfo(BulletType type,int posX, int posY);

public slots:
    //void shootTimerEvent();
};

#endif // HERO_H
