#include "bullet.h"
#include <shapes.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
using namespace std;
Bullet::Bullet()
{
    bulletX = 0;
    bulletY = 0;
    Enemy = false;
    killer = false;

}
void Bullet::bulletBody(){

    Color color;
    color.setColor("FF0000");

    glPushMatrix();
        if(Enemy == true)
            glRotatef(90,0,0,1);
        else
            glRotatef(270,0,0,1);
        glScalef(.2,.5,1);

        glTranslatef(bulletX,bulletY,0);
        Shapes::triangle(color);
    glPopMatrix();

    color.setColor("EEEEEE");
    glPushMatrix();
        if(Enemy == true)
            glRotatef(90,0,0,1);
        else
            glRotatef(270,0,0,1);
        glScalef(.2,.5,1);
        if(Enemy == true)
            glTranslatef(-14,0,0);
        else
            glTranslatef(14,0,0);
        Shapes::triangle(color);
    glPopMatrix();

}
Bullet::~Bullet()
{
    //dtor
}
