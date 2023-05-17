#include "scene.h"


Scene::Scene(QObject* parent): QGraphicsScene(parent)
{
    hero_item_ = new QGraphicsPixmapItem(model_.getHero().getPixmap());
    bullets_group_ = new QGraphicsItemGroup();
    enemies_group_ = new QGraphicsItemGroup();
    bullet_pixmaps_ = QVector<QGraphicsPixmapItem*>(0);
    enemy_pixmaps_ = QVector<QGraphicsPixmapItem*>(0);
    //bullet_manager_  = new BulletManager();
//    QPixmap im (":/images/sources/images/background.jpg");
//    QGraphicsPixmapItem image (im);
//    this->setSceneRect(0,0,this->width(),this->height());
//    this->addPixmap(im);
//    model_.getHero().setXCoordinate(this->width()/2);
//    model_.getHero().setYCoordinate(this->height()/2);


//    this->addItem(hero_item_);
//    hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());

    moveHeroTimer_ = new QTimer();
//    moveHeroTimer_->setInterval(1000/144);
//    moveHeroTimer_->start();
    QObject::connect(moveHeroTimer_, &QTimer::timeout, this, &Scene::moveHeroTimerEvent);

    bulletsRefreshTimer_ = new QTimer();
    QObject::connect(bulletsRefreshTimer_, &QTimer::timeout, this, &Scene::manageBulletsTimerEvent);
    //QObject::connect(bulletsRefreshTimer_, &QTimer::timeout, bullet_manager_, &BulletManager::updateBulletsCoordinates);

    shootingLimitTimer_ = new QTimer();
    QObject::connect(shootingLimitTimer_, &QTimer::timeout, this, &Scene::heroShootTimerEvent);


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
    moveHeroTimer_->setInterval(6);
    moveHeroTimer_->start();
    bulletsRefreshTimer_->setInterval(3);
    bulletsRefreshTimer_->start();
    shootingLimitTimer_->setInterval(80);
    shootingLimitTimer_->start();

}
//void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
////    if(event->button() == Qt::LeftButton){
////        //keys_[event->button()] = true;
////        bullet_manager_.addBullet(BulletType::Hero, model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2);
////    }
//}

void Scene::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_A ||
            event->key() == Qt::Key_S || event->key() == Qt::Key_D){
        keys_[event->key()] = true;
    }
    if (event->key() == Qt::Key_Space){
        keys_[event->key()] = true;
        //shootingLimitTimer_->start();
    }
//    if (event->key() == Qt::Key_Space){
//        bullet_manager_.addBullet(BulletType::Hero, model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2);
//        //int bulletXCoordinate =
//    }
    QGraphicsScene::keyPressEvent(event);
    //QGraphicsPixmapItem* image = new QGraphicsPixmapItem(QPixmap(":/images/sources/images/hero.png"));
    //this->addItem(image);
    //image->setSelected()
    //image->setPos(0,100);
//    if(event->key() == Qt::Key_W && event->key() == Qt::Key_A){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() - model_.getHero().getVerticalSpeed());
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() - model_.getHero().getHorizontalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//        return;
//    }
//    if(event->key() == Qt::Key_W){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() - model_.getHero().getVerticalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//        return;
//    }
//    if(event->key() == Qt::Key_S){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() + model_.getHero().getVerticalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//        return;

////        model_.getHero().setXCoordinate(this->width()/2);
////        model_.getHero().setYCoordinate(this->height()/2 - 5);

//        //this->removeItem(hero_item_);
//        //QTimer timer;
//        //QGraphicsPixmapItem* image = new QGraphicsPixmapItem(QPixmap(":/images/sources/images/hero.png"));
//        //this->addItem(image);
//        //image->setPos(0,100);
//        //this->removeItem(image);

//    }
//    if(event->key() == Qt::Key_A){
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() - model_.getHero().getHorizontalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//        return;
//    }
//    if(event->key() == Qt::Key_D){
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() + model_.getHero().getHorizontalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//        return;
//    }

}
void Scene::keyReleaseEvent(QKeyEvent *event){
    keys_[event->key()] = false;
    if (event->key() == Qt::Key_Space){
        //shootingLimitTimer_->stop();
    }

    QGraphicsScene::keyReleaseEvent(event);
}


void Scene::moveHeroTimerEvent(){

//previous speed system
//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
//    if(keys_[Qt::Key_W]){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() - model_.getHero().getVerticalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//    }
//    if(keys_[Qt::Key_S]){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() + model_.getHero().getVerticalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());

////        model_.getHero().setXCoordinate(this->width()/2);
////        model_.getHero().setYCoordinate(this->height()/2 - 5);

//        //this->removeItem(hero_item_);
//        //QTimer timer;
//        //QGraphicsPixmapItem* image = new QGraphicsPixmapItem(QPixmap(":/images/sources/images/hero.png"));
//        //this->addItem(image);
//        //image->setPos(0,100);
//        //this->removeItem(image);

//    }
//    if(keys_[Qt::Key_A]){
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() - model_.getHero().getHorizontalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//    }
//    if(keys_[Qt::Key_D]){
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() + model_.getHero().getHorizontalSpeed());
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//    }
//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
    int currentXSpeed = 0;
    int currentYSpeed = 0;
    int newXCoordinate = 0;
    int newYCoordinate = 0;
//    if(keys_[Qt::Key_W]){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() - static_cast<int>(model_.getHero().getVerticalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//    }
//    if(keys_[Qt::Key_S]){
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() + static_cast<int>(model_.getHero().getVerticalSpeed() * moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());

////        model_.getHero().setXCoordinate(this->width()/2);
////        model_.getHero().setYCoordinate(this->height()/2 - 5);

//        //this->removeItem(hero_item_);
//        //QTimer timer;
//        //QGraphicsPixmapItem* image = new QGraphicsPixmapItem(QPixmap(":/images/sources/images/hero.png"));
//        //this->addItem(image);
//        //image->setPos(0,100);
//        //this->removeItem(image);

//    }
//    if(keys_[Qt::Key_A]){
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() - static_cast<int>(model_.getHero().getHorizontalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//    }
//    if(keys_[Qt::Key_D]){
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() + static_cast<int>(model_.getHero().getHorizontalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
//    }

    if(keys_[Qt::Key_W]){
        currentYSpeed -= model_.getHero().getVerticalSpeed();
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() - static_cast<int>(model_.getHero().getVerticalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
        //return;
    }
    if(keys_[Qt::Key_S]){
        currentYSpeed += model_.getHero().getVerticalSpeed();
//        model_.getHero().setYCoordinate(model_.getHero().getYCoordinate() + static_cast<int>(model_.getHero().getVerticalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
        //return;

//        model_.getHero().setXCoordinate(this->width()/2);
//        model_.getHero().setYCoordinate(this->height()/2 - 5);

        //this->removeItem(hero_item_);
        //QTimer timer;
        //QGraphicsPixmapItem* image = new QGraphicsPixmapItem(QPixmap(":/images/sources/images/hero.png"));
        //this->addItem(image);
        //image->setPos(0,100);
        //this->removeItem(image);

    }
    if(keys_[Qt::Key_A]){
        currentXSpeed -= model_.getHero().getHorizontalSpeed();
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() - static_cast<int>(model_.getHero().getHorizontalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
    }
    if(keys_[Qt::Key_D]){
        currentXSpeed += model_.getHero().getHorizontalSpeed();
//        model_.getHero().setXCoordinate(model_.getHero().getXCoordinate() + static_cast<int>(model_.getHero().getHorizontalSpeed()* moveHeroTimer_->interval() / 1000.0));
//        hero_item_->setPos(model_.getHero().getXCoordinate(),model_.getHero().getYCoordinate());
    }
    if (abs(currentXSpeed) + abs(currentYSpeed) > fmax(model_.getHero().getHorizontalSpeed(), model_.getHero().getHorizontalSpeed())){
        newXCoordinate = model_.getHero().getXCoordinate() + static_cast<int>(currentXSpeed * moveHeroTimer_->interval() / 1000.0 / sqrt(2));
        newYCoordinate = model_.getHero().getYCoordinate() + static_cast<int>(currentYSpeed * moveHeroTimer_->interval() / 1000.0 / sqrt(2));
    }else {
        newXCoordinate = model_.getHero().getXCoordinate() + static_cast<int>(currentXSpeed * moveHeroTimer_->interval() / 1000.0);
        newYCoordinate = model_.getHero().getYCoordinate() + static_cast<int>(currentYSpeed * moveHeroTimer_->interval() / 1000.0);
    }
//    if (newXCoordinate > this->width() || newXCoordinate < -model_.getHero().getPixmap().width()){
//        newXCoordinate = model_.getHero().getXCoordinate();
//    }
    if (newXCoordinate > this->width() - model_.getHero().getPixmap().width() / 2  || newXCoordinate < - model_.getHero().getPixmap().width() / 2){
        newXCoordinate = model_.getHero().getXCoordinate();
    }
//    if (newYCoordinate > this->height() || newYCoordinate < -model_.getHero().getPixmap().height()){
//        newYCoordinate = model_.getHero().getYCoordinate();
//    }
    if (newYCoordinate > this->height() - model_.getHero().getPixmap().height() / 2|| newYCoordinate < -model_.getHero().getPixmap().height() / 2){
        newYCoordinate = model_.getHero().getYCoordinate();
    }
    model_.getHero().setXCoordinate(newXCoordinate);
    model_.getHero().setYCoordinate(newYCoordinate);

    hero_item_->setPos(newXCoordinate,newYCoordinate);

}

void Scene::heroShootTimerEvent(){
    if (keys_[Qt::Key_Space]){
        int xPos = model_.getHero().getXCoordinate() + model_.getHero().getPixmap().width()- 40;
        int yPos = model_.getHero().getYCoordinate() + model_.getHero().getPixmap().height() / 2 - 60;
        bullet_manager_.addBullet(BulletType::Hero, xPos, yPos);
    }
}

//void Scene::manageBulletsTimerEvent(){
//    bullet_manager_.updateBulletsCoordinates(bulletsRefreshTimer_->interval());
//    this->removeItem(bullets_group_);
//    bullets_group_ = bullet_manager_.getBulletsItemGroup();
//    this->addItem(bullets_group_);
//}

void Scene::manageBulletsTimerEvent(){
    bullet_manager_.updateBulletsCoordinates(bulletsRefreshTimer_->interval());
    bullet_manager_.clearBullets(this);
    this->removeItem(bullets_group_);
    this->destroyItemGroup(bullets_group_);
    bullets_group_ = new QGraphicsItemGroup();
    //bullet_pixmaps_.clear();
//    for (auto& item: bullet_pixmaps_){
//        delete item;
//    }
    for (int i = 0; i < bullet_pixmaps_.size(); ++i){
        delete bullet_pixmaps_[i];
    }

    bullet_pixmaps_ = bullet_manager_.getBulletsPixmapItems();
    for (auto& item: bullet_pixmaps_){
        bullets_group_->addToGroup(item);
    }
    this->addItem(bullets_group_);
}
