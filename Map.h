#ifndef MAP_H
#define MAP_H

#include "Config.h"
#include <QObject>

class Map : public QObject{
    Q_OBJECT
    Map();
    void __setUpMap();
    static Map& getMap();
private slots:
    void update();
public:
    static void setUpMap();
};

#endif // MAP_H
