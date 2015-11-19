#ifndef PAYOFF3_H_INCLUDED
#define PAYOFF3_H_INCLUDED

class PayOff
{

public:
    PayOff(){};
    virtual double operator()(double Spot) const=0;
    virtual PayOff* clone() const=0;
    virtual ~PayOff(){}

private:
};

class PayOffCall: public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffCall(){}

private:
    double Strike;

};

class PayOffPut: public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual PayOff* clone() const;
    virtual ~PayOffPut(){}

private:
    double Strike;

};

#endif // PAYOFF3_H_INCLUDED
