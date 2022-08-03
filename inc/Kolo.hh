#ifndef KOLO_HH
#define KOLO_HH

#include "ObiektGeom.hh"

class Kolo: public ObiektGeom {

    double Radius = 0;
        // Radius of the wheel

    public:

    /* Konstruktory klasy Kolo */

        Kolo () {}

        Kolo ( int Kolor, Wektor3D& KatPoczatkowy,
                    Wektor3D& PolozeniePoczatkowe, Wektor3D& SkalaPoczatkowa,
                    std::string NazwaElementuSkladowego, 
                    std::string NazwaPlikuBrylaWzorcowa,
                    std::string NazwaPlikuBrylaDoRysowania ) : 
                ObiektGeom ( 
                    Kolor, KatPoczatkowy, PolozeniePoczatkowe, SkalaPoczatkowa,
                    NazwaElementuSkladowego, NazwaPlikuBrylaWzorcowa,
                    NazwaPlikuBrylaDoRysowania )
        {}

        virtual ~Kolo () {};

    /*!
        \brief Metoda zwracajaca identyfiaktor typu obiektu.
    */
        virtual enum Obiekt_ID Wez_ID () const override { return Obiekt_Kolo;}

    /* Interface of class Kolo */
        
        /*! 
            \brief Method returning the value of attribute "Radius" 
        */ 
        double Get_Radius () const { return Radius; }

    /*!
        \brief Method to count the radius of the wheel
    */
        bool Count_the_Radius ();
};

#endif