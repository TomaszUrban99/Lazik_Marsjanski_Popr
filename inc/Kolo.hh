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
        \brief Method to count the radius of the vehicle's wheel

        POST: solid figure should be oriented parallel to the surface XY

        Steps of computing the radius of the wheel:

        #1 opening the input stream (Input) to the file with coordinates of
        original figure

        #2 coordinates will be imported to Temp2 as long as the second coordinate
        (coordinate Y) would be the different in both objects of type Wektor3D 
        (Temp and Temp2). When these coordinates are the same, then the while loop are
        out. 

        #3 After the while loop, the distance beetwen two points which coordinates, are
        temporarily storaged in Temp and Temp2, is being computed using the member function
        DistanceBetweenTwoPoints (Wektor3D) of class Wektor3D. Afterwards the result is
        multiplied, by first coordinate of attribute Skala (inherited member of class Kolo.hh).

        \retval bool true - data for computing were correctly imported, solid
        figure where parallel to the surface XY
        \retval bool false - there were problems with importing data from the
        file, solid figure was not correctly oriented towards surface XY
    */
        bool Count_the_Radius ();
};

#endif