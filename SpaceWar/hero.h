#ifndef HERO_H
#define HERO_H
#include <QImage>
#include <QPixmap>
#include <bullet.h>

class Hero
{
public:
    Hero();
    ~Hero() = default;

    void setHorizontalSpeed(int speed);
    void setVerticalSpeed(int speed);
    void setXCoordinate (int x);
    void setYCoordinate (int y);

    //QImage getImage();
    QPixmap getPixmap();
    int getHorizontalSpeed();
    int getVerticalSpeed();
    int getXCoordinate();
    int getYCoordinate();
    QPolygon getHitBox();

private:
    QPixmap image_;
    //QImage image_;
    QPolygon hitBox_;
    int horizontal_speed_;
    int vertical_speed_;
    int x_coordinate_;
    int y_coordinate_;

};

#endif // HERO_H
