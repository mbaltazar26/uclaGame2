#ifndef INTROWINDOW_H
#define INTROWINDOW_H
#include <instructionswindow.h>
#include <gamewindow.h>
#include <mainwindow.h>

//Currently commented out because to temp solve bug
/*extern bool isEasy;*/ //global variable (accessible across all files) to set difficulty

class introWindow : public QWidget
{
    Q_OBJECT

    public:
        introWindow();      //Constructor
        ~introWindow();     //Destructor
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
};

#endif // INTROWINDOW_H
