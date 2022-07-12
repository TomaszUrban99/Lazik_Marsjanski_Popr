#ifndef OBIEKT_HH
#define OBIEKT_HH

#include <string>
#include <list>
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

  Obiekt(Wektor3D PoczatkowePolozenie, Wektor3D NowaSkala,
            Wektor3D PoczatkowyKatOrientacji, std::string NowaNazwa,
            std::list<std::shared_ptr<ObiektGeom>> ListaObiektow)
    {
        _Polozenie = PoczatkowePolozenie;
        _Skala = NowaSkala;
        _KatOrientacjiSt = PoczatkowyKatOrientacji;
        _NazwaObiektu = NowaNazwa;
        Lista_Skladowych_ObiektowGeom = ListaObiektow;
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
    
    /* Metody klasy Obiekt */
    
};


#endif