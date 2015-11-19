#include "SimpleMC7.h"
#include "Random1.h"
#include <cmath>

// namespace std but aren’t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer)
{
    double Expiry=TheOption.GetExpiry();

    double variance=Vol.IntegralSquare(0,Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = Spot * exp(r.Integral(0,Expiry) + itoCorrection);
    double thisSpot;
    double discounting=exp(-r.Integral(0,Expiry));

    for (unsigned long i=0; i < NumberOfPaths; i++){
        double thisGaussian = GetGaussianByBoxMuller();
        thisSpot = movedSpot*exp( rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff * discounting);

    }
 }
