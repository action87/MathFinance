/*
uses source files
    MCStatistics.cpp,
    Parameters.cpp,
    PayOff3.cpp,
    PayOffBridge.cpp,
    Random1.cpp,
    SimpleMC7.cpp,
    Vanilla3.cpp,
*/

#include "SimpleMC7.h"
#include "DoubleDigital2.h"
#include "Vanilla3.h"
#include "Parameters.h"
#include "MCStatistics.h"
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

    SimpleMonteCarlo5(theOption, Spot,VolParam,rParam,NumberOfPaths, gatherer);

    vector<vector<double> > results = gatherer.GetResultSoFar();

    cout <<"\nFor the call price the results are " << endl;

    for (unsigned long i=0; i < results.size(); i++)
        {
            for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
            cout << "\n";
        }

    return 0;
}
