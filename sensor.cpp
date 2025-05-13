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
    return temperatuur;
}

Drukknop::Drukknop(){
    value = 999;
}


void Drukknop::setdrukknopstatus(int get) {
    value = get;
}

int Drukknop::getdrukknopstatus() {
    return value;
}

