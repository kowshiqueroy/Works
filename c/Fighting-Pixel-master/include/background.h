#ifndef BACKGROUND_H
#define BACKGROUND_H


class Background
{
    public:
        /** Default constructor */
        Background();
        void render();
        void road();
        void skyscrapper(int);
        void drawSkyscrapper();
        void skyscrapperHelper();

        void hills();
        void smallHills();
        void sun();
        void cloud();

        void animate(float);
        float hillX, skyscrapperX, sunScale, smallHillX, cloudFarX, cloudNearX;
        bool sunScalerH;

        float overAllSpeed;
        /** Default destructor */
        virtual ~Background();
    protected:
    private:
};

#endif // BACKGROUND_H
