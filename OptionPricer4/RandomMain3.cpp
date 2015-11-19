/*
uses source files
        AntiThetic.cpp
        Arrays.cpp,
        ConvergenceTable.cpp,
        MCStatistics.cpp
        Normals.cpp
        Parameters.cpp,
        ParkMiller.cpp
        PayOff3.cpp,
        PayOffBridge.cpp,
        Random2.cpp,
        SimpleMC8.cpp
        Vanilla3.cpp,
*/

#include "ParkMiller.h"
#include "AntiThehetic.h"
#include "SimpleMC8.h"
#include "DoubleDigital2.h"
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include <iostream>
using namespace std;


int main()
{
    double Expiry=1;
    double Strike=100;
    double Spot=100;
    ParametersConstant VolParam(0.1);
    ParametersConstant rParam(0);
    unsigned long NumberOfPaths=10000;

    PayOffCall payOffCall(Strike);

    VanillaOption theOption(payOffCall, Expiry);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);

    SimpleMonteCarlo6(theOption, Spot,VolParam,rParam,NumberOfPaths, gathererTwo, GenTwo);

    vector<vector<double> > results = gathererTwo.GetResultSoFar();

    cout <<"\nFor the call price the results are " << endl;

    for (unsigned long i=0; i < results.size(); i++)
        {
            for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
            cout << "\n";
        }

    return 0;
}
