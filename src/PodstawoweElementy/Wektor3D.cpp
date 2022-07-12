#include "Wektor3D.hh"

/* Przeciążenie operatora mnożenia element to element */
Wektor3D Wektor3D::operator*(Wektor3D& Wektor2) const
{
    Wektor3D Temp;
    for (int i = 0; i < ROZMIAR; ++i) { Temp[i] = ((*this)[i]) * (Wektor2[i]); }
    return Temp;
}

Wektor3D Wektor3D::KonwersjaNaRadiany() const
{
    Wektor3D Temp;

    for (uint i = 0; i < ROZMIAR; ++i)
        Temp[i] = StopnieNaRadiany((*this)[i]);
    
    return Temp;
}

Wektor3D Wektor3D::Cosinus() const
{
    Wektor3D Temp;

    for (uint i = 0; i < ROZMIAR; ++i)
        Temp[i] = cos((*this)[i]);
    
    return Temp;
}

Wektor3D Wektor3D::Sinus() const
{
    Wektor3D Temp;

    for (uint i = 0; i < ROZMIAR; ++i)
        Temp[i] = sin((*this)[i]);
    
    return Temp;
}



