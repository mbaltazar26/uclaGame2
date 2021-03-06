#ifndef INTROWINDOW_H
#define INTROWINDOW_H
#include <instructionswindow.h>
#include <gamewindow.h>
#include <mainwindow.h>

class introWindow : public QWidget
{
    Q_OBJECT

    public:
        introWindow();          //Constructor
        ~introWindow();         //Destructor
        bool getDifficulty();   //Get difficulty of game
    public slots:
        void openGameWindow();
        void openInstrWindow();
        void selectEasy();
        void selectHard();
    private:
        InstructionsWindow* instructionsWindow = nullptr;
        GameWindow* gameWindow = nullptr;

        //Layout
        QGridLayout* IntroWindowGridLayout = nullptr;

        //Label(s)
        QLabel* gameTitle = nullptr;

        //Buttons
        QPushButton* startWindowButton = nullptr;
        QPushButton* instructionsButton = nullptr;
        QPushButton* goBackButton = nullptr;
        QPushButton* easyButton = nullptr;
        QPushButton* hardButton = nullptr;

        bool isEasy;
        bool isEasySelected;
        bool isHardSelected;

        QMediaPlayer* introMusic = nullptr;
};

#endif // INTROWINDOW_H






























//#ifndef INTROWINDOW_H
//#define INTROWINDOW_H
//#include <instructionswindow.h>
//#include <gamewindow.h>
//#include <mainwindow.h>

//Currently commented out because to temp solve bug
//*extern bool isEasy;*/ //global variable (accessible across all files) to set difficulty

//class introWindow : public QWidget
//{
//    Q_OBJECT

//    public:
//        introWindow();      //Constructor
//        ~introWindow();     //Destructor
//    public slots:
//        void openGameWindow();
//        void openInstrWindow();
//        void selectEasy();
//        void selectHard();
//    private:
//        InstructionsWindow* instructionsWindow = nullptr;
//        GameWindow* gameWindow = nullptr;

//        //Layout
//        QGridLayout* IntroWindowGridLayout = nullptr;

//        //Label(s)
//        QLabel* gameTitle = nullptr;

//        //Buttons
//        QPushButton* startWindowButton = nullptr;
//        QPushButton* instructionsButton = nullptr;
//        QPushButton* goBackButton = nullptr;
//        QPushButton* easyButton = nullptr;
//        QPushButton* hardButton = nullptr;

//        bool isEasySelected;
//        bool isHardSelected;
//};

//#endif // INTROWINDOW_H
