#include "TotalEnergy.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

TotalEnergy::TotalEnergy() {

}

void TotalEnergy::add(EnergySource n) {
    arr.push_back(n);
}

void TotalEnergy::print() {
    for(unsigned int i = 0; i < arr.size(); ++i) {
        //cout << arr.at(i). << endl;
    }
}

