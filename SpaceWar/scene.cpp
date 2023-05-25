#include "scene.h"


Scene::Scene(QObject* parent): QGraphicsScene(parent)
{
    //model_ = new Model();
    hero_item_ = new QGraphicsPixmapItem(model_.getHero().getPixmap());
    hero_item_->setZValue(3);
    bullets_group_ = new QGraphicsItemGroup();
    bullets_group_->setZValue(0);
    enemies_group_ = new QGraphicsItemGroup();
    enemies_group_->setZValue(1);
    bullet_pixmaps_ = QVector<QGraphicsPixmapItem*>(0);
    enemy_pixmaps_ = QVector<QGraphicsPixmapItem*>(0);
    is_first_shot_ = true;
    health_bar_ = new QProgressBar();
    block_moving_ = false;
    score_ = new Score();
    //bullet_manager_  = new BulletManager();
//    QPixmap im (":/images/sources/images/background.jpg");
//    QGraphicsPixmapItem image (im);
//    this->setSceneRect(0,0,this->width(),this->height());
//    this->addPixmap(im);
//    model_.getHero().setXCoordinate(this->width()/2);
//    model_.getHero().setYCoordinate(this->height()/2);


//    this->addItem(hero_item_);
//    hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());

    move_hero_timer_ = new QTimer();
//    moveHeroTimer_->setInterval(1000/144);
//    moveHeroTimer_->start();
    QObject::connect(move_hero_timer_, &QTimer::timeout, this, &Scene::moveHeroTimerEvent);

    refresh_timer_ = new QTimer();

    //bullets_refresh_timer_ = new QTimer();
//    QObject::connect(bullets_refresh_timer_, &QTimer::timeout, this, &Scene::manageHeroBulletsTimerEvent);
    QObject::connect(refresh_timer_, &QTimer::timeout, this, &Scene::manageHeroBulletsTimerEvent);
    QObject::connect(refresh_timer_, &QTimer::timeout, this, &Scene::manageEnemiesTimerEvent);


    //QObject::connect(bullets_refresh_timer_, &QTimer::timeout, this, &Scene::manageEnemyBulletsTimerEvent);
    //QObject::connect(bulletsRefreshTimer_, &QTimer::timeout, bullet_manager_, &BulletManager::updateBulletsCoordinates);

//    shooting_timer_ = new QTimer();
//    QObject::connect(shooting_timer_, &QTimer::timeout, this, &Scene::heroShootTimerEvent);

    //enemies_refrest_timer_ = new QTimer();
//    QObject::connect(enemies_refrest_timer_, &QTimer::timeout, this, &Scene::manageEnemiesTimerEvent);

    intersections_refresh_timer_ = new QTimer();
    QObject::connect(intersections_refresh_timer_, &QTimer::timeout, this, &Scene::manageIntersections);

    QObject::connect(&model_.getHero(), &Hero::isDestroyed, this, &Scene::stopGame);
    //QObject::connect(&model_, &Model::enemyPassed, this, &Scene::decreaseScore);

    QObject::connect(score_, &Score::makeMoreDifficult, &model_, &Model::increaseSpawnSpeed);

    this->setUpScene();

    //QGraphicsItemGroup* result = new QGraphicsItemGroup();
//    HeroBullet* bul = new HeroBullet();
//    QGraphicsPixmapItem* graphicsItem;
//    graphicsItem = new QGraphicsPixmapItem(bul->image_);
//    graphicsItem->setPos(100, 100);
//    bullets_group_->addToGroup(graphicsItem);
//    this->addItem(bullets_group_);
}

void Scene::setUpScene(){
    QPixmap im (":/images/sources/images/background.jpg");
    QGraphicsPixmapItem image (im);
    //this->setSceneRect(0,0,this->width(),this->height());
    this->addPixmap(im);
    model_.getHero().setXCoordinate(this->width()/2);
    model_.getHero().setYCoordinate(this->height()/2);
    this->addItem(hero_item_);
    hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
    move_hero_timer_->setInterval(6);
    move_hero_timer_->start();

//    bullets_refresh_timer_->setInterval(3);
//    bullets_refresh_timer_->start();
    refresh_timer_->setInterval(3);
    refresh_timer_->start();
//    shooting_timer_->setInterval(400);
//    shooting_timer_->start();


//    enemies_refrest_timer_->setInterval(3);
//    enemies_refrest_timer_->start();
    intersections_refresh_timer_->setInterval(6);
    intersections_refresh_timer_->start();

    health_bar_->setOrientation(Qt::Horizontal);
    health_bar_->setRange(0,100);
    health_bar_->setValue(100);
    health_bar_->setAlignment(Qt::AlignTop);
    health_bar_->setAlignment(Qt::AlignLeft);
    //QWidget* wid = new QWidget();
    //health_bar_.
    health_bar_->move(10,10);
    //health_bar_->setTextVisible(false);
    //health_bar_
    health_bar_->setStyleSheet("QProgressBar {"
                 "background-color: #74c8ff;"
                 "color: #0a9dff;"
                 "border-style: outset;"
                 "border-width: 2px;"
                 "border-color: #74c8ff;"
                 "border-radius: 7px;"
                 "text-align: right; }"

                 "QProgressBar::chunk {"
                 "background-color: #010327; }");
    //health_bar_->setValue(90);
    this->addWidget(health_bar_);
    this->addItem(score_);
    //int a = score_->textWidth();
    score_->setPos(this->width() - 200, 0);


}


void Scene::keyPressEvent(QKeyEvent *event){
    if (block_moving_){
        keys_[event->key()] = false;
        return;
    }
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_A ||
            event->key() == Qt::Key_S || event->key() == Qt::Key_D){
        keys_[event->key()] = true;
    }
//    if (event->key() == Qt::Key_Space){
//        if (is_first_shot_){
//            //int xPos = model_.getHero().getXCoordinate() + model_.getHero().getPixmap().width()- 40;
//            //int yPos = model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2 - 60;
//            //bullet_manager_.addBullet(BulletType::Hero, xPos, yPos);
//            is_first_shot_ = false;
//            shooting_limit_timer_->start(1);
//        }
//        keys_[event->key()] = true;
//        shooting_limit_timer_->start(200);


//        //vvvvvvvvvvvv
////        if(isFirstShot_){
////            int xPos = model_.getHero().getXCoordinate() + model_.getHero().getPixmap().width()- 40;
////            int yPos = model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2 - 60;
////            bullet_manager_.addBullet(BulletType::Hero, xPos, yPos);
////            isFirstShot_ = false;
////            //shootingLimitTimer_->start();

////        }
////        else {
////            shootingLimitTimer_->start();
////        }
//        //vvvvvvvvvvvv
//        //shootingLimitTimer_->start();
//    }
//    if (event->key() == Qt::Key_Space){
//        bullet_manager_.addBullet(BulletType::Hero, model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2);
//        //int bulletXCoordinate =
//    }
    QGraphicsScene::keyPressEvent(event);
}
void Scene::keyReleaseEvent(QKeyEvent *event){
    keys_[event->key()] = false;
//    if (event->key() == Qt::Key_Space){
//        is_first_shot_ = true;
       // shooting_limit_timer_->stop();

        //vvvvvvvvvvvvvvv
//        isFirstShot_ = true;
//        shootingLimitTimer_->stop();
        //vvvvvvvvvvvvvvv
        //shootingLimitTimer_->stop();
 //   }

    QGraphicsScene::keyReleaseEvent(event);
}


void Scene::moveHeroTimerEvent(){
    int currentXSpeed = 0;
    int currentYSpeed = 0;
    int newXCoordinate = 0;
    int newYCoordinate = 0;

    if(keys_[Qt::Key_W]){
        currentYSpeed -= model_.getHero().getVerticalSpeed();
    }
    if(keys_[Qt::Key_S]){
        currentYSpeed += model_.getHero().getVerticalSpeed();

    }
    if(keys_[Qt::Key_A]){
        currentXSpeed -= model_.getHero().getHorizontalSpeed();
    }
    if(keys_[Qt::Key_D]){
        currentXSpeed += model_.getHero().getHorizontalSpeed();
    }

    if (abs(currentXSpeed) + abs(currentYSpeed) > fmax(model_.getHero().getHorizontalSpeed(), model_.getHero().getHorizontalSpeed())){
        newXCoordinate = model_.getHero().getXCoordinate() + static_cast<int>(currentXSpeed * move_hero_timer_->interval() / 1000.0 / sqrt(2));
        newYCoordinate = model_.getHero().getYCoordinate() + static_cast<int>(currentYSpeed * move_hero_timer_->interval() / 1000.0 / sqrt(2));
    }else {
        newXCoordinate = model_.getHero().getXCoordinate() + static_cast<int>(currentXSpeed * move_hero_timer_->interval() / 1000.0);
        newYCoordinate = model_.getHero().getYCoordinate() + static_cast<int>(currentYSpeed * move_hero_timer_->interval() / 1000.0);
    }

    if (newXCoordinate > this->width() - model_.getHero().getPixmap().width() / 2  || newXCoordinate < - model_.getHero().getPixmap().width() / 2){
        newXCoordinate = model_.getHero().getXCoordinate();
    }

    if (newYCoordinate > this->height() - model_.getHero().getPixmap().height() / 2|| newYCoordinate < -model_.getHero().getPixmap().height() / 2){
        newYCoordinate = model_.getHero().getYCoordinate();
    }
    model_.getHero().setXCoordinate(newXCoordinate);
    model_.getHero().setYCoordinate(newYCoordinate);

    hero_item_->setPos(newXCoordinate,newYCoordinate);
}

//void Scene::heroShootTimerEvent(){
////    if (keys_[Qt::Key_Space]){
//        int xPos = model_.getHero().getXCoordinate() + model_.getHero().getPixmap().width()- 40;
//        int yPos = model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2 - 60;
//        model_.getBulletManager()->addBullet(BulletType::Hero, xPos, yPos);
////    }
//}

//void Scene::manageBulletsTimerEvent(){
//    bullet_manager_.updateBulletsCoordinates(bulletsRefreshTimer_->interval());
//    this->removeItem(bullets_group_);
//    bullets_group_ = bullet_manager_.getBulletsItemGroup();
//    this->addItem(bullets_group_);
//}

void Scene::manageHeroBulletsTimerEvent(){
    if (model_.getBulletManager()->getHeroBulletsAmount() == 0 &&
           model_.getBulletManager()->getEnemyBulletsAmount() == 0 ){
        return;
    }

//    if (model_.getBulletManager()->getEnemyBulletsAmount() == 0){
//        return;
//    }


    QVector<QGraphicsPixmapItem*> vec = model_.getBulletManager()->getBulletsPixmapItems();
    for (auto& item: vec){
        bullets_group_->removeFromGroup(item);
    }
    for (int i = 0; i < vec.size(); ++i){
        delete vec[i];
    }
   vec.clear();


//    model_.getBulletManager()->updateBulletsCoordinates(bullets_refresh_timer_->interval());
   model_.getBulletManager()->updateBulletsCoordinates(refresh_timer_->interval());
    model_.getBulletManager()->clearBullets(this);
    //this->removeItem(bullets_group_);
    //this->destroyItemGroup(bullets_group_);
    //delete bullets_group_;
    //bullets_group_.
    //bullets_group_ = new QGraphicsItemGroup();
    //bullet_pixmaps_.clear();
//    for (auto& item: bullet_pixmaps_){
//        delete item;
//    }
    for (int i = 0; i < bullet_pixmaps_.size(); ++i){
        delete bullet_pixmaps_[i];
    }
    bullet_pixmaps_.clear();
//    if (bullet_manager_.hero_bullets_.size() > 0){
//        QPen(QColor(Qt::green), 2);
//        this->addPolygon(bullet_manager_.hero_bullets_[0]->getHitbox());
//    }

    bullet_pixmaps_ = model_.getBulletManager()->getBulletsPixmapItems();
    for (auto& item: bullet_pixmaps_){
        bullets_group_->addToGroup(item);
    }
    this->addItem(bullets_group_);
}

void Scene::manageEnemiesTimerEvent(){
    if (model_.getEnemiesAmount() == 0){
        return;
    }
    QVector<QGraphicsPixmapItem*> vec = model_.getEnemiesPixmapItems();
    for (auto& item: vec){
        enemies_group_->removeFromGroup(item);
    }
    for (int i = 0; i < vec.size(); ++i){
        delete vec[i];
    }
    vec.clear();


//    model_.updateEnemiesCoordinates(enemies_refrest_timer_->interval());
    model_.updateEnemiesCoordinates(refresh_timer_->interval());
    model_.clearEnemies();
    for (int i = 0; i < enemy_pixmaps_.size(); ++i){
        delete enemy_pixmaps_[i];
    }
    enemy_pixmaps_.clear();
    enemy_pixmaps_ = model_.getEnemiesPixmapItems();
    for (auto& item: enemy_pixmaps_){
        enemies_group_->addToGroup(item);
    }
    this->addItem(enemies_group_);
}



//void Scene::manageEnemyBulletsTimerEvent(){
////    if (bullet_manager_.getEnemyBulletsAmount() == 0){
////        return;
////    }
//    QVector<QGraphicsPixmapItem*> vec = bullet_manager_.getBulletsPixmapItems();
//    for (auto& item: vec){
//        bullets_group_->removeFromGroup(item);
//    }
//    for (int i = 0; i < vec.size(); ++i){
//        delete vec[i];
//    }
//   vec.clear();


//    //QVector<Bullet*>* bullets = model_.getAllEnemyBullets();
//   QVector<Bullet*> bullets;
//   model_.getAllEnemyBullets(bullets);
//    for (auto& bul: bullets){
//        //bullet_manager_.addEnemyBullet(bul);
//        bullet_manager_.addBullet(BulletType::EnemyType1, bul->x_coordinate_, bul->y_coordinate_);
//    }
//    if (bullet_manager_.getEnemyBulletsAmount() == 0){
//        return;
//    }
//    bullet_manager_.updateBulletsCoordinates(bullets_refresh_timer_->interval());
//    bullet_manager_.clearBullets(this);

//    //Bullet* bul = bullet_manager_.enemy_bullets_[0];

//    for (int i = 0; i < bullet_pixmaps_.size(); ++i){
//        delete bullet_pixmaps_[i];
//    }
//    bullet_pixmaps_.clear();
////    if (bullet_manager_.hero_bullets_.size() > 0){
////        QPen(QColor(Qt::green), 2);
////        this->addPolygon(bullet_manager_.hero_bullets_[0]->getHitbox());
////    }

//    bullet_pixmaps_ = bullet_manager_.getBulletsPixmapItems();
//    for (auto& item: bullet_pixmaps_){
//        bullets_group_->addToGroup(item);
//    }
//    //this->addItem(bullets_group_);


//    //this->addPixmap(bul->image_);
//}

//void Scene::manageIntersections(){
//    QPolygon enemyHitBox;
//    QPolygon bulletHitBox;
//    QVector<Enemy*> enemies = model_.getEnemies();
//    QVector<Bullet*> bullets = model_.getBulletManager()->getHeroBullets();
//    bool isHit = false;
//    for (int i = 0; i < enemies.size(); ++i){
//        enemyHitBox = enemies[i]->getHitbox();
//        isHit = false;
//        for (int j = 0; j < bullets.size(); ++j){
//            bulletHitBox = bullets[j]->getHitbox();
//            if (enemyHitBox.intersects(bulletHitBox)){
//                isHit = true;
//                delete bullets[j];
//                bullets.erase(bullets.begin() + j);
//                break;
//            }
//        }
//        if (isHit){
//            delete enemies[i];
//            enemies.erase(enemies.begin() + i);
//            --i;
//            continue;
//        }
//    }

//}

void Scene::manageIntersections(){
    QPolygon shipHitbox;
    QPolygon bulletHitBox;
    QVector<Enemy*> enemies = model_.getEnemies();
    QVector<Bullet*> bullets = model_.getBulletManager()->getHeroBullets();
    for (int i = 0; i < enemies.size(); ++i){
        shipHitbox = enemies[i]->getHitbox();
        for (int j = 0; j < bullets.size(); ++j){
            bulletHitBox = bullets[j]->getHitbox();
            if (shipHitbox.intersects(bulletHitBox)){
                enemies[i]->hp_ -= bullets[j]->damage_;
                score_->addScore(1);
                if (enemies[i]->hp_ <= 0){
                    enemies[i]->is_eliminated_ = true;
                    score_->addScore(1);

                }
                bullets[j]->is_eliminated_ = true;
                break;
            }
        }
    }
    Hero& hero = model_.getHero();
    shipHitbox = model_.getHero().getHitBox();
    bullets = model_.getBulletManager()->getEnemyBullets();
    for (int i = 0; i < bullets.size(); ++i){
        bulletHitBox = bullets[i]->getHitbox();
        if (shipHitbox.intersects(bulletHitBox)){
            //int dam = bullets[i]->damage_;
            hero.setHP(hero.getHP() - bullets[i]->damage_);
            if (hero.getHP() >= 0){
                health_bar_->setValue(hero.getHP());
            }/*else {
                health_bar_->setValue(0);
            }*/
            if (hero.getHP() <= 0){
                hero.setEliminated(true);
            }
            bullets[i]->is_eliminated_ = true;
            break;
        }
    }
}

void Scene::stopGame(){
//    this->removeItem(hero_item_);
//    delete hero_item_;
    refresh_timer_->stop();
    //shooting_timer_->stop();
    intersections_refresh_timer_->stop();
    model_.stopAllEvents();
    block_moving_ = true;
    keys_[Qt::Key_W] = false;
    keys_[Qt::Key_A] = false;
    keys_[Qt::Key_S] = false;
    keys_[Qt::Key_D] = false;


    //delete model_.getHero();
    //    model_.updateEnemiesCoordinates(enemies_refrest_timer_->interval());
}

//void Scene::manageHeroTimerEvent(){
//    if (model_.getEnemiesAmount() == 0){
//        return;
//    }
//    QVector<QGraphicsPixmapItem*> vec = model_.getEnemiesPixmapItems();
//    for (auto& item: vec){
//        enemies_group_->removeFromGroup(item);
//    }
//    for (int i = 0; i < vec.size(); ++i){
//        delete vec[i];
//    }
//    vec.clear();


////    model_.updateEnemiesCoordinates(enemies_refrest_timer_->interval());
//    model_.updateEnemiesCoordinates(refresh_timer_->interval());
//    model_.clearEnemies();
//    for (int i = 0; i < enemy_pixmaps_.size(); ++i){
//        delete enemy_pixmaps_[i];
//    }
//    enemy_pixmaps_.clear();
//    enemy_pixmaps_ = model_.getEnemiesPixmapItems();
//    for (auto& item: enemy_pixmaps_){
//        enemies_group_->addToGroup(item);
//    }
//    this->addItem(enemies_group_);
//}

//void Scene::decreaseScore(){
//    score_->addScore(-1);
//}
