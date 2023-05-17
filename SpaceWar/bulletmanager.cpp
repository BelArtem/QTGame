#include "bulletmanager.h"

BulletManager::BulletManager()
{
    hero_bullets_ = QVector<Bullet*>(0);
    enemy_bullets_ = QVector<Bullet*>(0);
    //bulletsClearTimer_ = new QTimer();


    //bulletsRefreshTimer_ = new QTimer();
    //bulletsRefreshTimer_->setInterval(6);
    //bulletsRefreshTimer_->start();

    //connect(bulletsRefreshTimer_, &QTimer::timeout, this, &BulletManager::updateBulletsCoordinates);
    //connect(bulletsRefreshTimer_, &QTimer::timeout, this, &Scene::updateBullets);
    //connect(bulletsClearTimer_, &QTimer::timeout, this, &Scene::updateBullets);
}


void BulletManager::addBullet(BulletType type,int posX, int posY){
    Bullet* newBullet;
    switch(type)
    {
        case BulletType::Hero:
            newBullet = new HeroBullet(posX, posY);
            hero_bullets_.push_back(newBullet);
        break;
        case BulletType::EnemyType1:
            newBullet = new EnemyBullet(posX, posY);
            enemy_bullets_.push_back(newBullet);
        break;
        default:
            qFatal("fatal error");
    }
}

//QGraphicsItemGroup* BulletManager::getBulletsItemGroup(){
//    QGraphicsItemGroup* result = new QGraphicsItemGroup();
//    QGraphicsPixmapItem* graphicsItem;
//    for (auto& item: bullets_){
//        graphicsItem = new QGraphicsPixmapItem(item->image_);
//        graphicsItem->setPos(item->x_coordinate_, item->y_coordinate_);
//        result->addToGroup(graphicsItem);
//    }
//    return result;
//}

QVector<QGraphicsPixmapItem*> BulletManager::getBulletsPixmapItems(){
    QVector<QGraphicsPixmapItem*> result = QVector<QGraphicsPixmapItem*>(0);
    QGraphicsPixmapItem* graphicsItem;
    for (auto& item: hero_bullets_){
        graphicsItem = new QGraphicsPixmapItem(item->image_);
        graphicsItem->setPos(item->x_coordinate_, item->y_coordinate_);
        result.push_back(graphicsItem);
    }
    return result;
}

void BulletManager::updateBulletsCoordinates(int interval){
    for (auto& item: hero_bullets_){
        item->x_coordinate_ += static_cast<int>(interval / 1000.0 * item->horizontal_speed_);
    }
    for (auto& item: enemy_bullets_){
        item->x_coordinate_ += static_cast<int>(interval / 1000.0 * item->horizontal_speed_);
    }
}

void BulletManager::clearBullets(QGraphicsScene* scene){
    for (int i = 0; i < hero_bullets_.size(); ++i){
        if (hero_bullets_[i]->x_coordinate_ > scene->width()
                + hero_bullets_[i]->image_.width()){
//        if (hero_bullets_[i]->x_coordinate_ > scene->width()/2){
//            hero_bullets_.erase(hero_bullets_.begin() + i);
//            --i;
            //qDebug() <<"Bullet has been deleted"<<hero_bullets_.size();
        }
    }
}
