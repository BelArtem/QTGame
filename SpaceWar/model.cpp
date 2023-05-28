#include "model.h"

Model::Model()
{
    //hero_ = Hero();
    enemies_ = QVector<Enemy*>(0);
    spawn_enemy_timer_ = new QTimer();
    randomizer_area_height_ = 980;
    area_width_ = 1920;
    generator_ = EnemyGenerator();

    QObject::connect(spawn_enemy_timer_, &QTimer::timeout, this, &Model::spawnEnemyTimerEvent);
    //spawn_enemy_timer_->setInterval(2000);
    spawn_enemy_timer_->setInterval(2000);
    //spawn_enemy_timer_->start();

    //QObject::connect(&hero_, &Hero::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
}

Hero& Model::getHero(){
    return hero_;
}

//QVector<Enemy*> Model::getEnemies(){
//    return enemies_;
//}

void Model::spawnEnemyTimerEvent(){
    //    Enemy* newEnemy = new EnemyType1();

    //    //possibly here will be generator of enemy type

    //    //int a = newEnemy->image_.height();
    //    int randomHeight = qrand() % (981 - newEnemy->image_.height());
    //    newEnemy->x_coordinate_ = area_width_;
    //    newEnemy->y_coordinate_ = randomHeight;

    //    enemies_.push_back(newEnemy);
    EnemyType type = EnemyType::EnemyType1;
    Enemy* newEnemy = generator_.generateEnemy(type, area_width_);
    //    QObject::connect(newEnemy->shoot_timer_, &QTimer::timeout, &bullet_manager_, &BulletManager::addEnemyBulletEvent);
    EnemyType1* enemy = dynamic_cast<EnemyType1*>(newEnemy);
    if (enemy != nullptr){
        QObject::connect(enemy, &EnemyType1::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
    }


    //newEnemy->shoot_timer_->start();
    enemies_.push_back(newEnemy);

    //enemies_.push_back(generator_.generateEnemy(EnemyType::EnemyType1, area_width_));
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
        //       if (enemies_[i]->x_coordinate_ < -enemies_[i]->image_.width()){
        //            emit enemyPassed();
        //        }
        if (enemies_[i]->x_coordinate_ < -enemies_[i]->image_.width() || enemies_[i]->is_eliminated_){
            EnemyType1* enemy = dynamic_cast<EnemyType1*>(enemies_[i]);
            if (enemy != nullptr){
                QObject::disconnect(enemy, &EnemyType1::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
            }
            //QObject::disconnect(enemies_[i], &Enemy::BulletInfo, &bullet_manager_, &BulletManager::addEnemyBulletEvent);
            delete enemies_[i];
            enemies_.erase(enemies_.begin() + i);
            --i;
        }
    }
}

void Model::clearAllEnemies(){
    for (int i = 0; i < enemies_.size(); ++i){
        //       if (enemies_[i]->x_coordinate_ < -enemies_[i]->image_.width()){
        //            emit enemyPassed();
        //        }
        EnemyType1* enemy = dynamic_cast<EnemyType1*>(enemies_[i]);
        if (enemy != nullptr){
            QObject::disconnect(enemy, &EnemyType1::bulletInfo, &bullet_manager_, &BulletManager::addBulletEvent);
        }
        //QObject::disconnect(enemies_[i], &Enemy::BulletInfo, &bullet_manager_, &BulletManager::addEnemyBulletEvent);
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

//QVector<Bullet*>* Model::getAllEnemyBullets(){
//    QVector<Bullet*>* result = new QVector<Bullet*>(0);
//    QVector<Bullet*> vec;
//    for (auto& enemy: enemies_){
//        vec = enemy->getBullets();
//        if (enemy->bullets_.size() > 0){
//            for (int i = 0; i < vec.size(); ++i){
//                result->push_back(vec[i]);
//            }
//        }
//        enemy->clearBullets();
//    }
//    return result;
//}

//void Model::getAllEnemyBullets(QVector<Bullet*>& vec){
//    QVector<Bullet*> bullets;
//    for (auto& enemy: enemies_){
//        bullets = enemy->getBullets();
//        if (enemy->bullets_.size() > 0){
//            for (int i = 0; i < enemy->getBullets().size(); ++i){
//                vec.push_back(enemy->getBullets()[i]);
//            }
//        }
//        enemy->clearBullets();
//    }
//}

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
    //hero_.stopShootingTimer();
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
