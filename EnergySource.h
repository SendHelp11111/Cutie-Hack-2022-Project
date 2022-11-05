#ifndef ENERGYSOURCE_H
#define ENERGYSOURCE_H
#include <iostream>
#include <vector>
using namespace std;

class EnergySource {
    public:
        EnergySource(int year, double value = 0, int order = 0);


    private:
        int _year;
        double _value;
        int _order;
        string _type;
        vector<string> names;
    
};


#endif