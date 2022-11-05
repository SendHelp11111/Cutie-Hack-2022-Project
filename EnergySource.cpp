#include "EnergySource.h"
#include <iostream>
#include <vector>

EnergySource::EnergySource(int year, double value, int order) {
    _year = year;
    _value = value;
    _order = order;

    _type = nullptr;
}

int EnergySource::year() const {return _year;}
double EnergySource::value() const {return _value;}
string EnergySource::type() const {return _type;}

