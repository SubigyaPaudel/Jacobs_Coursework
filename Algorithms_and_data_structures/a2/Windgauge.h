#ifndef WINDGAUGE_H
#define WINDGAUGE_H
#include <deque>

class WindGauge{
    private:
        unsigned int period;
        std::deque<int> windspeeds;
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void print_all_speeds() const;
        void dump() const;
};


#endif