/*
requires
PayOff1.cpp
Random1.cpp,
SimpleMC.cpp,
*/

#include "SimpleMC4.h"
#include "DoubleDigital2.h"
#include "Vanilla3.h"
#include <iostream>
using namespace std;


int main()
{
    double Expiry=1;
    double Strike=100;
    double Spot=100;
    double Vol=0.1;
    double r=0;
    unsigned long NumberOfPaths=10000;

    PayOffCall payOffCall(Strike);
    PayOffPut payOffPut(Strike);

    VanillaOption theOption(payOffCall, Expiry);
    VanillaOption thePutOption(payOffPut, Expiry);

    double resultCall = SimpleMonteCarlo3(theOption, Spot,Vol,r,NumberOfPaths);

    theOption=thePutOption;
    double resultPut = SimpleMonteCarlo3(theOption, Spot,Vol,r,NumberOfPaths);

    cout <<"the prices are " << resultCall << " for the call and " << resultPut << " for the put\n";

    double LowerLevel=80;
    double UpperLevel=120;

    PayOffDoubleDigital payOffDoubleDigital(LowerLevel, UpperLevel);

    VanillaOption theDDOption(payOffDoubleDigital, Expiry);

    double resultDD = SimpleMonteCarlo3(theDDOption, Spot,Vol,r,NumberOfPaths);

    cout <<"the price for Double Digital is " << resultDD << endl;

    VanillaOption seconDDOption(theDDOption);

    resultDD = SimpleMonteCarlo3(seconDDOption, Spot,Vol,r,NumberOfPaths);

    cout <<"the price of the 2nd Double Digital is " << resultDD << endl;



    return 0;
}
