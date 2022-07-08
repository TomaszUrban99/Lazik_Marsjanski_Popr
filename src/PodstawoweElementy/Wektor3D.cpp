#include "Wektor3D.hh"

/* Przeciążenie operatora mnożenia element to element */
Wektor3D Wektor3D::operator*(Wektor3D& Wektor2) const
{
    Wektor3D Temp;
    for (int i = 0; i < ROZMIAR; ++i) { Temp[i] = ((*this)[i]) * (Wektor2[i]); }
    return Temp;
}

