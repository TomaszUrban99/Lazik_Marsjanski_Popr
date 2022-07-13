#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

#include <cmath>
#include "OperacjeMat.hh"
#include "SMacierz.hh"
#include "Wektor3D.hh"

using Wektor = SWektor<double, ROZMIAR>;

constexpr int JEDEN = 1;
constexpr int DWA = 2;

/*!
    \brief Klasa modelująca pojęcie macierzy trójwymiarowej.

    Klasa Macierz3D dziedziczy z klasy SMacierz zdefiniowanej w pliku nagłówkowym
    SMacierz.hh.

*/
class Macierz3D : public SMacierz<Wektor, double, ROZMIAR>{
    
    public:

    /*!
        \brief Metoda wyliczająca macierz rotacji, dla aktualnej orientacji.

        \param Wektor3D& KatyOrientacjiSt - referencja do obiektu klasy Wektor3D, przechowującego
        wartość kątów obrotu wokół osi Z-Y-X (w takiej samej kolejności) wyrażonych w STOPNIACH.

        W pierwszej kolejność wartości kątów przechowywane w zmiennej KatyOrientacjiSt są przeliczane
        na radiany i zapisywane w tymczasowym obiekcie typu Wektor3D - KatyOrientacjiRad. Następnie tworzone
        są obiekty przechowujące cosinusy i sinusy kątów.

        \retval BRAK - metoda typu void
    */
    void MacierzRotacji (Wektor3D& KatyOrientacjiSt);

    /*!
        \brief Przeciążenie operatora mnożenia skalarnego trójwymiarowej macierzy i wektora.

        Metoda wyznacza wartość iloczynu skalarnego obiektu klasy Macierz3D przez obiekt klasy
        Wektor3D. Przeciążenie nie modyfikuje parametrów wywołania.

        \param Wektor3D Wektor2 - wektor przez, który skalarnie zostanie przemnożona macierz, dla
        której przeciążenie zostało wywołane

        \retval Wartość mnożenia skalarnego dwóch parametrów wywołania.
    */
    Wektor3D operator* (Wektor3D Wektor2) const;
};

#endif