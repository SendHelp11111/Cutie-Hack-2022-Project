#ifndef TOTALENERGY_H
#define TOTALENERGY_H
#include "EnergySource.h"
#include <iostream>
#include <vector>
using namespace std;

class TotalEnergy {
    public:
        TotalEnergy();
        void add(EnergySource n);
        void print();


    private:
        vector<EnergySource> arr;
        
};


#endif