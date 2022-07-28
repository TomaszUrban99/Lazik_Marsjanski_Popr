#ifndef KADLUB_HH
#define KADLUB_HH

#include "ObiektGeom.hh"

class Kadlub: public ObiektGeom {
    
    public:

    /* Konstruktory klasy Kadlub */

        Kadlub () {};

        Kadlub ( int Kolor, Wektor3D& KatPoczatkowy,
                    Wektor3D& PolozeniePoczatkowe, Wektor3D& SkalaPoczatkowa,
                    std::string NazwaElementuSkladowego, 
                    std::string NazwaPlikuBrylaWzorcowa,
                    std::string NazwaPlikuBrylaDoRysowania ) : 
                ObiektGeom ( 
                    Kolor, KatPoczatkowy, PolozeniePoczatkowe, SkalaPoczatkowa,
                    NazwaElementuSkladowego, NazwaPlikuBrylaWzorcowa,
                    NazwaPlikuBrylaDoRysowania )
        {};

        virtual ~Kadlub () {};

    virtual enum Obiekt_ID Wez_ID () const override { return Obiekt_Kadlub;}
};

#endif