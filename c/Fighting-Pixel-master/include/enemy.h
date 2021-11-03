#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <bullet.h>
#include <color.h>
#include <text.h>
using namespace std;
class Enemy
{
    public:
        /** Default constructor */
        Enemy();
       void render();
        void head();
        void wheel();
        void animateWheel();
        void body();
        void gunHolder();
        void gun();
        void bullet();
        void build();
        void moveLeft();
        void moveRight();
        float speed, EnemyX, EnemyY;
        bool shoot;
        vector<Bullet> bullets;
        int bulletAtATime;
        int reloader;
        Color colorA, colorB;
        bool goLeft, goRight, dead;
        float shooter;
        int shootTextDuration;
        Text shootText;

    protected:
    private:
        float wheelRotater;
};

#endif // ENEMY_H
