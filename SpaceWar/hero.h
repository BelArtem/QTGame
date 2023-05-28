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
    ~Hero() {};

    void setHorizontalSpeed(int speed);
    void setVerticalSpeed(int speed);
    void setXCoordinate (int x);
    void setYCoordinate (int y);
    void setEliminated (bool flag);
    void setHP (int newHP);

    QPixmap getPixmap();
    int getHorizontalSpeed();
    int getVerticalSpeed();
    int getXCoordinate();
    int getYCoordinate();
    QPolygon getHitBox();
    bool getEliminated();
    int getHP();

private:
    QPixmap image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int vertical_speed_;
    int x_coordinate_;
    int y_coordinate_;
    bool is_eliminated_;
    int hp_;

signals:
    void isDestroyed();
};

#endif // HERO_H
