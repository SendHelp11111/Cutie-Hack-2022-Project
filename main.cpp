
#include <iostream>
#include <fstream>
#include <vector>
#include "EnergySource.h"
#include "TotalEnergy.h"

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
    TotalEnergy current;
    TotalEnergy coal, naturalGasDry, crudeOil, naturalGasPlant, fossilFuels, nuclearElectric, hydroElectric, geothermal, solar, wind, biomass;
    

    getline(inFS, line); 
    while(inFS.ignore(256,',')){
        inFS >> year; inFS.ignore();
        if(inFS.peek() == 'N'){
            inFS.ignore(256,',');
            eValue = 0;
        } else {
            inFS >> eValue;
            inFS.ignore();
        }
        inFS >> column;
        getline(inFS, line);
        
        if(eValue != 0){
            EnergySource e(year, eValue, column);
        }
        
        if(column == 1){
            coal.add(e);
        } else if (column == 2){
            naturalGasDry.add(e);
        } else if (column == 3){
            crudeOil.add(e);
        } else if (column == 4){
            naturalGasPlant.add(e);
        } else if (column == 5){
            fossilFuels.add(e);
        } else if (column == 6){
            nuclearElectric.add(e);
        } else if (column == 7){
            hydroElectric.add(e);
        } else if (column == 8){
            geothermal.add(e);
        } else if (column == 9){
            solar.add(e);
        } else if (column == 10){
            wind.add(e);
        } else if (column == 11){
            biomass.add(e);
        } 

    }


    inFS.close();

    

    return 0; 
}