#ifndef SIMPLEMC4_H_INCLUDED
#define SIMPLEMC4_H_INCLUDED

#include "Vanilla3.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);


#endif // SIMPLEMC4_H_INCLUDED
