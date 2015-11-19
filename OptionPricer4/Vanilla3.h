#ifndef VANILLA3_H_INCLUDED
#define VANILLA3_H_INCLUDED

#include "PayOffBridge.h"

class VanillaOption{
    public:
        VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
        double OptionPayOff(double Spot) const;
        double GetExpiry() const;

    private:
        double Expiry;
        PayOffBridge ThePayOff;
};

#endif // VANILLA3_H_INCLUDED
