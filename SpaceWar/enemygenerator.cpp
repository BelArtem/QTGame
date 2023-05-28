#include "enemygenerator.h"
#include <QRandomGenerator>

EnemyGenerator::EnemyGenerator()
{

}


Enemy* EnemyGenerator::generateEnemy(EnemyType type, int xPos){
    Enemy* newEnemy = nullptr;
    switch(type)
    {
        case EnemyType::EnemyType1:
            newEnemy = new EnemyType1();
            break;
        default:
            qFatal("fatal error");
    }
    //int randomHeight = qrand() % (981 - newEnemy->image_.height());
    //QRandomGenerator gen;
    QRandomGenerator *rg = QRandomGenerator::global();
    int section = rg->bounded(0, INT_MAX) % 11;
    //int section = 0;
    int width = 980 - newEnemy->image_.height();
    //qDebug() << "df";
    //int randomHeight1 = rg->bounded(0, 980 - newEnemy->image_.height());
    //int randomHeight2 = rg->bounded(0, 980 - newEnemy->image_.height());
    //double a = static_cast<double>(rg->bounded(0,10)) / 10;
    //int randomHeight = static_cast<int>(randomHeight1 * a + randomHeight2 * (1- a));
    int randomHeight = rg->bounded(static_cast<int>((width * 1.0 / 11) * section),
                                   (static_cast<int>(width * 1.0 / 11) * (section + 1)));

    //int randomHeight = 300;
    newEnemy->x_coordinate_ = xPos;
    newEnemy->y_coordinate_ = randomHeight;
    return newEnemy;
}

//Enemy* EnemyGenerator::generateAnyEnemy(int xPos){
////    Enemy* newEnemy = nullptr;
//////    EnemyType->
//////    switch(type){
//////        case EnemyType::EnemyType1:
//////            newEnemy = new EnemyType1();
//////    }
////    int randomHeight = qrand() % (981 - newEnemy->image_.height());
////    newEnemy->x_coordinate_ = xPos;
////    newEnemy->y_coordinate_ = randomHeight;
////    return newEnemy;
//}
