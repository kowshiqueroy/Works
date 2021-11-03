#include "controller.h"

Controller::Controller()
{
    gameOver = false;
    gameRunning = false;
    souncontroller.startTheme();
}

void Controller::renderStart(){

    if(currentScore+100 < ai.score){
        bg.overAllSpeed += 0.01;
        currentScore = ai.score;
    }

    bg.animate(sunScaleChanger);

    bg.render();

    if(gameRunning){
        ai.render();
        if(ai.hero.newBullet){
            souncontroller.heroShoot();
            ai.hero.newBullet = false;
        }
        if(ai.newEnemyBullet){
            souncontroller.enemyShoot();
            ai.newEnemyBullet = false;
        }
        if(ai.enemyDead){
            souncontroller.enemyDead();
            ai.enemyDead = false;
        }
        if(ai.hero.gotHit){
            souncontroller.heroDead(true);
        }
    }else{
        renderBg();
        button();
        glPushMatrix();
            glTranslatef(2.6,-3.6,0);
            soundButton();
        glPopMatrix();


    }

    if(ai.hero.dead){
        gameOver = true;
        gameRunning = false;
        souncontroller.heroDead(false);
        if(wait > 5){
                souncontroller.startTheme();
                wait = -1;
        }
        else if( wait >= 0)
            wait += 0.05;

        if(bg.overAllSpeed > 0)
        bg.overAllSpeed -= (bg.overAllSpeed/2);
    }

}

void Controller::renderBg(){
    Color color;
    color.setColor("d35400");
    glPushMatrix();
        glTranslatef(-4.5,-4.5,0);
        glScalef(9,9,1);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor("e67e22");
    glPushMatrix();
        glTranslatef(-4,-4,0);
        glScalef(8,8,1);
        Shapes::rect(color);
    glPopMatrix();

    color.setColor("FFFFFF");
    Text logo;
    glPushMatrix();
        glTranslatef(-1,2,0);
        logo.text(color, "Fighting Pixels");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2,1.5,0);
        logo.text(color, "Click below to start fighting!");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.45,-1.5,0);
        logo.text(color, "    Shoot : S");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.45,-1.9,0);
        logo.text(color, "     Jump : Space");
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.45,-2.3,0);
        logo.text(color, "Direction : Arrow Keys");
    glPopMatrix();

    if(gameOver){
        glPushMatrix();
            glTranslatef(-3.5,-3.5,0);
            logo.score(color, ai.score);
        glPopMatrix();
    }
}

void Controller::button(){
    Color btnColor;
    btnColor.setColor("8e44ad");
    glPushMatrix();
        Shapes::octagon(btnColor);
    glPopMatrix();

    btnColor.setColor("ffffff");
    Text logo;
    glPushMatrix();
        glTranslatef(-.35,-.1,0);
        logo.text(btnColor, "Fight!");
    glPopMatrix();
}

void Controller::soundButton(){
    Color btnColor;
    if(!souncontroller.mute)
        btnColor.setColor("FFFFFF");
    else
        btnColor.setColor("000000");
    glPushMatrix();
        glScalef(1,.3,1);
        Shapes::rect(btnColor);
    glPopMatrix();

    if(!souncontroller.mute)
        btnColor.setColor("000000");
    else
        btnColor.setColor("FFFFFF");
    Text logo;
    glPushMatrix();
        glTranslatef(0.15,.05,0);
        logo.text(btnColor, "Sound");
    glPopMatrix();
}

void Controller::clicked(float x, float y){
    if(!gameRunning){

        if(x < -0.4 && x > -0.56 && y < -0.4 && y > -0.6){
            AI newAI;
            ai = newAI;
            gameRunning = true;
            gameOver = false;
            souncontroller.clickStart();
            wait = 0;
            bg.overAllSpeed = 0;
        }
        if(x < -.32 && x > -.37 && y < -.19 && y > -.22){
            souncontroller.clickStart();
            if(souncontroller.mute)
                souncontroller.mute = false;
            else
                souncontroller.mute = true;

        }
        //cout << x << y << endl;
    }
}
