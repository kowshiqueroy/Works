#include "Enemy.h"
#include <shapes.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include "bullet.h"

using namespace std;
Enemy::Enemy()
{
    speed = .6;
    EnemyX = 8;
    wheelRotater = -1.0;
    bulletAtATime = 0;
    reloader =0;
    goLeft = true;
    shoot = false;
    goRight = false;
    dead = false;
    shooter = 0;
    shootTextDuration = -1;
}
void Enemy::render(){

    glPushMatrix();
        bullet();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(EnemyX,EnemyY,0);
        glScalef(.5,.5,1);
        build();
    glPopMatrix();



    shooter +=0.001;
}

void Enemy::build(){
    glPushMatrix();

            //shadow
            glPushMatrix();
                Color color;
                color.setColor("EEEEEE");
                glRotatef(-2,0,0,1);
                glScalef(2.5,.2,1);
                glTranslatef(-.5,-6,0);

                Shapes::circle(color);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.2,.4,0);
                head();
            glPopMatrix();

            glPushMatrix();
                animateWheel();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.2,.4,0);
                body();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-2.5,1.5,0);
                if(bulletAtATime == 4){
                    glRotatef(reloader,0,0,1);
                    reloader += 2;
                    if(reloader == 360){
                        reloader = 0;
                        bulletAtATime = 0;
                    }
                }
                glPushMatrix();
                    glRotatef(180,0,0,1);
                    gunHolder();
                glPopMatrix();
            glPopMatrix();



        glPopMatrix();
        if(shoot || shootTextDuration > 0){
            glPushMatrix();
                glTranslatef(-4,2,0);
                shootText.fire(colorA);
            glPopMatrix();
            shootTextDuration--;
        }
}
void Enemy::head(){
    Color color;
    glPushMatrix();
        glTranslatef(-1,2.1,0);
        glRotatef(15,0,0,1);
        Shapes::triangle(colorA);
    glPopMatrix();



    color.setColor("FFFFFF");
    glPushMatrix();
    glScalef(.5,.5,1);
    glPushMatrix();
        glTranslatef(-2.5,4.25,0);
        glRotatef(15,0,0,1);
        Shapes::triangle(color);
    glPopMatrix();
    glPopMatrix();

    color.setColor("000000");
    glPushMatrix();

    glPushMatrix();
        glTranslatef(-1.3,2.17,0);
        glRotatef(15,0,0,1);
        glScalef(.25,.25,1);
        Shapes::triangle(color);
    glPopMatrix();
    glPopMatrix();



}
void Enemy::wheel(){
    Color color;
    glPushMatrix();
        Shapes::octagon(colorA);
    glPopMatrix();
    color.setColor("FFFFFF");
    glPushMatrix();
        glScalef(.9,.9,1);
        Shapes::octagon(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(.7,.7,1);
        Shapes::octagon(colorA);
    glPopMatrix();
}
void Enemy::animateWheel(){
    if(wheelRotater < -360)
        wheelRotater = -1.0;
    glPushMatrix();
        glRotatef(wheelRotater,0,0,1);
        glScalef(1.2,1.2,1);
        wheel();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-2.3,0,0);
        glRotatef(wheelRotater,0,0,1);
        glPushMatrix();

            wheel();
        glPopMatrix();
    glPopMatrix();

    wheelRotater -= speed;
    //cout << wheelRotater << " " << speed <<endl;
}
void Enemy::body(){
    Color color;


    glPushMatrix();
        glTranslatef(-1.3,1.3,0);
        glRotatef(-270,0,0,1);
        glScalef(.4,1.5,1);
        Shapes::triangle(colorB);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-.7,1,0);
        glRotatef(60,0,0,1);
        glScalef(1.5,1.5,1);
        Shapes::triangle(colorA);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-1.3,1.1,0);
        glRotatef(-270,0,0,1);
        glScalef(.4,1.5,1);
        Shapes::triangle(colorB);
    glPopMatrix();
}

void Enemy::gunHolder(){
    Color color;
    color.setColor("FFFFFF");
    glPushMatrix();
        glScalef(.5,.5,1);

        Shapes::octagon(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(.4,.4,1);

        Shapes::octagon(colorB);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-.2,0);
        gun();
    glPopMatrix();
}

void Enemy::gun() {

    Color color;
    color.setColor("FFFFFF");
    glPushMatrix();
        glScalef(.5,.4,1);
        Shapes::rect(color);
    glPopMatrix();


    glTranslatef(.1,.05,0);
    glPushMatrix();
        glScalef(.4,.3,1);
        Shapes::rect(colorA);
    glPopMatrix();
}

void Enemy::bullet() {
    if(shoot == true && bulletAtATime != 4){
        Bullet bullet;
        bullet.heroX = EnemyX;
        bullet.heroY = EnemyY;
        bullet.Enemy = true;
        bullets.push_back(bullet);
        bulletAtATime++;
        shoot = false;
        shootTextDuration = 50;
    }

    for(int i=0; i<bullets.size();i++){
        if(bullets[i].killer){
            bullets.erase(bullets.begin()+i);
            continue;
        }
        Bullet current = bullets[i];
        glPushMatrix();
            glTranslatef(bullets[i].heroX,bullets[i].heroY,0);
            glScalef(.5,.5,1);
            glTranslatef(.1,1.3,0);
            glTranslatef(-2,.2,0);
            bullets[i].bulletBody();
        glPopMatrix();
        bullets[i].heroX -= 0.03;
        if(bullets[i].heroX < -12)
            bullets.erase(bullets.begin()+i);

    }
    shoot = false;
}

void Enemy::moveLeft(){
    if(EnemyX > 2){
        EnemyX -= 0.005;
        wheelRotater += 3;
    }else{
        goRight = true;
        goLeft = false;
    }
}

void Enemy::moveRight(){
    if(EnemyX < 8){
        EnemyX += 0.005;

    }else{
        goRight = false;
        goLeft = true;
    }
}
