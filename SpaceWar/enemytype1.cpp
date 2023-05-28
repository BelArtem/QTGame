#include "enemytype1.h"

EnemyType1::EnemyType1()
{
    image_ = QPixmap(":/images/sources/images/enemy1.png");
    image_.scaledToWidth(60);
    QVector<QPoint> list = {{5,60}, {1,49}, {1,42}, {15,23}, {35,11}, {64,1}, {95,1}
                            , {129,11}, {129,110}, {95,120}, {64,120}, {29,106},
                            {13,95}, {1,80}, {1,71}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = -500;
    x_coordinate_ = 0;
    y_coordinate_ = 0;
    is_eliminated_ = false;
    shoot_timer_->setInterval(720);
    shoot_timer_->start();
    QObject::connect(shoot_timer_, &QTimer::timeout, this, &EnemyType1::getTimerEvent);
    hp_ = 20;
}
EnemyType1::EnemyType1(int xPos, int yPos, int horizontalSpeed){
    image_ = QPixmap(":/images/sources/images/enemy1.png");
    image_.scaledToWidth(130);
    QVector<QPoint> list = {{5,60}, {1,49}, {1,42}, {15,23}, {35,11}, {64,1}, {95,1}
                            , {129,11}, {129,110}, {95,120}, {64,120}, {29,106},
                            {13,95}, {1,80}, {1,71}};
    hitBox_ = QPolygon(list);
    horizontal_speed_ = horizontalSpeed;
    x_coordinate_ = xPos;
    y_coordinate_ = yPos;
    is_eliminated_ = false;
    shoot_timer_->setInterval(720);
    shoot_timer_->start();
    QObject::connect(shoot_timer_, &QTimer::timeout, this, &EnemyType1::getTimerEvent);
    hp_ = 20;
}

QPolygon EnemyType1::getHitbox(){
    QPolygon result = QPolygon (hitBox_);
    for (int i = 0; i < hitBox_.size(); ++i){
        QPoint p = hitBox_.point(i);
        result.setPoint(i, p.x() + x_coordinate_, p.y() + y_coordinate_);
    }
    return result;
}

void EnemyType1::getTimerEvent(){
    emit bulletInfo(BulletType::EnemyType1, this->x_coordinate_, this->y_coordinate_);
}
