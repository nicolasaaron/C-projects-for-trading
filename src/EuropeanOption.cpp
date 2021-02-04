#include <math.h>
#include <string>
#include "EuropeanOption.hpp"

using namespace std;

double N(double x)
{
    return erfc(-x / sqrt(2)) / 2;
}


double EuropeanOption::CallPrice() const
{

    double tmp = sig * sqrt(T);

    double d1 = (log(S / K) + (b + sig * sig / 2) * T) / tmp;
    double d2 = d1 - tmp;

    return (S * exp((b - r) * T) * N(d1)) - ( K * exp(- r * T) * N(d2));
}


double EuropeanOption::PutPrice() const
{

    double tmp = sig * sqrt(T);

    double d1 = ( log(S / K) + ( b + sig * sig / 2) * T ) / tmp;
    double d2 = d1 - tmp;

    return ( K * exp( - r * T) * N(-d2) ) - ( S * exp( (b-r) * T) * N(-d1) ); 

}


double EuropeanOption::CallDelta() const
{
    
    double tmp = sig * sqrt(T);
    double d1 = (log(S / K) + (b + sig * sig / 2) * T) / tmp;
    return exp( (b-r) * T) * N(d1);
}



double EuropeanOption::PutDelta() const
{

    double tmp = sig * sqrt(T);
    double d1 = (log(S / K) + (b + sig * sig / 2) * T) / tmp;
    return exp( (b-r) * T) * (N(d1) - 1.0);
}


void EuropeanOption::init()
{

    r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    S = 60.0;
    b = r;
    optType = "Call";

}

void EuropeanOption::copy( const EuropeanOption& o2)
{
    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.T;
    S = o2.S;
    b = o2.b;

    optType = o2.optType;
}

EuropeanOption::EuropeanOption()
{
    // default constructor
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{
    // copy constructor
    copy(o2);
}

EuropeanOption::EuropeanOption(const string& optionType)
{
    init();
    optType = optionType;

    if (optType == "call")
        optType = "Call";

}

EuropeanOption::~EuropeanOption()
{
    return;
}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{
//Assignment operator
    if (this == &option2) return *this;
    copy(option2);
    return *this;
}


// function of calculation
double EuropeanOption::Price() const
{
    if ( optType == "Call")
    {
        return CallPrice();
    }    
    else
        return PutPrice();
}

double EuropeanOption::Delta() const
{
    if (optType == "Call")
        return CallDelta();
    else
        return PutDelta();
}

//Modifier functions
void EuropeanOption::toggle()
{

    if (optType == "Call")
        optType = "Put";
    else
        optType = "Call";
}




