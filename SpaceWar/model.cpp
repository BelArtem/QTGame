#include "model.h"

Model::Model()
{
    hero_ = Hero();
    enemies_ = QVector<Enemy*>(0);
    spawn_enemy_timer_ = new QTimer();
    randomizer_area_height_ = 980;
    area_width_ = 1920;

    QObject::connect(spawn_enemy_timer_, &QTimer::timeout, this, &Model::spawnEnemyTimerEvent);
    spawn_enemy_timer_->setInterval(2000);
    spawn_enemy_timer_->start();
}

Hero& Model::getHero(){
    return hero_;
}

//QVector<Enemy*> Model::getEnemies(){
//    return enemies_;
//}

void Model::spawnEnemyTimerEvent(){
    Enemy* newEnemy = new EnemyType1();

    //possibly here will be generator of enemy type

    //int a = newEnemy->image_.height();
    int randomHeight = qrand() % (981 - newEnemy->image_.height());
    newEnemy->x_coordinate_ = area_width_;
    newEnemy->y_coordinate_ = randomHeight;

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

void Model::clearEnemies(){
    for (int i = 0; i < enemies_.size(); ++i){
       if (enemies_[i]->x_coordinate_ < -enemies_[i]->image_.width()){
            delete enemies_[i];
            enemies_.erase(enemies_.begin() + i);
            --i;
        }
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
