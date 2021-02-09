#include "Windgauge.h"
#include <iostream>

WindGauge::WindGauge(int period){
    this->period = period;
}

void WindGauge::currentWindSpeed(int speed){
    windspeeds.push_back(speed);
    if(windspeeds.size() > period){
        windspeeds.pop_front();
    }
}

void WindGauge::print_all_speeds() const{
    for(unsigned int i = 0; i < windspeeds.size(); i++){
        std::cout << windspeeds[i];
    }
    std::cout << std::endl;
}

int WindGauge::highest() const{
    int highest = windspeeds.front();
    for(unsigned int i = 1; i < windspeeds.size(); i++){
        if(windspeeds[i] > highest)
            highest = windspeeds[i];
    }
    return highest;
}

int WindGauge::lowest() const{
    int lowest = windspeeds.front();
    for(unsigned int i = 1; i < windspeeds.size(); i++){
        if(windspeeds[i] < lowest)
            lowest = windspeeds[i];
    }
    return lowest;
}

int WindGauge::average() const{
    int sum = 0;
    for(unsigned int i = 0; i < windspeeds.size(); i++){
        sum += windspeeds[i];
    }
    return (sum/windspeeds.size());
}

void WindGauge::dump() const{
    std::cout << "Highest Wind Speed=" << this->highest() << std::endl;
    std::cout << "Lowest Wind Speed=" << this->lowest() << std::endl;
    std::cout << "Average Wind Speed" << this->average() << std::endl; 
}