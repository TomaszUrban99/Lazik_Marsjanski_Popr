#ifndef KOLO_HH
#define KOLO_HH

#include "ObiektGeom.hh"

class Kolo: public ObiektGeom {

    public:

    /*!
        \brief Metoda zwracajaca identyfiaktor typu obiektu.
    */
        enum Obiekt_ID Wez_ID () { return Obiekt_Kolo;}
};

#endif