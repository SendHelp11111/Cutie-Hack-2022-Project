
#include <iostream>
#include <fstream>
#include <vector>
#include "EnergySource.h"
#include "TotalEnergy.h"
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

void display(vector<double> &years, vector<double> &energyProduction);

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
    getline(inFS, line);    

    while(inFS.ignore(8,',')){
        inFS >> year; inFS.get(comma); 
        inFS >> eValue; inFS.get(comma); 
        inFS >> column;
        getline(inFS,line);

        EnergySource e(year, eValue, column);
        current.add(e);
    }
    inFS.close();

    for(unsigned int i = 0; i < current.getArr().size(); i++){
         cout << fixed << setprecision(3) << current.getArr().at(i);
    }
    vector<double> x;
    for(int i = 0; i < 10; ++i) {
        x.push_back(i*2.5);
    }
    vector<double> y;
    for(int i = 0; i < 10; ++i) {
        y.push_back(i*3.7);
    }
    display(x, y);
    return 0; 
}

void display(vector<double> &years, vector<double> &energyProduction) {
    bool success;
    StringReference *errorMessage;
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series->xs = &years;
    series->ys = &energyProduction;
    series->color = CreateRGBColor(0,0,1);

    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings->title = toVector(L"test");
    settings->width = 900;
    settings->height = 600;
    settings->xLabel = toVector(L"Year");
    settings->yLabel = toVector(L"Energy Production");
    settings->scatterPlotSeries->push_back(series);

    success = DrawScatterPlotFromSettings(imageRef, settings, errorMessage);

    if (success) {
        vector<double> *pngdata = ConvertToPNG(imageRef->image);
        WriteToFile(pngdata, "test.png");
        DeleteImage(imageRef->image);
    } else {
        cout << "Error drawing plot";
    }
}