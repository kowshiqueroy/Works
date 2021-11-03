#ifndef PARTICLES_H
#define PARTICLES_H
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <shapes.h>
#include <color.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795
class Particles
{
    public:
        /** Default constructor */
        Particles();
        void destroy();
        Color destroyColor;
        float destroyTrans, destroySize, durationCounter, elementX, elementY;
    protected:
    private:
};

#endif // PARTICLES_H
