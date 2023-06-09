QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    bulletmanager.cpp \
    enemy.cpp \
    enemybullet.cpp \
    enemygenerator.cpp \
    enemytype1.cpp \
    gameovermenu.cpp \
    hero.cpp \
    herobullet.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    model.cpp \
    scene.cpp \
    score.cpp

HEADERS += \
    bullet.h \
    bulletmanager.h \
    enemy.h \
    enemybullet.h \
    enemygenerator.h \
    enemytype1.h \
    gameovermenu.h \
    hero.h \
    herobullet.h \
    mainmenu.h \
    mainwindow.h \
    model.h \
    scene.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    spacewar.qrc
