#ifndef HERO_H
#define HERO_H
#include <vector>
#include <bullet.h>
#include <text.h>
#include <cmath>
using namespace std;

class Hero
{
    public:
        /** Default constructor */
        Hero();
        void render();
        void head();
        void wheel();
        void animateWheel();
        void body();
        void gunHolder();
        void gun();
        void bullet();
        void build();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void jump();
        float speed, heroX, heroY;
        bool shoot;
        vector<Bullet> bullets[4];
        int bulletAtATime;
        int reloader;
        bool dead;
        int shootTextDuration;
        bool newBullet;
        bool jumper;
        bool jumpTop;
        float prevY;
        bool gotHit = false;
        int life;
    protected:
    private:
        float wheelRotater;
};

#endif // HERO_H
