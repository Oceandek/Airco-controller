#include "sensor.h"
#include <iostream>
#include <string>
using namespace std;

Temperatuursensor::Temperatuursensor() {
    temperatuur = 12;
}

void Temperatuursensor::settemperatuursensor(float i) {
    temperatuur = i;
}


float  Temperatuursensor::gettemperatuursensor() {
    return temperatuur ;
}


