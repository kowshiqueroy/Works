#include "ai.h"
#include <iostream>
#include <text.h>
using namespace std;
void AI::createEnemy() {
    if(((enemyRandomer == 0 || enemyCreator > enemyRandomer) && enemies.size() < 4) || dynamic == true){
        //cout << (enemyRandomer == 0 || enemyCreator > enemyRandomer) <<  (enemies.size() < 4) << (dynamic == true) << endl;
        enemyCreator = 0;

        if(currentColor > 3)
            currentColor = 0;
        enemyRandomer = rand()%10;

        if(dynamic == true){
            enemies[createOnPosition].colorA = colors[currentColor].first;
            enemies[createOnPosition].colorB = colors[currentColor].second;
            enemies[createOnPosition].EnemyX = 15;
            enemies[createOnPosition].dead = false;
            dynamic = false;
        }else{
            Enemy newEnemy;
            newEnemy.EnemyY = enemyPosition;
            //cout << enemyPosition << endl;
            newEnemy.EnemyX = 15;
            newEnemy.colorA = colors[currentColor].first;
            newEnemy.colorB = colors[currentColor].second;
            enemies.push_back(newEnemy);
            enemyPosition += -0.5;
        if(enemyPosition < -5.4) enemyPosition = -3.5;
        }

        currentColor++;
       // cout << "Yeah New One" << newEnemy.EnemyY  << endl;

    }
    if(enemyCreator > enemyRandomer){
        enemyRandomer = 0;
        enemyCreator = 0;
    }
    enemyCreator += 0.01;
}
void AI::render(){
    renderEnemy();
    if(!hero.dead)
        checkColision();
    writeScore();

    glPushMatrix();
        glTranslatef(8,5.3,0);
        heroLife();
    glPopMatrix();

}
void AI::writeScore(){
    Color color;
    color.setColor("e74c3c");
    Text newScore;
    glPushMatrix();
        glTranslatef(8,5,0);
        newScore.score(color, (int)score);
    glPopMatrix();
}
void AI::renderEnemy(){
    bool heroOnRoad = false;
    for(int i = 0; i<enemies.size(); i++){


        if(!enemies[i].dead){
            enemies[i].render();
            enemies[i].shoot = false;
            if(enemies[i].goLeft == true)
                enemies[i].moveLeft();
            if(enemies[i].goRight == true)
                enemies[i].moveRight();
            if(enemies[i].shooter > 2){

                enemies[i].shooter = 0;
                enemies[i].shoot = true;
                newEnemyBullet = true;
            }
        }else{
            dynamic =true;
            Particles particle;
            particle.elementX = enemies[i].EnemyX;
            particle.elementY = enemies[i].EnemyY;
            particle.destroyColor = enemies[i].colorA;
            particles.push_back(particle);
            createOnPosition = i;
        }

        if(abs(abs(hero.heroY)-abs(enemies[i].EnemyY)) < 0.1){
            hero.render();
            heroOnRoad = true;
            if(hero.gotHit){
                Particles particle;
                Color color;
                color.setColor("F30000");
                particle.elementX = hero.heroX;
                particle.elementY = hero.heroY;
                particle.destroyColor = color;
                particles.push_back(particle);
                hero.gotHit = false;

            }
        }
         //cout << enemies[i].shooter << endl;
    }
    if(!heroOnRoad){
        hero.render();

        if(hero.gotHit){
                Particles particle;
                Color color;
                color.setColor("F30000");
                particle.elementX = hero.heroX;
                particle.elementY = hero.heroY;
                particle.destroyColor = color;
                particles.push_back(particle);
                hero.gotHit = false;

            }
    }

    for(int i = 0; i<particles.size(); i++){

        if(particles[i].durationCounter > 2){
            particles.erase(particles.begin() + i);
        }else{
            glPushMatrix();
                glTranslatef(particles[i].elementX, particles[i].elementY, 0);
                particles[i].destroy();
            glPopMatrix();
        }

    }
    createEnemy();
}
void AI::checkColision (){
    Colition colt;
    colt.DeadEnemy(hero.bullets, enemies);
    colt.DeadHero(hero,enemies);
    if(colt.isDeadEnemy){
        score += 25;
        enemyDead = true;
    }else{
        score += 0.001;
    }
}

void AI::heroLife(){
    float x = 0;
    Color color;
    color.setColor("ffffff");
    glPushMatrix();
    glScalef(.33,.4,1);
    glPushMatrix();
        for(int i = 0; i<5; i++){
            glPushMatrix();
                glTranslatef(x,0,0);
                Shapes::rect(color);
            glPopMatrix();
            x += 1;
        }
    glPopMatrix();
    glPopMatrix();
    color.setColor("e74c3c");
    glPushMatrix();
    glScalef(.3,.3,1);
    glTranslatef(-4.8,.15,0);
    glPushMatrix();
        for(int i = 0; i<hero.life; i++){
            glPushMatrix();
                glTranslatef(x,0,0);
                Shapes::rect(color);
            glPopMatrix();
            x += 1;
        }
    glPopMatrix();
    glPopMatrix();

}

AI::AI()
{
    pair <Color, Color> newPair;
    newPair.first.setColor("16a085");
    newPair.second.setColor("1abc9c");
    colors.push_back(newPair);
    newPair.first.setColor("8e44ad");
    newPair.second.setColor("9b59b6");
    colors.push_back(newPair);
    newPair.first.setColor("f2ca27");
    newPair.second.setColor("f39c12");
    colors.push_back(newPair);
    newPair.first.setColor("e67e22");
    newPair.second.setColor("d35400");
    colors.push_back(newPair);

    enemyDead = false;
    enemyRandomer = 0;
    enemyCreator = 0;
    currentColor = 0;
    enemyPosition = -3.5;
    score = 0;
    dynamic = false;
    newEnemyBullet = false;
}
