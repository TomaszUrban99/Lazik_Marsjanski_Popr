#ifndef OBIEKT_HH
#define OBIEKT_HH

#include <string>
#include <list>
#include <vector>
#include <memory>
#include "ObiektGeom.hh"
#include "Kolo.hh"
#include "Kadlub.hh"
#include "Wektor3D.hh"

/*!
    \brief Identyfing type for classification of derived objects from base class Obiekt

    #1 Lazik_ID - identificator for derived class Lazik (defined in header file "Lazik.hh")
    #2 ProbkaRegolitu_ID - identificator for derived class ProbkaRegolitu (defined in header file
    ProbkaRegolitu.hh)
*/
enum ObiektID { Lazik_ID, ProbkaRegolitu_ID};

class Obiekt
{
  
  Wektor3D _Polozenie;
  Wektor3D _Skala;
  Wektor3D _KatOrientacjiSt;

  Macierz3D _RotationMatrix;

  std::string _NazwaObiektu;
  static std::string _TempFileCusps;
    // Name of the temporary file
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
        _RotationMatrix.MacierzRotacji(_KatOrientacjiSt);

        _NazwaObiektu = NowaNazwa;
    }

   virtual ~Obiekt() = default;

/*!
    \brief Method for identication of derived classes
        Pure virtual method. It enables identification of type of objects, enabling
        safe casting of objects.
*/
virtual enum ObiektID Get_ObiektID () const = 0;

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
        void Change_KatOrientacjiSt (Wektor3D NowyKatSt)
            { _KatOrientacjiSt = NowyKatSt;}
        
        void Add_KatOrientacjiSt (Wektor3D& AddKatSt)
            { 
                _KatOrientacjiSt = _KatOrientacjiSt + AddKatSt; 
                _RotationMatrix.MacierzRotacji(_KatOrientacjiSt);
            }
    
    /* Rotation matrix */
        Macierz3D& Get_MacierzRotacji () { return _RotationMatrix; }
  
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
        \brief Metoda umo??liwiaj??ca dodanie sk??adowego obiektu klasy ObiektGeom

        \param Wektor3D& PolozenieWzgledne - referencja do wektora przechowuj??cego po??o??enie dodawanego
            obiektu wzgl??dem po??o??enia obiektu, do kt??rego dodawana jest 
        \param Wektor3D& OrientacjaWzgledna - referencja do wektora przechowuj??cego wzgl??dne k??ty 
            Eulera wyra??one w stopniach
        \param std::shared_ptr<ObiektGeom> NowyObiekt - wska??nik na obiekt klasy ObiektGeom, ktory
            zosta?? dodany do listy obiektow skladowych
    */
    template <class T>
        void DodajObiekt(   Wektor3D& PolozenieWzgledne,
                            Wektor3D& OrientacjaWzgledna,
                            T& NowyObiekt );
    /*!
        \brief Metoda wyliczaj??ca aktualne wsp????rz??dne poszczeg??lnych bry?? sk??adowych

        Metoda wylicza wsp????rz??dne poszczeg??lnych bry?? dla zadanego po??o??enia obiektu.
    */
        void Count_and_Save_Cusps ();  

};

/*!
    \brief Szablon metody dodaj??cej sk??adowe elemtny do listy obiekt??w obiektu typu Obiekt.
*/
template <class T>
void Obiekt::DodajObiekt(   Wektor3D& PolozenieWzgledne,
                            Wektor3D& OrientacjaWzgledna,
                            T& NowyObiekt )
{     
    std::shared_ptr<T> Wsk =  std::make_shared<T>();
        // Deklaracja wska??nika na obiekt okre??lony typem T
    *Wsk = NowyObiekt;
        // Przypisanie nowo utworzonego obiektu do stworzonego
        // wska??nika wsp????dzielonego
    
    Wsk->Wez_Polozenie() = PolozenieWzgledne;
                                // Wyznaczenie bezwzgl??dnego po??o??enia
                                // sk??adowego obiektu
    
    Wsk->Wez_KatOrientacji() = OrientacjaWzgledna;
                                // Wyznaczenie bezwgl??dnego k??ta orientacji
                                // Dodanie obiektu do listy obiekt??w sk??adowychs
    
    Wsk->Change_RotationMatrix();

    Lista_Skladowych_ObiektowGeom.push_back(Wsk);
        // Umieszczenie obiektu na li??cie obiekt??w sk??adowych
}

/* Przeci????enia operator??w */

/* Operator wypisywania listy obiektu */

/*!
    \brief Przeci????enie operatora wyj??cia dla listy wska??nik??w inteligentnych wskazuj??cych na obiekty
        typu ObiektGeom
    
    \param std::ostream& Output - referencja do strumienia wyj??ciowego, na kt??ry ma zosta?? wypisana
        zawarto???? listy
    \param std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych - lista, kt??rej zawarto????
        ma zosta?? wypisana
    
    \retval Referencja do strumienia wyj??ciowego, na kt??ry zosta??a wypisana zawarto???? listy.
*/
std::ostream& operator<<(std::ostream& Output, 
                    std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych);


#endif