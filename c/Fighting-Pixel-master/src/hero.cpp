#include "hero.h"
#include <shapes.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include "bullet.h"

using namespace std;
Hero::Hero()
{
    speed = 2;
    heroX = -8;
    heroY = prevY = -3.5;
    wheelRotater = -1.0;
    bulletAtATime = 0;
    reloader =0;
    dead = false;
    newBullet = false;
    shoot = false;
    jumpTop = false;
    jumper = false;
    life = 5;
    shootTextDuration = -1;
}
void Hero::render(){


    float jumpSpeed;
    if(jumpTop)
        jumpSpeed = 0.01;
    else
        jumpSpeed = 0.02;
    if(jumper == true){
        //cout << prevY << " " << heroY << " " << jumpSpeed << endl;
        if(heroY > prevY + 2){
            jumpTop = true;
        }
        if(jumpTop)
            heroY -= jumpSpeed;
        else
            heroY += jumpSpeed;
        if(jumpTop && abs(heroY - prevY) < 0.01){
            jumpTop =false;
            heroY = prevY;
            jumper = false;
        }
    }

    glPushMatrix();
        bullet();
    glPopMatrix();
    if(!dead){
        glPushMatrix();
            glTranslatef(heroX,heroY,0);
            glScalef(.5,.5,1);
            build();
        glPopMatrix();
    }

}

void Hero::build(){
    glPushMatrix();

            //shadow
            if(!jumper){
                glPushMatrix();
                    Color color;
                    color.setColor("EEEEEE");
                    glRotatef(2,0,0,1);
                    glScalef(2.5,.2,1);
                    glTranslatef(0,-6,0);

                    Shapes::circle(color);
                glPopMatrix();
            }
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
                glTranslatef(.2,1.5,0);
                if(bulletAtATime == 12){
                    glRotatef(reloader,0,0,1);
                    reloader += 2;
                    if(reloader == 360){
                        reloader = 0;
                        bulletAtATime = 0;
                    }
                }
                glPushMatrix();
                    gunHolder();
                glPopMatrix();
            glPopMatrix();



        glPopMatrix();

        if(shoot || shootTextDuration > 0){
            glPushMatrix();
                glTranslatef(1,2,0);
                Text shootText;
                Color colorA;
                colorA.setColor("2980b9");
                shootText.fire(colorA);
            glPopMatrix();
            shootTextDuration--;
        }
}
void Hero::head(){
    Color color;
    color.setColor("2980b9");
    glPushMatrix();
        glTranslatef(-1.7,2.1,0);
        glRotatef(-15,0,0,1);
        Shapes::triangle(color);
    glPopMatrix();

    color.setColor("FFFFFF");
    glPushMatrix();
    glScalef(.5,.5,1);
    glPushMatrix();
        glTranslatef(-3,4.4,0);
        glRotatef(-15,0,0,1);
        Shapes::triangle(color);
    glPopMatrix();
    glPopMatrix();

    color.setColor("000000");
    glPushMatrix();

    glPushMatrix();
        glTranslatef(-1.3,2.17,0);
        glRotatef(-15,0,0,1);
        glScalef(.25,.25,1);
        Shapes::triangle(color);
    glPopMatrix();
    glPopMatrix();

}
void Hero::wheel(){
    Color color;
    color.setColor("2980b9");
    glPushMatrix();
        Shapes::octagon(color);
    glPopMatrix();
    color.setColor("FFFFFF");
    glPushMatrix();
        glScalef(.9,.9,1);
        Shapes::octagon(color);
    glPopMatrix();
    color.setColor("2980b9");
    glPushMatrix();
        glScalef(.7,.7,1);
        Shapes::octagon(color);
    glPopMatrix();
}
void Hero::animateWheel(){
    if(wheelRotater < -360)
        wheelRotater = -1.0;
    glPushMatrix();
        glRotatef(wheelRotater,0,0,1);
        wheel();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-2.3,0,0);
        glRotatef(wheelRotater,0,0,1);
        glPushMatrix();
            glScalef(1.2,1.2,1);
            wheel();
        glPopMatrix();
    glPopMatrix();

    wheelRotater -= speed;
    //cout << wheelRotater << " " << speed <<endl;
}
void Hero::body(){
    Color color;

    color.setColor("3498BD");
    glPushMatrix();
        glTranslatef(-1.3,1.3,0);
        glRotatef(270,0,0,1);
        glScalef(.4,1.5,1);
        Shapes::triangle(color);
    glPopMatrix();

    color.setColor("2980b9");

    glPushMatrix();
        glTranslatef(-1.95,1,0);
        glRotatef(-60,0,0,1);
        glScalef(1.5,1.5,1);
        Shapes::triangle(color);
    glPopMatrix();

    color.setColor("3498BD");

    glPushMatrix();
        glTranslatef(-1.3,1.1,0);
        glRotatef(270,0,0,1);
        glScalef(.4,1.5,1);
        Shapes::triangle(color);
    glPopMatrix();
}

void Hero::gunHolder(){
    Color color;
    color.setColor("FFFFFF");
    glPushMatrix();
        glScalef(.5,.5,1);

        Shapes::octagon(color);
    glPopMatrix();

    color.setColor("3498BD");
    glPushMatrix();
        glScalef(.4,.4,1);

        Shapes::octagon(color);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-.2,0);
        gun();
    glPopMatrix();
}

void Hero::gun() {

    Color color;
    color.setColor("FFFFFF");
    glPushMatrix();
        glScalef(.5,.4,1);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor("3498BD");
    glTranslatef(.1,.05,0);
    glPushMatrix();
        glScalef(.4,.3,1);
        Shapes::rect(color);
    glPopMatrix();
}

void Hero::bullet() {
    if(shoot == true && bulletAtATime != 12){
        bool will = true;
        /*
        if(bullets.size()>0){
                int absData = (bullets[bullets.size() - 1].heroX - heroX);
            if(abs(absData) < 1)
                will = false;
        }
        */
        if(will){
            Bullet bullet;
            bullet.heroX = heroX;
            bullet.heroY = heroY;

            if(abs(heroY + 3.5) < 0.001){
                bullets[0].push_back(bullet);
            }
            else if(abs(heroY + 4) < 0.01){
                bullets[1].push_back(bullet);
            }
            else if(abs(heroY + 4.5) < 0.01){
                bullets[2].push_back(bullet);
            }
            else if(abs(heroY + 5) < 0.01){
                    bullets[3].push_back(bullet);
            }
            bulletAtATime++;
            shootTextDuration = 50;
            newBullet = true;
        }

    }
    for(int j = 0; j<4; j++){
    for(int i=0; i<bullets[j].size();i++){
        if(bullets[j][i].killer){
            bullets[j].erase(bullets[j].begin()+i);
            continue;
        }

            Bullet current = bullets[j][i];
            glPushMatrix();
                glTranslatef(bullets[j][i].heroX,bullets[j][i].heroY,0);
                glScalef(.5,.5,1);
                glTranslatef(.1,1.3,0);
                glTranslatef(0,.2,0);
                bullets[j][i].bulletBody();
                //cout << bullets[i].heroY << endl;
            glPopMatrix();
            bullets[j][i].heroX += 0.08;
            if(bullets[j][i].heroX >= 10)
                bullets[j].erase(bullets[j].begin()+i);

        }
    }
    shoot = false;
}
void Hero::moveUp(){
    if(heroY < -3.9 && !jumper){
        heroY += 0.5;
        prevY = heroY;
    }
}

void Hero::moveDown() {
    if(heroY > -5 && !jumper){
        heroY -= 0.5;
        prevY = heroY;
    }
}

void Hero::moveLeft(){
    if(heroX > -8){
        heroX -= 0.1;
        wheelRotater += 3;
    }
}

void Hero::moveRight(){
    if(heroX < 8){
        heroX += 0.1;
        wheelRotater -= 5;
    }
}

void Hero::jump(){
    jumper = true;
}
