#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <mainwindow.h>

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>
#include <QObject>
#include <map>
#include <iostream>

template<typename F, typename S>
class coordPair{

public:
    coordPair(const F a, const S b);
    F get_rowCoordInPair() const;
    F set_rowCoordInPair();
    S get_colCoordInPair() const;
    S set_colCoordInPair();

private:
    F row_coord;
    S col_coord;
};

template<typename F, typename S>
coordPair<F, S>::coordPair(const F a, const S b)
{
 row_coord = a;
 col_coord = b;
}
template<typename F, typename S>
F coordPair<F, S>::get_rowCoordInPair() const
{
 return row_coord;
}
template<typename F, typename S>
S coordPair<F, S>::get_colCoordInPair() const
{
 return col_coord;
}

class Zombie: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //Zombie(QGraphicsItem * parent=0);
    Zombie(QPixmap& pixmap);
    ~Zombie();

    //Accessors
    int getHealth();
    char getDir();
    bool getStatus();  //accesses isDead




    //Modifiers
    void setHealth();
    void setDir(char c);


    void decreaseHealth(int amount);  //decreases health by amount
    void Gene();  //function that finds player using algo
    void hurtGene();   //function that hurts geneBlock when it coollifes

    std::vector<std::pair<int,int>> mypath;
    char zombieMap[26][31];  //2D array scaled representation of the game grid
    double zombieMapToXY(double coord); //linear transformation from zombieMap array to XY coordinate plane for QGraphicsScene


public slots:
    //void move();
    void setPathToGene(); //sets path from source to target
    void moveToGene();  //moves to Gene
    //void doSomething();  // function that checks the status of the zombie, if zombie !isDead then call findPlayer()- called every second of the game
    //int binary_search(int x_player, int y_player, int x_pos, int y_pos);



private:
   int health;
   char direction;
   int speed;
   bool isDead;
   double x_pos;
   double y_pos;
   std::map<std::pair<int,int>,std::pair<int,int>> mymap; //map containing keys of zombieMap and values as parents of each node in zombieMap
   void findPathFromMap(std::map<std::pair<int,int>,std::pair<int,int>>, int sourceX, int sourceY, int targetX, int targetY);
   QPointF destination;
   QTimer *timer;

   size_t k;


};

#endif // ZOMBIE_H
