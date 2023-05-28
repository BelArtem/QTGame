#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class GameOverMenu: public QWidget
{
    Q_OBJECT
public:
    GameOverMenu(QWidget* parent = 0);
    virtual ~GameOverMenu();

private:
    void setUpWidget();

private:
    QGridLayout* layout_;
    QPushButton* restart_button_;
    QPushButton* menu_button_;

private slots:
    void restartButtonClicked();
    void menuButtonClicked();

signals:
    void restartGameSignal();
    void setUpMainMenuSignal();

};

#endif // GAMEOVERMENU_H
