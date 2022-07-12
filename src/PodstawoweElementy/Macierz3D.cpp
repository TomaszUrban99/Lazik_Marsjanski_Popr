#include "Macierz3D.hh"

/* Metoda zwracająca macierz rotacji wokół osi Z kartezjańskiego układu współrzędnych */
Macierz3D Macierz3D::MacierzRotacji(Wektor3D KatyOrientacjiSt)
{
    Wektor3D KatyOrientacjiRad = KatyOrientacjiSt.KonwersjaNaRadiany(); // Zapisanie wartości kąta wyrażonej w radianach
    Wektor3D Cosinus = KatyOrientacjiRad.Cosinus(); // Zmienna Cosinus do przechowywania wartości cosinusa kąta
    Wektor3D Sinus = KatyOrientacjiRad.Sinus(); // Zmienna Sinus do przechowywania wartości sinusa kąta

    (*this)(ZERO, ZERO) = Cosinus;
    (*this)(ZERO, JEDEN) = (-1)*Sinus;
    (*this)(ZERO, DWA) = ZERO;

    (*this)(JEDEN, ZERO) = Sinus;
    (*this)(JEDEN, JEDEN) = Cosinus;
    (*this)(JEDEN, DWA) = ZERO;

    (*this)(DWA, ZERO) = ZERO;
    (*this)(DWA, JEDEN) = ZERO;
    (*this)(DWA, DWA) = JEDEN;

    return (*this);
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