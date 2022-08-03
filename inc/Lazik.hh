#ifndef LAZIK_HH
#define LAZIK_HH

#include "Obiekt.hh"
#include "Wektor3D.hh"
#include "Kolo.hh"
#include <cmath>
#include <memory>

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

    std::shared_ptr<Kolo> AktywneKolo;

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
        double Get_DistanceToMove () const { return OdlegloscDoPrzejechania; }
        double& Get_DistanceToMove () { return OdlegloscDoPrzejechania; }

        void Zmien_OdlegloscDoPrzejechania (double Odleglosc)
            { OdlegloscDoPrzejechania = Odleglosc; }
    
    /* Velocity of translation */
        double Get_VelocityTranslation () { return PredkoscPrzejazdu; }

        void Change_VelocityTranslation ( double Velocity)
            { PredkoscPrzejazdu = Velocity; }

    /* Active wheel */
        std::shared_ptr<Kolo> Get_AktywneKolo () { return AktywneKolo; }
    
    /* Metody klasy Lazik */

    /*!
        \brief Method for finding the wheel on the list of elementary objects

        Firstly, attribute AktywneKolo is checked, whether it does not point to
        null. If it is so, then it is assumed, that the wheel has already been found,
        and the true value is being returned. Otherwise the list is checked.
        
        The loop goes until the first object of type Kolo is found 
        ( virtual function Wez_ID returns appropiate ID). 
        After that the pointer is cast to Kolo and is assigned to the attribute AktywneKolo. 

        \retval true - active wheel has been found
        \retval false - active has not been found or there were problems by casting
        the pointer from the list
    */
    bool FindTheMainWheel ();

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

    /*!
        \brief Method to translate lazik by rotation of it's wheels

        PRE: AktywneKolo should not point to null

        \param double Angle - the value of an angle to rotate the wheel about

        Firstly, at the base of angle given as parameter (Angle) and the radius
        of the active Wheel, the linear distance to move is counted. It's saved
        in the member OdlegloscDoPrzejechania.

        After that, by every wheel on the list, the orientation angle is changed.
        To keep the orientation angle between 0 and 360, the current value of angle
        is computed with the help of modulo operation.

        After going through the whole list, the method TranslacjaLazika() is run. 

        \retval bool true - 
        \retval bool false - member AktywneKolo points to null
    */
    bool Translate_Lazik_WheelRotation ( double Angle );
};

#endif