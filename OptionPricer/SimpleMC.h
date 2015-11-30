#ifndef SIMPLEMC_H_INCLUDED
#define SIMPLEMC_H_INCLUDED

#include "Vanilla.h"
#include "Parameters.h"
#include "Random.h"
#include "MCStatistics.h"

void SimpleMonteCarlo(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer,
                         RandomBase& generator);


#endif // SIMPLEMC_H_INCLUDED
