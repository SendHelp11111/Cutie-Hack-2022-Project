#ifndef TOTALENERGY_H
#define TOTALENERGY_H
#include "EnergySource.h"
#include <iostream>
#include <vector>
using namespace std;

class TotalEnergy {
    public:
        TotalEnergy();
        vector<EnergySource> getArr();
        void add(EnergySource n);
        void print();
        double sumValCol(int col);
        double sumPerYear(int year);
        vector <double> vectorYears();
        vector <double> vectorValue();


    private:
        vector<EnergySource> arr;
        
};


#endif