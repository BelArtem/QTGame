#include "bulletmanager.h"

BulletManager::BulletManager()
{
    hero_bullets_ = QVector<Bullet*>(0);
    enemy_bullets_ = QVector<Bullet*>(0);
}

void BulletManager::addBullet(BulletType type,int posX, int posY){
    Bullet* newBullet = nullptr;
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

QVector<QGraphicsPixmapItem*> BulletManager::getBulletsPixmapItems(){
    QVector<QGraphicsPixmapItem*> result = QVector<QGraphicsPixmapItem*>(0);
    QGraphicsPixmapItem* graphicsItem;
    for (auto& item: hero_bullets_){
        graphicsItem = new QGraphicsPixmapItem(item->image_);
        graphicsItem->setPos(item->x_coordinate_, item->y_coordinate_);
        result.push_back(graphicsItem);
    }
    for (auto& item: enemy_bullets_){
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

void BulletManager::clearUnusedBullets(QGraphicsScene* scene){
    for (int i = 0; i < hero_bullets_.size(); ++i){
        if (hero_bullets_[i]->x_coordinate_ > scene->width() || hero_bullets_[i]->is_eliminated_){
            delete hero_bullets_[i];
            hero_bullets_.erase(hero_bullets_.begin() + i);
            --i;
        }
    }
    for (int i = 0; i < enemy_bullets_.size(); ++i){
        if (enemy_bullets_[i]->x_coordinate_ < -enemy_bullets_[i]->image_.width()
                || enemy_bullets_[i]->is_eliminated_){
            delete enemy_bullets_[i];
            enemy_bullets_.erase(enemy_bullets_.begin() + i);
            --i;
        }
    }
}

void BulletManager::clearAllBullets(){
    for (int i = 0; i < hero_bullets_.size(); ++i){
        delete hero_bullets_[i];
        hero_bullets_.erase(hero_bullets_.begin() + i);
        --i;
    }
    for (int i = 0; i < enemy_bullets_.size(); ++i){
        delete enemy_bullets_[i];
        enemy_bullets_.erase(enemy_bullets_.begin() + i);
        --i;
    }
}

size_t BulletManager::getHeroBulletsAmount(){
    return hero_bullets_.size();
}

size_t BulletManager::getEnemyBulletsAmount(){
    return enemy_bullets_.size();
}

void BulletManager::addBulletEvent(BulletType type,int posX, int posY){
    this->addBullet(type, posX, posY);
}

QVector<Bullet*>& BulletManager::getHeroBullets(){
    return hero_bullets_;
}

QVector<Bullet*>& BulletManager::getEnemyBullets(){
    return enemy_bullets_;
}
