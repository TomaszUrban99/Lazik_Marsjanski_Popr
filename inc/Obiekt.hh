#ifndef OBIEKT_HH
#define OBIEKT_HH

#include <string>
#include <list>
#include <vector>
#include <memory>
#include "ObiektGeom.hh"
#include "Wektor3D.hh"

class Obiekt
{
  
  Wektor3D _Polozenie;
  Wektor3D _Skala;
  Wektor3D _KatOrientacjiSt;

  std::string _NazwaObiektu;
  std::list<std::shared_ptr<ObiektGeom>> Lista_Skladowych_ObiektowGeom;

  public:

  /* Konstruktory i destruktory obiektu klasy Obiekt */

  Obiekt() {};

  Obiekt(Wektor3D& PoczatkowePolozenie, Wektor3D& NowaSkala,
            Wektor3D& PoczatkowyKatOrientacji, std::string NowaNazwa )
    {
        _Polozenie = PoczatkowePolozenie;
        _Skala = NowaSkala;
        _KatOrientacjiSt = PoczatkowyKatOrientacji;
        _NazwaObiektu = NowaNazwa;
    }

    ~Obiekt() = default;

  /* Interfejs klasy Obiekt */

  /* atrybut: _Polozenie */

    /* Uzyskanie dostepu do pola _Polozenie */    
        Wektor3D& Get_Polozenie() {return _Polozenie;}
        Wektor3D Get_Polozenie() const {return _Polozenie;}
        
    /* Zmiana wartosci pola _Polozenie */ 
        void Change_Polozenie(Wektor3D& NowePolozenie)
            { _Polozenie = NowePolozenie; }
        void Change_Polozenie(const Wektor3D NowePolozenie)
            { _Polozenie = NowePolozenie; }

  /* atrybut: _Skala */

    /* Uzyskanie dostepu do pola _Skala */    
        Wektor3D& Get_Skala() {return _Skala;}
        Wektor3D Get_Skala() const {return _Skala;}
    
    /* Zmiana wartosci pola _Skala */
        void Change_Skala(Wektor3D& NowaSkala)
            { _Skala = NowaSkala; }
        void Change_Skala(const Wektor3D NowaSkala)
            { _Skala = NowaSkala; }

  /* atrybut: _KatOrientacjiSt */

    /* Uzyskanie dostepu do pola _KatOrientacjiSt */
        Wektor3D& Get_KatOrientacji() {return _KatOrientacjiSt;}
        Wektor3D Get_KatOrientacji() const {return _KatOrientacjiSt;}
    
    /* Zmiana wartosci pola _KatOrientacjiSt */
        void Change_KatOrientacjiSt (Wektor3D& NowyKatSt)
            { _KatOrientacjiSt = NowyKatSt;}
        void Change_KatOrientacjiSt (const Wektor3D NowyKatSt)
            { _KatOrientacjiSt = NowyKatSt;}
  
  /* atrybut: _NazwaObiektu */
    
    /* Uzyskanie dostepu do pola _NazwaObiektu */
        std::string Get_NazwaObiektu() {return _NazwaObiektu;}
        std::string Get_NazwaObiektu() const {return _NazwaObiektu;}
    
    /* Zmiana wartosci pola _NazwaObiektu */
        void Change_NazwaObiektu (std::string& NowaNazwa)
            { _NazwaObiektu = NowaNazwa;}
        void Change_NazwaObiektu (const std::string NowaNazwa)
            { _NazwaObiektu = NowaNazwa;}
    
  /* atrybut: ListaSkladowych_ObiektowGeom */

    /* Uzyskanie dostepu do pola ListaSkladowych_ObiektowGeom */
        std::list<std::shared_ptr<ObiektGeom>>& Get_ListaObiektowSkladowych ()
            { return Lista_Skladowych_ObiektowGeom; }
    
    /* Metody klasy Obiekt */

    /*!
        \brief Metoda umożliwiająca dodanie składowego obiektu klasy ObiektGeom

        \param Wektor3D& PolozenieWzgledne - referencja do wektora przechowującego położenie dodawanego
            obiektu względem położenia obiektu, do którego dodawana jest 
        \param Wektor3D& OrientacjaWzgledna - referencja do wektora przechowującego względne kąty 
            Eulera wyrażone w stopniach
        \param std::shared_ptr<ObiektGeom> NowyObiekt - wskaźnik na obiekt klasy ObiektGeom, ktory
            zostać dodany do listy obiektow skladowych
    */
   template <typename T>
        void DodajObiekt(   Wektor3D& PolozenieWzgledne,
                            Wektor3D& OrientacjaWzgledna,
                            T& NowyObiekt );

    /*!
        \brief Metoda wyliczająca aktualne współrzędne poszczególnych brył składowych

        Metoda wylicza współrzędne poszczególnych brył dla zadanego położenia obiektu.
    */
        void Przelicz_I_Zapisz_Wierzcholki ();  

};

template <typename T> void Obiekt::DodajObiekt(   Wektor3D& PolozenieWzgledne,
                            Wektor3D& OrientacjaWzgledna,
                            T& NowyObiekt )
{     
    std::shared_ptr<T> Wsk =  std::make_shared<T>();
        *Wsk = NowyObiekt;
    
    Wsk->Wez_Polozenie() = _Polozenie + PolozenieWzgledne;
                                // Wyznaczenie bezwzględnego położenia
                                // składowego obiektu

    Wsk->Wez_KatOrientacji() = _KatOrientacjiSt + OrientacjaWzgledna;
                                // Wyznaczenie bezwględnego kąta orientacji
                                // Dodanie obiektu do listy obiektów składowych

    Lista_Skladowych_ObiektowGeom.push_back(Wsk);
}

/* Przeciążenia operatorów */

/* Operator wypisywania listy obiektu */

/*!
    \brief Przeciążenie operatora wyjścia dla listy wskaźników inteligentnych wskazujących na obiekty
        typu ObiektGeom
    
    \param std::ostream& Output - referencja do strumienia wyjściowego, na który ma zostać wypisana
        zawartość listy
    \param std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych - lista, której zawartość
        ma zostać wypisana
    
    \retval Referencja do strumienia wyjściowego, na który została wypisana zawartość listy.
*/
std::ostream& operator<<(std::ostream& Output, 
                    std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych);


#endif