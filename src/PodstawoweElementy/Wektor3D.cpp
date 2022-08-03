#include "Wektor3D.hh"

/* Przeciążenie operatora mnożenia element to element */
Wektor3D Wektor3D::operator*(Wektor3D& Wektor2)
{
    Wektor3D Temp;
    for (int i = 0; i < ROZMIAR; ++i) { Temp[i] = ((*this)[i]) * (Wektor2[i]); }
    return Temp;
}

bool Wektor3D::operator== (Wektor3D& Wektor2)
{
    int j = 0;
    
    for ( int i = 0; i < ROZMIAR; ++i)
        if ((*this)[i] == Wektor2[i]) ++j;
    
    if ( j == ROZMIAR) return true;

    return false;
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

double Wektor3D::DistanceBetweenTwoPoints ( Wektor3D& SecondPoint) const
{
    double Suma = 0;

    for (int i = 0; i < ROZMIAR; ++i)
        Suma += pow( ((*this)[i]-SecondPoint[i]), 2);
    
    return sqrt(Suma);
}



