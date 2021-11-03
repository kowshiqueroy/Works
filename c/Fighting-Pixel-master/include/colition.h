#ifndef COLITION_H
#define COLITION_H
#include <vector>
#include <bullet.h>
#include <enemy.h>
#include <cmath>
#include <iostream>
#include <hero.h>
#define ERROR_AC 0.1
using namespace std;

class Colition
{
    public:
        /** Default constructor */
        Colition();
        void DeadEnemy(vector <Bullet>  (&bullets)[4], vector <Enemy> &enemies);
        void DeadHero(Hero &hero, vector <Enemy> &enemies);
        bool isDeadEnemy;
    protected:
    private:

};

#endif // COLITION_H
