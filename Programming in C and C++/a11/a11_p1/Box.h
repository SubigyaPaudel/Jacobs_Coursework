/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a11_p01.c
*/

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
        double getheight() const;
        double getwidth() const;
        double getdepth() const;
        double volume();
        Box();
        Box(double x, double y, double z);
        Box(const Box& pointer);
        ~Box();

};

#endif