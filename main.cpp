
#include <iostream>
#include <fstream>
#include <vector>
#include "EnergySource.h"

using namespace std;

int main(int argc, char* argv[]){
    // vector <string> names {"Coal Production", "Natural Gas (Dry)", "Crude Oil Production", "Natural Gas (Liquid)", "Total Fossil Fuel Production"
    //     , "Nuclear Electric Power Production", "Hydroelectric Power Production", "Geothermal Energy Production", "Solar Energy Production"
    //     , "Wind Energy Production", "Biomass Energy Production", "Total Renewable Energy Production", "Total Primary Energy Production"};
    if (argc < 2) {
        cout << "Usage: myprog.exe csvfile";
        return 1;
    }
    ifstream inFS;
    string filename = argv[1];

    inFS.open(filename);
    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    string line, name;
    char comma;
    int year, column;
    double eValue;
    vector <EnergySource> energylist;

    getline(inFS, line);
    while(inFS.ignore(8,',')){
        inFS >> year; inFS.get(comma); 
        inFS >> eValue; inFS.get(comma); 
        inFS >> column;
        getline(inFS,line);

        EnergySource e(year, eValue, column);
        energylist.push_back(e);
    }

    for(unsigned int i = 0; i < energylist.size(); i++){
        cout << fixed << setprecision(3) << energylist.at(i);
    }

   

    return 0; 
}