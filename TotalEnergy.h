#ifndef TOTALENERGY_H
#define TOTALENERGY_H
#include "EnergySource.h"
#include <iostream>
#include <vector>
using namespace std;

class TotalEnergy {
    public:
        TotalEnergy();
        TotalEnergy(int year);
        vector<EnergySource> getArr();
        void add(EnergySource n);
        void print();
        int sumYear(int year);
        double sumValue(int year);
        vector<double> vectorYears();
        vector<double> vectorValue();
        int totalYearsAfter(int year);
        int avgYear(int year);
        double avgValue(int year);
        int sumYearFromAvg(int year);
        double sumValueFromAvg(int year);
        void regression(int year);
        double getReg();
        void yInt(int year);
        double getYInt();
        void removeZero();



    private:
        vector<EnergySource> arr;
        int _year;
        double _regression;
        double _yInt;
};


#endif