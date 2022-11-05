#include "EnergySource.h"
#include <iostream>

EnergySource::EnergySource(int year, double value, int order) {
    _year = year;
    _value = value;
    _order = order;

    names = {"Coal Production", "Natural Gas (Dry)", "Crude Oil Production", "Natural Gas (Liquid)", "Total Fossil Fuel Production"
        , "Nuclear Electric Power Production", "Hydroelectric Power Production", "Geothermal Energy Production", "Solar Energy Production"
        , "Wind Energy Production", "Biomass Energy Production", "Total Renewable Energy Production", "Total Primary Energy Production"};
    
    _type = names.at(_order-1);
}