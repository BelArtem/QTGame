#include "hero.h"

Hero::Hero()
{
    //image_ = QImage(":/images/sources/images/hero.png");
    image_ = QPixmap(":/images/sources/images/hero.png");
    QVector<QPoint> list = {{99,65}, {90,56}, {87,39}, {79,25}, {24,16}
                         , {14,1}, {5,5}, {10,18}, {11,39}, {2,50}, {0,64}
                         , {0,72}, {2,86}, {11,97}, {10,118}, {5,131}
                         , {13,135}, {19,132}, {25,118}, {80,111}, {87,97}
                         , {88,82}, {98,73}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = 500;
    vertical_speed_ = 500;
    x_coordinate_ = 0;
    y_coordinate_ = 0;
}

void Hero::setHorizontalSpeed(int speed){
    horizontal_speed_ = speed;
}

void Hero::setVerticalSpeed(int speed){
    vertical_speed_ = speed;
}

void Hero::setXCoordinate(int x){
    x_coordinate_ = x;
}

void Hero::setYCoordinate(int y){
    y_coordinate_ = y;
}

//QImage Hero::getImage(){
//    return image_;
//}

QPixmap Hero::getPixmap(){
    return image_;
}

int Hero::getHorizontalSpeed(){
    return horizontal_speed_;
}

int Hero::getVerticalSpeed(){
    return vertical_speed_;
}

int Hero::getXCoordinate(){
    return x_coordinate_;
}

int Hero::getYCoordinate(){
    return y_coordinate_;
}

QPolygon Hero::getHitBox(){
    QPolygon result = QPolygon (hitBox_);
    for (int i = 0; i < hitBox_.size(); ++i){
        QPoint p = hitBox_.point(i);
        result.setPoint(i, p.x() + x_coordinate_, p.y() + y_coordinate_);
    }
    return result;
}


