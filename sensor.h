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

class Drukknop {
    private:
    int value;

    public:
    Drukknop();
    void setdrukknopstatus(int t);
    int getdrukknopstatus();


};



#endif