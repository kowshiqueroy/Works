#include "background.h"
#include <shapes.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
Background::Background() {
    hillX  = skyscrapperX = smallHillX = cloudFarX = cloudNearX = 0.0;
    sunScale = 1;
}

void Background::render(){
    glPushMatrix();
        glTranslatef(-9,4,0);
        glScalef(sunScale,sunScale,1);
        sun();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloudFarX,4.5,0);
        glScalef(.8,.8,1);
        cloud();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloudFarX+5,5,0);
        glScalef(.8,.8,1);
        cloud();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(hillX,-3,0);
        hills();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(cloudNearX+5,2,0);
        glScalef(1.2,1.2,1);
        cloud();
    glPopMatrix();

    glPushMatrix();
        glScalef(.6,.6,1);
        glTranslatef(smallHillX-5,-6,0);
        smallHills();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(skyscrapperX,2,0);
        drawSkyscrapper();
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-15,-6,0);
        road();
    glPopMatrix();



}

void Background::sun(){
    Color color;
    // color of background wrapper
    color.setColor("bbedf9");

    glPushMatrix();
        glScalef(10,10,1);
        glTranslatef(-.5,-.4,0);
        Shapes::rect(color);
    glPopMatrix();
    // color of sun background wrapper
    color.setColor("fdf78c");

    glPushMatrix();
        glScalef(1.5,1.5,1);
        glTranslatef(-.155,-.155,0);
        Shapes::rect(color);
    glPopMatrix();
    // color of sun
    color.setColor("fff200");

    glPushMatrix();
        Shapes::rect(color);
    glPopMatrix();

}
void Background::cloud(){
    Color color;
    color.setColor("ffffff");

    glPushMatrix();
        glTranslatef(.4,0,0);
        Shapes::rect(color);
    glPopMatrix();

    glPushMatrix();
        glScalef(.5,.5,1);
        glTranslatef(0,0,0);
        Shapes::rect(color);

    glPopMatrix();

    glPushMatrix();
        glScalef(.5,.5,1);
        glTranslatef(2.5,0,0);
        Shapes::rect(color);
    glPopMatrix();


}


void Background::road() {
    Color color;
    color.setColor("ffffff");
    glPushMatrix();
        glScalef(50,3,1);
        Shapes::rect(color);
    glPopMatrix();
    color.setColor("EEEEEE");
    glPushMatrix();
        glScalef(50,.5,1);
        glTranslatef(0,5,0);
        Shapes::rect(color);
    glPopMatrix();
}

void Background::hills(){
    Color color;

    color.setColor("9edb4c");
    glPushMatrix();
        glScalef(4,8,1);
        glTranslatef(1,0,0);
        Shapes::triangle(color);
    glPopMatrix();
    color.setColor("8dc63f");
    glPushMatrix();
        glScalef(4,4,1);
        Shapes::triangle(color);
    glPopMatrix();
    glPushMatrix();
        glScalef(4,6,1);
        glTranslatef(2,0,0);
        Shapes::triangle(color);
    glPopMatrix();

}

void Background::smallHills(){
    Color color;

    color.setColor("9edb4c");
    glPushMatrix();
        glScalef(4,8,1);
        glTranslatef(1,0,0);
        Shapes::triangle(color);
    glPopMatrix();
    color.setColor("b6eb6f");
    glPushMatrix();
        glScalef(4,4,1);
        Shapes::triangle(color);
    glPopMatrix();
    glPushMatrix();
        glScalef(4,6,1);
        glTranslatef(2,0,0);
        Shapes::triangle(color);
    glPopMatrix();

}

void Background::drawSkyscrapper(){
    int rand[] = {3,1,3,2,1};
    float x = 0;
    for(int i = 0; i<5; i++){
            glPushMatrix();
                glTranslatef(x,0,0);
                skyscrapper(rand[i]);
            glPopMatrix();
            x += 1.9;
    }

}

void Background::skyscrapper(int till){

    float y = -4.9;
    for(int i = 1; i<= till; i++){
        glPushMatrix();
            glTranslatef(0,y,0);
            skyscrapperHelper();
        glPopMatrix();
        y += 2;
    }
}

void Background::skyscrapperHelper(){
    Color color;
    color.setColor("ffffff");

    glPushMatrix();
        glScalef(1.8,2,1);
        glTranslatef(-.07,-.06,0);
        Shapes::rect(color);
    glPopMatrix();


    color.setColor("444444");
    float x = 0, y = 0;
    for(int j = 0; j<5; j++){
        for(int i = 0; i<5; i++){
            glPushMatrix();
                glScalef(.25,.25,1);
                glTranslatef(x, y,0);
                x += 1.3;
                Shapes::rect(color);
            glPopMatrix();
        }
        y += 1.5;
        x = 0;
    }
}

void Background::animate(float sunScaleChanger){
    skyscrapperX -= (0.004+overAllSpeed);
    hillX -= (0.001+overAllSpeed);
    smallHillX -= (0.003+overAllSpeed);
    cloudFarX -= (.0005);
    cloudNearX -= (.002);
    if(sunScale > 1.3)
        sunScaleChanger *= -1;
    else if(sunScale < 1)
        sunScaleChanger *= -1;
    sunScale += sunScaleChanger;
    if(skyscrapperX < -21) skyscrapperX = 10;
    if(hillX < -23.2) hillX = 16;
    if(smallHillX < -22.2) smallHillX = 20;
    if(cloudFarX < -23) cloudFarX = 10;
    if(cloudNearX < -23) cloudNearX = 10;
}

Background::~Background()
{
    //dtor
}
