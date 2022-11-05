
#include <iostream>
#include <fstream>
#include <vector>
#include "EnergySource.h"
#include "TotalEnergy.h"

using namespace std;

int main(int argc, char* argv[]){
    // vector<string> names = {"Coal Production", "Natural Gas (Dry)", "Crude Oil Production", "Natural Gas (Liquid)", "Total Fossil Fuel Production"
    //     , "Nuclear Electric Power Production", "Hydroelectric Power Production", "Geothermal Energy Production", "Solar Energy Production"
    //     , "Wind Energy Production", "Biomass Energy Production", "Total Renewable Energy Production", "Total Primary Energy Production"};
    
    ifstream inFS;
    string filename = argv[1];

    inFS.open(filename);
    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    string line, name, units;
    char comma;
    int year, column;
    double eValue;
    
    TotalEnergy current;

    while(inFS.ignore(8,',')){
        inFS >> year;
        inFS.get(comma);
        inFS >> eValue;
        inFS.get(comma);
        inFS >> column;
        getline(inFS,line);
        EnergySource curr(year,eValue,column);
        current.add(curr);
    }

    current.print();
    cout << fixed << setprecision(3) << year << " " << eValue << " " << column << " " << endl;
    return 0; 
}