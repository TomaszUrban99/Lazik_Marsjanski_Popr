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

    Lazik () = default;

    Lazik ( Wektor3D& PoczatkowePolozenie, Wektor3D& NowaSkala, 
            Wektor3D& PoczatkowyKatOrientacji, std::string NowaNazwa )
        : Obiekt ( PoczatkowePolozenie, NowaSkala, PoczatkowyKatOrientacji, NowaNazwa ) {}
    
    virtual ~Lazik () = default;
    
    virtual ObiektID Get_ObiektID () const { return Lazik_ID; }
    /* Interfejs klasy Lazik */

    /* Odleglosc do przejechania */
        void Zmien_OdlegloscDoPrzejechania (double Odleglosc)
            { OdlegloscDoPrzejechania = Odleglosc; }
    
    /* Metody klasy Lazik */

    /*!
        \brief Metoda przemieszczająca łazik na określoną odleglosc

            Metoda TranslacjaLazika() pozwala na dokonanie translacji lazika na odleglosc
        przechowywana w polu OdlegloscDoPrzejechania.
            W pierwszej kolejnosci wyliczane są wartości poszczególnych wspólrzędnych
        o jakie należy zwiększyć pola przechowujące położenie łazika na planszy. Przechowywane
        są w pomocniczym obiekcie Wektor3D Wsp. 
            Z racji tego, że ruch będzie translacyjny, następnym krokiem będzie dodanie do
        wektor okeślającego położenie, wyznaczonego wcześniej wektora Wsp.

        Przyjmuje się, że łazik może poruszać się wyłącznie na płaszczyżnie XY.
    */
    void TranslacjLazika();
};

#endif