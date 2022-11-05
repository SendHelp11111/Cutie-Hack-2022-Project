
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
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
    

    while(inFS.ignore(8,',')){
        inFS >> year;
        inFS.get(comma);
        inFS >> eValue;
        inFS.get(comma);
        inFS >> column;
        getline(inFS,line);
    }

    cout << fixed << setprecision(3) << year << " " << eValue << " " << column << " " << endl;
    return 0; 
}