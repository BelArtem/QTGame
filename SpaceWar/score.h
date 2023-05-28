#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsTextItem * parent = 0);
    ~Score() {};

    void addScore(int score);
    int getScore();
    void setScore(int score);

private:
    int score_;

signals:
    void makeMoreDifficult(int millisec);
};

#endif // SCORE_H
