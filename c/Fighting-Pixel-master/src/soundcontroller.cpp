#include "soundcontroller.h"

SoundController::SoundController()
{
    mute = false;
    heroDeadTrigger = false;
}

void SoundController::startTheme(){
    if(!mute)
        PlaySound("gameTheme.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void SoundController::heroShoot(){
    if(!mute)
        PlaySound("heroShoot.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundController::enemyShoot(){
    if(!mute)
        PlaySound("enemyShoot.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundController::clickStart(){
    if(!mute)
        PlaySound("clicStart.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundController::heroDead(bool dt){
    if(!mute && !heroDeadTrigger){
        PlaySound("heroDead.wav", NULL, SND_FILENAME | SND_ASYNC);
        heroDeadTrigger = true;
    }
    if(dt)
        PlaySound("heroDead.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundController::enemyDead(){
    if(!mute)
        PlaySound("enemyDead.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundController::background(){
    if(!mute)
        PlaySound("gameTheme.wav", NULL, SND_FILENAME | SND_LOOP);
}
