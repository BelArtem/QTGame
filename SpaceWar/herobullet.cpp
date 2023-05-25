#include "herobullet.h"

HeroBullet::HeroBullet()
{
    image_ = QPixmap(":/images/sources/images/herobullet.png");
    //QVector<QPoint> list = {{33,13}, {26,6}, {18,7}, {5,13}, {18,19}, {26,19}};
    QVector<QPoint> list = {{75,60}, {69,54}, {62,54}, {48,60}, {62,66}, {69,66}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = 1300;
    x_coordinate_ = 0;
    y_coordinate_ = 0;
    is_eliminated_ = false;
    damage_ = 10;
}

HeroBullet::HeroBullet(int xPos, int yPos, int horizontalSpeed){
    image_ = QPixmap(":/images/sources/images/herobullet.png");
    QVector<QPoint> list = {{75,60}, {69,54}, {62,54}, {48,60}, {62,66}, {69,66}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = horizontalSpeed;
    x_coordinate_ = xPos;
    y_coordinate_ = yPos;
    is_eliminated_ = false;
    damage_ = 10;
}

//bool HeroBullet::isNeededToBeDeleted(QGraphicsScene* scene){
//    if (x_coordinate_ > scene->width() + image_.width()){
//        return true;
//    }
//    return false;
//}

QPolygon HeroBullet::getHitbox(){
    QPolygon result = QPolygon (hitBox_);
    for (int i = 0; i < hitBox_.size(); ++i){
        QPoint p = hitBox_.point(i);
        result.setPoint(i, p.x() + x_coordinate_, p.y() + y_coordinate_);
    }
    return result;
}
