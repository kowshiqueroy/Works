#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <shapes.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <text.h>
#include <ai.h>
#include <background.h>
#include <soundcontroller.h>
using namespace std;
class Controller
{
    public:
        /** Default constructor */
        Controller();
        void renderStart();
        void renderBg();
        void button();
        void soundButton();
        void clicked(float x, float y);
        bool gameOver;
        bool gameRunning;
        AI ai;
        Background bg;
        float sunScaleChanger = .0005;
        float currentScore;
    protected:
    private:
        SoundController souncontroller;
        float wait = 0;

};

#endif // CONTROLLER_H
