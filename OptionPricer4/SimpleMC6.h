#ifndef SIMPLEMC6_H_INCLUDED
#define SIMPLEMC6_H_INCLUDED

#include "Vanilla3.h"
#include "Parameters.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths);

#endif // SIMPLEMC6_H_INCLUDED
