#include "SimpleMC6.h"
#include "Random1.h"
#include <cmath>

// namespace std but aren�t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths)
{
    double Expiry=TheOption.GetExpiry();

    double variance=Vol.IntegralSquare(0,Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * exp(r.Integral(0,Expiry) + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i=0; i < NumberOfPaths; i++){
        double thisGaussian = GetGaussianByBoxMuller();
        thisSpot = movedSpot*exp( rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r.Integral(0,Expiry));
    return mean;

 }
