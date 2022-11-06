#include "TotalEnergy.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
TotalEnergy::TotalEnergy(){

}
TotalEnergy::TotalEnergy(int year) {
    int _year = year;
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

//functions for average

int TotalEnergy::sumYear(int year) {
    int sum = 0; 
    for(unsigned int i = 0; i < arr.size(); i++){
        if(arr.at(i).getYear() >= year){
            sum += arr.at(i).getYear();
        }
    }
    return sum;
}

double TotalEnergy::sumValue(int year) {
    int sum = 0;
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getYear() >= year) {
            sum += arr.at(i).getValue();
        }
    }
    return sum;
}

int TotalEnergy::totalYearsAfter(int year) {
    int sum = 0;
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getYear() >= year) {
            sum ++;
        }
    }
    return sum;
}

int TotalEnergy::avgYear(int year) {return (sumYear(year)/totalYearsAfter(year));}

double TotalEnergy::avgValue(int year) {return (sumValue(year)/totalYearsAfter(year));}

//functions for regression line
int TotalEnergy::sumYearFromAvg(int year) {
    int sum = 0;
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getYear() > year) {
            sum += (arr.at(i).getYear() - avgYear(year));
        }
    }    
    return sum;
}

double TotalEnergy::sumValueFromAvg(int year) {
    int sum = 0;
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getYear() > year) {
            sum += (arr.at(i).getValue() - avgValue(year));
        }
    }    
    return sum;
}
vector <double> TotalEnergy::vectorYears(){
    vector<double> temp;
    for(unsigned int i = 0; i < arr.size(); i++){
        temp.push_back(arr.at(i).getYear());
    }
    return temp;
}

vector <double> TotalEnergy::vectorValue(){
    vector<double> temp;
    for(unsigned int i = 0; i < arr.size(); i++){
        temp.push_back(arr.at(i).getValue());
    }
    return temp;
}

void TotalEnergy::regression(int year) {
    double top = sumValueFromAvg(year) * sumYearFromAvg(year);
    double bot = sumYearFromAvg(year) * sumYearFromAvg(year);
    _regression = top/bot;
}

double TotalEnergy::getReg() {return _regression;}

void TotalEnergy::yInt(int year) {
    regression(year);
    _yInt = (avgValue(year) - (avgYear(year)*_regression));
}

double TotalEnergy::getYInt() {return _yInt;}

void TotalEnergy::removeZero() {
    for(unsigned int i = 0; i < arr.size(); ++i) {
        if(arr.at(i).getValue() == 0) {
            arr.erase(arr.begin()+i);
        }
    }
}




