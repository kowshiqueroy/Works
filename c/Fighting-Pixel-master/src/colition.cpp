#include "colition.h"

Colition::Colition()
{
    //ctor
    isDeadEnemy = false;
}

void Colition::DeadEnemy(vector <Bullet>  (&bullets)[4], vector <Enemy> &enemies){


    for(int i = 0; i<enemies.size();i++){

        if (!enemies[i].dead && abs(enemies[i].EnemyY + 3.5) < ERROR_AC){
            for(int j = 0; j<bullets[0].size(); j++){
                if(abs(bullets[0][j].heroX - enemies[i].EnemyX) < ERROR_AC){
                    //cout << "Dead" << endl;
                    bullets[0][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }
        else if (!enemies[i].dead && abs(enemies[i].EnemyY + 4) < ERROR_AC){
            for(int j = 0; j<bullets[1].size(); j++){
                if(abs(bullets[1][j].heroX - enemies[i].EnemyX) < ERROR_AC){
                    //cout << "Dead" << endl;
                    bullets[1][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }
        else if (!enemies[i].dead && abs(enemies[i].EnemyY + 4.5) < ERROR_AC){
            for(int j = 0; j<bullets[2].size(); j++){
                if(abs(bullets[2][j].heroX - enemies[i].EnemyX) < ERROR_AC){
                    //cout << "Dead" << endl;
                    bullets[2][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }
        else if (!enemies[i].dead && abs(enemies[i].EnemyY + 5) < ERROR_AC){
            for(int j = 0; j<bullets[3].size(); j++){
                if(abs(bullets[3][j].heroX - enemies[i].EnemyX) < ERROR_AC){
                    //cout << "Dead" << endl;
                    bullets[3][j].killer = true;
                    enemies[i].dead = true;
                    isDeadEnemy = true;
                }
            }
        }

    }
}


void Colition::DeadHero(Hero &hero, vector<Enemy> &enemies){

    for(int i = 0; i<enemies.size(); i++){

        for(int j = 0; j<enemies[i].bullets.size();j++){
            if(!hero.jumper){
                if(abs(enemies[i].bullets[j].heroY-hero.heroY) < ERROR_AC){

                    if(abs(enemies[i].bullets[j].heroX-hero.heroX) < ERROR_AC){
                            //cout << hero.life << endl;
                        if(hero.life == 1)
                            hero.dead = true;
                        else
                            hero.life--;
                        enemies[i].bullets[j].killer = true;
                        hero.gotHit = true;
                    }

                }
            }
            if(hero.jumper){

               if(abs(enemies[i].bullets[j].heroY-hero.prevY) < ERROR_AC && abs(hero.prevY - hero.heroY) < 1){

                if(abs(enemies[i].bullets[j].heroX-hero.heroX) < 1){

                    if(hero.life == 1)
                            hero.dead = true;
                        else
                            hero.life--;
                    enemies[i].bullets[j].killer = true;
                    hero.gotHit = true;
                }

            }

            }

        }

    }


}
