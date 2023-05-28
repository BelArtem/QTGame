#include "model.h"

Model::Model()
{
    enemies_ = QVector<Enemy*>(0);
    spawn_enemy_timer_ = new QTimer();
    randomizer_area_height_ = 980;
    area_width_ = 1920;
    generator_ = EnemyGenerator();

    QObject::connect(spawn_enemy_timer_, &QTimer::timeout, this, &Model::spawnEnemyTimerEvent);
    spawn_enemy_timer_->setInterval(2000);
}

Hero& Model::getHero(){
    return hero_;
}

void Model::spawnEnemyTimerEvent(){
    EnemyType type = EnemyType::EnemyType1;
    Enemy* newEnemy = generator_.generateEnemy(type, area_width_);
    EnemyType1* enemy = dynamic_cast<EnemyType1*>(newEnemy);
    if (enemy != nullptr){
        QObject::connect(enemy, &EnemyType1::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
    }
    enemies_.push_back(newEnemy);
}

QVector<QGraphicsPixmapItem*> Model::getEnemiesPixmapItems(){
    QVector<QGraphicsPixmapItem*> result = QVector<QGraphicsPixmapItem*>(0);
    QGraphicsPixmapItem* graphicsItem;
    for (auto& item: enemies_){
        graphicsItem = new QGraphicsPixmapItem(item->image_);
        graphicsItem->setPos(item->x_coordinate_, item->y_coordinate_);
        result.push_back(graphicsItem);
    }
    return result;
}

void Model::updateEnemiesCoordinates(int interval){
    for (auto& item: enemies_){
        item->x_coordinate_ += static_cast<int>(interval / 1000.0 * item->horizontal_speed_);
    }
}

void Model::clearUnusedEnemies(){
    for (int i = 0; i < enemies_.size(); ++i){
        if (enemies_[i]->x_coordinate_ < -enemies_[i]->image_.width() || enemies_[i]->is_eliminated_){
            EnemyType1* enemy = dynamic_cast<EnemyType1*>(enemies_[i]);
            if (enemy != nullptr){
                QObject::disconnect(enemy, &EnemyType1::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
            }
            delete enemies_[i];
            enemies_.erase(enemies_.begin() + i);
            --i;
        }
    }
}

void Model::clearAllEnemies(){
    for (int i = 0; i < enemies_.size(); ++i){
        EnemyType1* enemy = dynamic_cast<EnemyType1*>(enemies_[i]);
        if (enemy != nullptr){
            QObject::disconnect(enemy, &EnemyType1::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
        }
        delete enemies_[i];
        enemies_.erase(enemies_.begin() + i);
        --i;
    }
}

void Model::setRandomizerAreaHeight(int height){
    randomizer_area_height_ = height;
}
void Model::setAreaWidth(int width){
    area_width_ = width;
}

size_t Model::getEnemiesAmount(){
    return enemies_.size();
}

BulletManager* Model::getBulletManager(){
    return &bullet_manager_;
}

QVector<Enemy*>& Model::getEnemies(){
    return enemies_;
}

void Model::startSpawnTimer(){
    spawn_enemy_timer_->start();
}

void Model::stopSpawnTimer(){
    spawn_enemy_timer_->stop();
}

void Model::stopAllEvents(){
    spawn_enemy_timer_->stop();
    for (auto& enemy: enemies_){
        enemy->stopShootTimer();
    }
}

void Model::increaseSpawnSpeed(int millisec){
    if (spawn_enemy_timer_->interval() < 800){
        return;
    }
    spawn_enemy_timer_->setInterval(spawn_enemy_timer_->interval() - millisec);
}

Model::~Model(){
    delete spawn_enemy_timer_;
}
