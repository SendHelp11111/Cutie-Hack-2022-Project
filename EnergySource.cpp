#include "EnergySource.h"
#include <iostream>
#include <iomanip>
#include <vector>

EnergySource::EnergySource(){
    _year = 0;
    _value = 0;
    _order = 0;
}

EnergySource::EnergySource(int year, double value, int order) {
    _year = year/100;
    _value = value;
    _order = order;

}

int EnergySource::getYear() const{
    return _year;
}
int EnergySource::getValue() const{
    return _value;
}
int EnergySource::getOrder() const{
    return _order;
}
void EnergySource::setYear(int year){
    _year = year/100;
}
void EnergySource::setValue(double value){
    _value = value;
}
void EnergySource::setOrder(int order){
    _order = order;
}

ostream& operator<<(ostream& out, EnergySource& rhs){
    out << "Year: " << rhs._year << " Energy Value: " << rhs._value << " Column: " << rhs._order << endl;
    return out;
}
