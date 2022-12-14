#ifndef SCENA_HH
#define SCENA_HH

#include <list>
#include <memory>

#include "Obiekt.hh"
#include "Lazik.hh"
#include "PowierzchniaMarsa.hh"
#include "lacze_do_gnuplota.hh"
#include "assert.h"
#include <cmath>

constexpr uint CONST_ANIMATION_TRANS_BODY = 100;
constexpr uint CONST_ANIMATION_TRANS_WHEEL = 100;
constexpr uint CONST_ANIMATION_ROTATE = 10;

class Scena {

    std::shared_ptr<Lazik> _ActiveLazik;
        // Shared pointer to the currently active Lazik
    std::list<std::shared_ptr<Obiekt>> Lista_Obiektow_Na_Scenie;
        // Lista wskaźników współdzielonych na obiekty, które mają być wyświetlane na scenie
    PzG::LaczeDoGNUPlota _Lacze;
        // Obiekt klasy LaczeDoGNUPlota stanowiący interfejsc z programem GNUPlot. Klasa została
        // zadeklarowana w pliku nagłówkowym lacze_do_gnuplota.hh

    uint Translation_Animation_Count_Body ();

    uint Translation_Animation_Count_Wheel ( double AngleDegree );

    uint Rotation_Animation_Count ();

    public:

    /* Interfejs klasy Scena */

    /* Aktywny lazik */
        std::shared_ptr<Lazik> Get_ActiveLazik () { return _ActiveLazik; }

        /* Change _ActiveLazik */
        void Change_ActiveLazik ( uint Numer_Lazika);

    /* Lacze do GNUPlota */
        PzG::LaczeDoGNUPlota& Get_Lacze () { return _Lacze; }
    
    /* Lista obiektow na scenie */
        std::list<std::shared_ptr<Obiekt>>& Get_Lista ()
                { return Lista_Obiektow_Na_Scenie; }
    
    /*!
        \brief Metoda inicjalizująca połączenie z programem GNUPlot

        Metoda inicjalizuje połączenie z programem GNUPlot. Dodatkowo ustawiane są
        parametry wyświetlania sceny.
    */
    void Inicjalizuj_Lacze();

    /*!
        \brief Metoda dodająca obiekt klasy Obiekt do listy zawartej w klasie scena.

        \param Obiekt& NowyObiekt - referencja do obiektu, który ma zostać dodany do
        listy obiektów znajdujących się na scenie.   
    */
    template <typename T>
    bool Dodaj_Do_Listy_Scena (T& NowyObiekt);

    /*!
        \brief Metoda dodająca obiekty znajdujące się na liście do listy obiektów
        wyświetlanych przez program GNUPlot.

        Metoda przechodzi przez kolejne elementy listy. Dla każdego obiektu znajdującego się
        na scenie uruchamiana jest metoda Dodaj_Do_Listy_Obiekty, która dodaje wszystkie elementy
        składowe obiektu do listy obiektów rysowanych przez program GNUPlot.
    */
    void Dodaj_Do_ListyRysowania ();

    /*!
        \brief Metoda dodająca poszczególne elementy składowe danego obiektu klasy Obiekt do
        listy brył wyświetlanych przez program GNUPlot.

        \param std::shared_ptr<Obiekt> NowyObiekt - wskaźnik współdzielony na obiekt klasy Obiekt,
        którego elementy składowe powinny zostać wyświetlone przez program GNUPlot.
    */
    void Dodaj_Do_Listy_Obiekty ( std::shared_ptr<Obiekt> NowyObiekt );

    

    /*!
        \brief Method to animate translation movement of the vehicle
    */
   bool Translation_Animation_Body ();

   /*!
        \brief Method to animate translation movement of the vehicle by steering
        it's movement by one of it's wheel.

        \param double AngleDegree - angle expressed in degrees about which the
        wheel should rotate

    */
   bool Translation_Animation_Wheel ( double AngleDegree );

   bool Rotation_Animation ();

};

/* Templates */

/*!
    \brief
*/
template <typename T>
bool Scena::Dodaj_Do_Listy_Scena (T& NowyObiekt)
    {
        if (NowyObiekt.Get_ListaObiektowSkladowych().empty()) return false;
        
        std::shared_ptr<T> WskOb = std::make_shared<T>();
            // Declaration of pointer to the newly created "empty"
            // instance of type T
        *WskOb = NowyObiekt;
            // Assign the new object to the newly created shared pointer
        Lista_Obiektow_Na_Scenie.push_back(WskOb);
            // Put the pointer on the back of the list of objects on the scene
        
        return true;
            // If everything was correct, then return true
    }

/*!
    \brief Przeciążenie operatora wyjścia dla listy wskaźników współdzielonych na obiekty klasy Obiekt
        Metoda wyświetlająca nazwę obiektów znajdujących się na liście.
        
    \param std::ostream& Output- referencja do strumienia wyjściowego, na który ma zostać wyświetlona
    zawartość listy
    \param std::list<std::shared_ptr<Obiekt>>& Lista - lista obiektów jakie mają być wyświetlone

    \retval std::ostream& Output - referencja do strumienia wyjściowego
*/
std::ostream& operator<< ( std::ostream& Output, std::list<std::shared_ptr<Obiekt>>& Lista);

#endif