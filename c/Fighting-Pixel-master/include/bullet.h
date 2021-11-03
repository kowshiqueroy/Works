#ifndef BULLET_H
#define BULLET_H
#include <text.h>

class Bullet
{
    public:
        float bulletX, bulletY;
        float heroX, heroY;
        bool Enemy,killer;
        Bullet();
        void bulletBody();
        /** Default destructor */
        virtual ~Bullet();

    protected:
    private:
};

#endif // BULLET_H
