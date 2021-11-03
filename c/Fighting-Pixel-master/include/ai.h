#ifndef AI_H
#define AI_H
#include <color.h>
#include <vector>
#include <enemy.h>
#include <math.h>
#include <cstdlib>
#include <hero.h>
#include <colition.h>
#include <particles.h>
using namespace std;
class AI
{
    public:
        /** Default constructor */
        AI();
        void createEnemy();
        void renderEnemy();
        void render();
        void checkColision();
        void writeScore();
        void heroLife();
        Hero hero;
        float score;
        bool newEnemyBullet;
        bool enemyDead;
    protected:
    private:
        vector <pair <Color, Color> > colors;
        vector <Enemy> enemies;
        vector <Particles> particles;
        float enemyCreator;
        int currentColor;
        float enemyPosition;
        int enemyRandomer;
        int createOnPosition;
        bool dynamic;


};

#endif // AI_H
