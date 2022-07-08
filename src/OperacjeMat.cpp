#include "OperacjeMat.hh"

constexpr double KAT_POLPELNY = 180;

double StopnieNaRadiany (double AngleSt){ return AngleSt*(M_PI/KAT_POLPELNY);}

int Znak (double Szybkosc)
{
    if (Szybkosc > 0) return 1;
    if (Szybkosc < 0) return -1;
    
    return 0;
}