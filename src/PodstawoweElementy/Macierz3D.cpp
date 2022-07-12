#include "Macierz3D.hh"

/* 
    Metoda zwracająca macierz rotacji wokół osi Z kartezjańskiego układu współrzędnych
        Z-Y-X - kolejność osi wokół, których dokonywana będzie rotacja
*/
void Macierz3D::MacierzRotacji(Wektor3D& KatyOrientacjiSt)
{
    Wektor3D KatyOrientacjiRad = KatyOrientacjiSt.KonwersjaNaRadiany(); // Zapisanie wartości kąta wyrażonej w radianach
    Wektor3D Cosinus = KatyOrientacjiRad.Cosinus(); // Zmienna Cosinus do przechowywania wartości cosinusa kąta
    Wektor3D Sinus = KatyOrientacjiRad.Sinus(); // Zmienna Sinus do przechowywania wartości sinusa kąta

    (*this)(ZERO, ZERO) = Cosinus[ZERO] * Cosinus[JEDEN];
    (*this)(ZERO, JEDEN) = (Cosinus[ZERO] * Sinus[JEDEN] * Sinus[DWA]) - (Sinus[ZERO] * Cosinus[DWA]);
    (*this)(ZERO, DWA) = (Cosinus[ZERO] * Sinus[JEDEN] * Cosinus[DWA]) + (Sinus[ZERO] * Sinus[DWA]);

    (*this)(JEDEN, ZERO) = Sinus[ZERO] * Cosinus[JEDEN];
    (*this)(JEDEN, JEDEN) = (Sinus[ZERO] * Sinus[JEDEN] * Sinus[DWA]) + (Cosinus[ZERO] * Cosinus[DWA]);
    (*this)(JEDEN, DWA) = (Sinus[ZERO] * Sinus[JEDEN] * Cosinus[DWA]) - (Cosinus[ZERO] * Sinus[DWA]);

    (*this)(DWA, ZERO) = (-1) * Sinus[JEDEN];
    (*this)(DWA, JEDEN) = Cosinus[JEDEN] * Sinus[DWA];
    (*this)(DWA, DWA) = Cosinus[JEDEN] * Cosinus[DWA];
}

/* 
    Przeciążenie operatora mnożenia skalarnego trójwymiarowej 
    macierzy (Macierz3D) przez trójwymiarowy wektor (Wektor 3D) 
*/
Wektor3D Macierz3D::operator*(Wektor3D Wektor2) const
{
    Wektor3D Temp;

    for (int i = 0 ; i < ROZMIAR; ++i)
    {
        double Suma = 0;
        for (int j = 0; j < ROZMIAR; ++j){Suma += (*this)(i, j) * (Wektor2[j]);}
        Temp[i] = Suma;
    }
    
    return Temp;
}