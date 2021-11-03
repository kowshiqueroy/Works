#include "particles.h"

Particles::Particles()
{
    //ctor
    durationCounter = 0;
}

void Particles::destroy(){
    if(durationCounter < 2){

        glPushMatrix();


        for(double i = 0; i < 2 * PI; i += PI / 12){

            glPushMatrix();
                glTranslatef(cos(i) *destroyTrans, sin(i) *destroyTrans, 0);
                glScalef(destroySize,destroySize,1);

                Shapes::rect(destroyColor);
            glPopMatrix();

        }
        glEnd();
        glPopMatrix();
        destroySize += 0.01;
        destroyTrans += 0.08;
        if(destroySize > .1) destroySize = .1;
        if(destroyTrans > 1) {
        destroyTrans = 0;
        destroySize = 0;
        durationCounter += 0.5;
    }
  }
}
