#include "TotalEnergy.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

TotalEnergy::TotalEnergy() {

}

vector<EnergySource> TotalEnergy::getArr() {
    return arr;
}

void TotalEnergy::add(EnergySource n) {
    arr.push_back(n);
}

void TotalEnergy::print() {
    for(unsigned int i = 0; i < arr.size(); ++i) {
        cout << arr.at(i) << endl;
    }
}

double TotalEnergy::sumValCol(int col) {
    double sum = 0.0;
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getOrder() == col) {
            sum += arr.at(i).getValue();
        }
    }
    return sum;
}

double TotalEnergy::sumPerYear(int year) {
    double sum = 0.0;
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getYear() == year) {
            sum += arr.at(i).getValue();
        }
    }
    return sum;    
}

