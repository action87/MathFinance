#ifndef SIMPLEMC8_H_INCLUDED
#define SIMPLEMC8_H_INCLUDED

#include "Vanilla3.h"
#include "Parameters.h"
#include "Random2.h"
#include "MCStatistics.h"

void SimpleMonteCarlo6(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer,
                         RandomBase& generator);


#endif // SIMPLEMC8_H_INCLUDED
