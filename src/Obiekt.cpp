#include "Obiekt.hh"

void Obiekt::DodajObiekt(   Wektor3D& PolozenieWzgledne,
                            Wektor3D& OrientacjaWzgledna,
                            std::shared_ptr<ObiektGeom> NowyObiekt )
{
    NowyObiekt->Wez_Polozenie() = _Polozenie + PolozenieWzgledne; 
                                // Wyznaczenie bezwzględnego położenia
                                // składowego obiektu
    NowyObiekt->Wez_KatOrientacji() = _KatOrientacjiSt + OrientacjaWzgledna;
                                // Wyznaczenie bezwględnego kąta orientacji
    Lista_Skladowych_ObiektowGeom.push_back(NowyObiekt);
                                // Dodanie obiektu do listy obiektów składowych
}

/* Przeciążenie operatora wyjścia */
std::ostream& operator<<(std::ostream& Output, 
                            std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych)
{
    for (std::shared_ptr<ObiektGeom> Temp: ListaObiektowSkladowych)
        Output << (*Temp).Get_NazwaElementuSkladowego() << std::endl;

    return Output;
}