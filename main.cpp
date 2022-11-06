
#include <iostream>
#include <fstream>
#include <vector>
#include "EnergySource.h"
#include "TotalEnergy.h"
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

void display(vector<double> &years, vector<double> &energyProduction, string pngName, string plotTitle);

int main(int argc, char* argv[]){
    // vector <string> names {"Coal Production", "Natural Gas (Dry)", "Crude Oil Production", "Natural Gas (Liquid)", "Total Fossil Fuel Production"
    //     , "Nuclear Electric Power Production", "Hydroelectric Power Production", "Geothermal Energy Production", "Solar Energy Production"
    //     , "Wind Energy Production", "Biomass Energy Production", "Total Renewable Energy Production", "Total Primary Energy Production"};
    if (argc < 2) {
        cout << "Usage: myprog.exe csvfile";
        return 1;
    }
    ifstream inFS;
    string filename = argv[1]; //File must be in this format: MSN,YYYYMM,Value,Column_Order,Description,Unit


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
        
        EnergySource e(year, eValue, column);
        
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

    string inputName;
    cout << "Energy Options: Coal Production, Natural Gas (Dry), Crude Oil Production, Natural Gas (Liquid), Total Fossil Fuel Production
       , Nuclear Electric Power Production, Hydroelectric Power Production, Geothermal Energy Production, Solar Energy Production
       , Wind Energy Production, Biomass Energy Production, Total Renewable Energy Production, Total Primary Energy Production" << endl;
    cout << "Choose an Energy Option: "; cin >> inputName; cout << endl;

    
    vector<double> yearValues = wind.vectorYears();
    vector<double> productionValues = wind.vectorValue();
    display(yearValues, productionValues, "CoalProduction.png", "Predictions for coal production energy values in 2050");

    
    

    return 0; 
}


//Display creates a new file "pngName" ***MUST HAVE .png FILETYPE*** that stores a graph with the x values (&years) and y values (&energyProduction) plotted with the title "plotTitle"
void display(vector<double> &years, vector<double> &energyProduction, string pngName, string plotTitle) {
    bool success;
    StringReference *errorMessage;
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    wstring wplotTitle = wstring(plotTitle.begin(), plotTitle.end());

    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series->xs = &years;
    series->ys = &energyProduction;
    series->color = CreateRGBColor(0,0,1);
    series->linearInterpolation = true;

    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings->title = toVector(wplotTitle.c_str());
    settings->width = 1200;
    settings->height = 800;
    settings->xLabel = toVector(L"Year");
    settings->yLabel = toVector(L"Energy Production");
    settings->scatterPlotSeries->push_back(series);

    success = DrawScatterPlotFromSettings(imageRef, settings, errorMessage);

    if (success) {
        vector<double> *pngdata = ConvertToPNG(imageRef->image);
        WriteToFile(pngdata, pngName);
        DeleteImage(imageRef->image);
    } else {
        cout << "Error drawing plot";
    }
}