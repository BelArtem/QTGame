#include "enemybullet.h"

EnemyBullet::EnemyBullet()
{
    image_ = QPixmap(":/images/sources/images/enemy1bullet.png");
    //QVector<QPoint> list = {{33,13}, {26,6}, {18,7}, {5,13}, {18,19}, {26,19}};
    QVector<QPoint> list = {{51,61}, {57, 55}, {63,55}, {78,61}, {63,67}, {57,67}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = 1000;
    x_coordinate_ = 0;
    y_coordinate_ = 0;
    is_eliminated_ = false;
    damage_ = 10;
}

EnemyBullet::EnemyBullet(int xPos, int yPos, int horizontalSpeed){
    image_ = QPixmap(":/images/sources/images/enemy1bullet.png");
    //QVector<QPoint> list = {{33,13}, {26,6}, {18,7}, {5,13}, {18,19}, {26,19}};
    QVector<QPoint> list = {{51,61}, {57, 55}, {63,55}, {78,61}, {63,67}, {57,67}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = horizontalSpeed;
    x_coordinate_ = xPos;
    y_coordinate_ = yPos;
    is_eliminated_ = false;
    damage_ = 10;
}

QPolygon EnemyBullet::getHitbox(){
    QPolygon result = QPolygon (hitBox_);
    for (int i = 0; i < hitBox_.size(); ++i){
        QPoint p = hitBox_.point(i);
        result.setPoint(i, p.x() + x_coordinate_, p.y() + y_coordinate_);
    }
    return result;
}
