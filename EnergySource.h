#ifndef ENERGYSOURCE_H
#define ENERGYSOURCE_H
#include <iostream>
#include <vector>
#include <ostream>
using namespace std;

class EnergySource {
    public:
        EnergySource();
        EnergySource(int year, double value = 0, int order = 0);
        int getYear() const;
        int getValue() const;
        int getOrder() const;
        void setYear(int year);
        void setValue(double value);
        void setOrder(int order);
        friend ostream& operator<<(ostream& out, EnergySource& rhs);

    private:
        int _year;
        double _value;
        int _order;
        string _type;
    
};


#endif