#include "enemy.h"

Enemy::Enemy()
{
    shoot_timer_ = new QTimer();
}

void Enemy::startShootTimer(){
    shoot_timer_->start();
}
void Enemy::stopShootTimer(){
    shoot_timer_->stop();
}
