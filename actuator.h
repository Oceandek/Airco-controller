#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>
using namespace std;

class Temperatuursensor {
    private:
    int temperatuur;

    public:
    Temperatuursensor();
    void settemperatuursensor(float t);
    float gettemperatuursensor();


};

#endif