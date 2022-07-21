#ifndef LAZIK_HH
#define LAZIK_HH

#include "Obiekt.hh"
#include <cmath>

/*!
    \brief Klasa modelująca pojęcie łazika poruszającego się po scenie
*/
class Lazik: public Obiekt
{
    double OdlegloscDoPrzejechania = 0;
        // Odleglosc o jaką należy przemiescic lazik
    double PredkoscPrzejazdu = 0;
        // Predkosc z jaka łazik powinien zostać przemieszczony
    double KatDoObrotuSt = 0;
        // Kąt wyrażony w stopniach o jaki powinien obrócić się łazik
    double PredkoscObrotu = 0;
        // Prędkość z jaką łazik powinien obrócić się łazik

    public:

    /* Konstruktory klasy Lazik */

    Lazik ( Wektor3D& PoczatkowePolozenie, Wektor3D& NowaSkala, 
            Wektor3D& PoczatkowyKatOrientacji, std::string NowaNazwa )
        : Obiekt ( PoczatkowePolozenie, NowaSkala, PoczatkowyKatOrientacji, NowaNazwa ) {}
    
    /* Interfejs klasy Lazik */

    /* Odleglosc do przejechania */
        void Zmien_OdlegloscDoPrzejechania (double Odleglosc)
            { OdlegloscDoPrzejechania = Odleglosc; }
    
    /* Metody klasy Lazik */

    /* Metoda przemieszczająca łazik na określoną odleglosc */
    void TranslacjLazika();
};

#endif