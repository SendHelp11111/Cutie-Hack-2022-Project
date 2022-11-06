
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
    string png;
    string title;
    cout << "Energy Options: Coal, Natural Gas (Dry), Crude Oil, Natural Gas (Liquid), Fossil Fuel, Nuclear Electric Power, Hydroelectric Power, Geothermal Energy, Solar Energy, Wind Energy, Biomass Energy" << endl;
    cout << "Choose an Energy Option (Exactly as written above): "; 
    getline(cin,inputName);
    cout << endl;

    png = inputName+"_Production.png";
    title = "Predictions for "+inputName+" energy values in x years";

    if(inputName == "Coal"){
        vector<double> yearValues = coal.vectorYears();
        vector<double> productionValues = coal.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Natural Gas (Dry)"){
        vector<double> yearValues = naturalGasDry.vectorYears();
        vector<double> productionValues = naturalGasDry.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Crude Oil"){
        vector<double> yearValues = crudeOil.vectorYears();
        vector<double> productionValues = crudeOil.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Natural Gas (Liquid)"){
        vector<double> yearValues = naturalGasPlant.vectorYears();
        vector<double> productionValues = naturalGasPlant.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Fossil Fuel"){
        vector<double> yearValues = fossilFuels.vectorYears();
        vector<double> productionValues = fossilFuels.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Nuclear Electric Power"){
        vector<double> yearValues = nuclearElectric.vectorYears();
        vector<double> productionValues = nuclearElectric.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Hydroelectric Power"){
        vector<double> yearValues = hydroElectric.vectorYears();
        vector<double> productionValues = hydroElectric.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Geothermal Energy"){
        vector<double> yearValues = geothermal.vectorYears();
        vector<double> productionValues = geothermal.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Solar Energy"){
        vector<double> yearValues = solar.vectorYears();
        vector<double> productionValues = solar.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Wind Energy"){
        vector<double> yearValues = wind.vectorYears();
        vector<double> productionValues = wind.vectorValue();
          display(yearValues, productionValues, png, title);
    } else if (inputName == "Biomass Energy"){
        vector<double> yearValues = biomass.vectorYears();
        vector<double> productionValues = biomass.vectorValue();
          display(yearValues, productionValues, png, title);
    }
    



    
    

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