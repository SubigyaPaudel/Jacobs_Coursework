#ifndef _BOX_H
#define _BOX_H

class Box{
    private:
        double height;
        double width;
        double depth;
    public:
        void setheight(double x);
        void setwidth(double y);
        void setdepth(double z);
        double getheight();
        double getwidth();
        double getdepth();
        double volume();
        Box();
        Box(double x, double y, double z);
        Box(Box& pointer);
        ~Box();

};

#endif