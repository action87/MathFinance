/*
requires
PayOff1.cpp
Random1.cpp,
SimpleMC.cpp,
*/

#include "SimpleMC6.h"
#include "DoubleDigital2.h"
#include "Vanilla3.h"
#include "Parameters.h"
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
    PayOffPut payOffPut(Strike);

    VanillaOption theOption(payOffCall, Expiry);
    VanillaOption thePutOption(payOffPut, Expiry);

    double resultCall = SimpleMonteCarlo3(theOption, Spot,VolParam,rParam,NumberOfPaths);

    theOption=thePutOption;
    double resultPut = SimpleMonteCarlo3(theOption, Spot,VolParam,rParam,NumberOfPaths);

    cout <<"the prices are " << resultCall << " for the call and " << resultPut << " for the put\n";

    double LowerLevel=80;
    double UpperLevel=120;

    PayOffDoubleDigital payOffDoubleDigital(LowerLevel, UpperLevel);

    VanillaOption theDDOption(payOffDoubleDigital, Expiry);

    double resultDD = SimpleMonteCarlo3(theDDOption, Spot,VolParam,rParam,NumberOfPaths);

    cout <<"the price for Double Digital is " << resultDD << endl;

    VanillaOption seconDDOption(theDDOption);

    resultDD = SimpleMonteCarlo3(seconDDOption, Spot,VolParam,rParam,NumberOfPaths);

    cout <<"the price of the 2nd Double Digital is " << resultDD << endl;



    return 0;
}
