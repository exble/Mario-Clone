QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Block.cpp \
    Bullet.cpp \
    Entity.cpp \
    Game.cpp \
    Hitbox.cpp \
    Map.cpp \
    Mario.cpp \
    Object.cpp \
    TitleScreen.cpp \
    ToxicMushroom.cpp \
    main.cpp

HEADERS += \
    Block.h \
    Bullet.h \
    Config.h \
    Entity.h \
    Game.h \
    Hitbox.h \
    Map.h \
    Mario.h \
    Object.h \
    TitleScreen.h \
    ToxicMushroom.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
