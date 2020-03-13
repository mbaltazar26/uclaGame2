#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

//extern int health;

class Health: public QGraphicsTextItem {
    public:
        Health(bool isEasyDifficulty);
        void decrease();
        int getHealth();
    private:
        int health;
};

#endif // SCORE_H
