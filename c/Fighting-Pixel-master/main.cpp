#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <color.h>
#include <iostream>
#include <cmath>
#include <mmsystem.h>
//my libraries
#include <shapes.h>
#include <background.h>
#include <hero.h>
#include <enemy.h>
#include <ai.h>
#include <text.h>
#include <controller.h>
#include <particles.h>
using namespace std;
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 600
#define SETCOLOR(color) color.Getred(), color.Getgreen(), color.Getblue()

float currentWidth = 1024;
float currentHeight = 600;
Controller control;
Particles pr;
void changeSize(int w, int h) {
    glutReshapeWindow( SCREEN_WIDTH, SCREEN_HEIGHT);
    glutPositionWindow(50,50);

	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);

    currentWidth = w;
    currentHeight = h;
	gluPerspective(100,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);

}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //bg animations



        control.renderStart();

	glutSwapBuffers();
}


void processSpecialKeys(int key, int x, int y) {

	switch(key) {
        case GLUT_KEY_UP:
            control.ai.hero.moveUp();
            break;
        case GLUT_KEY_DOWN:
            control.ai.hero.moveDown();
            break;
        case GLUT_KEY_LEFT:
            control.ai.hero.moveLeft();
            break;
        case GLUT_KEY_RIGHT:
            control.ai.hero.moveRight();
            break;

        default:
            break;

	}
}


void processKeys(unsigned char key, int x, int y){
    if(key == 's') {
            if(!control.ai.hero.jumper)
                control.ai.hero.shoot = true;
        }
    else if(key == 32){
        control.ai.hero.jump();
    }
    else if(key == 'q'){

        glutLeaveGameMode();
        exit(1);
    }

}

void processMouse(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
           // cout << (float)((x/currentWidth)-1) << " " << (float) ((y/currentHeight)-1) << endl;
			control.clicked((float)((x/currentWidth)-1), (float) ((y/currentHeight)-1));
		}
	}
}


int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50,50);
	//glutInitWindowSize(1024,600);
	//glutCreateWindow("Fighting Pixels");


    glutGameModeString("1024x600:32@60");
	// enter full screen

    glutEnterGameMode();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );


    Color bgcolor;
    bgcolor.setColor("a7edfe");
    glClearColor(SETCOLOR(bgcolor),1);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc( processKeys );
    glutSpecialFunc(processSpecialKeys);
    glutMouseFunc(processMouse);

	glutMainLoop();



	return 1;
}
