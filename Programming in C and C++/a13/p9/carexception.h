#include <cstring>

class Motor{
    private:
        double power;
    public:
        Motor();
};

class Car{
    private:
        Motor move;
    public:
        Car();
};

class Garage{
    private:
        Car vehicle;
    public:
        Garage();
};