#include "score.h"

Score::Score(QGraphicsTextItem * parent): QGraphicsTextItem(parent)
{
    score_ = 0;
    setPlainText(QString("Score:") + QString::number(score_));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

int Score::getScore(){
    return score_;
}

void Score::addScore(int score){
    int previous = score_ % 10;
    score_ += score;
    if (score_ % 10 < previous){
        emit makeMoreDifficult(40);
    }
    setPlainText(QString("Score:") + QString::number(score_));

}

void Score::setScore(int score){
    score_ = score;
}
