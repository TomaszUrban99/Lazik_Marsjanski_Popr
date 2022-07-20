#include "Obiekt.hh"

void Obiekt::DodajObiekt(   Wektor3D& PolozenieWzgledne,
                            Wektor3D& OrientacjaWzgledna,
                            ObiektGeom& NowyObiekt )
{ 
    NowyObiekt.Wez_Polozenie() = _Polozenie + PolozenieWzgledne;
                                // Wyznaczenie bezwzględnego położenia
                                // składowego obiektu

    NowyObiekt.Wez_KatOrientacji() = _KatOrientacjiSt + OrientacjaWzgledna;
                                // Wyznaczenie bezwględnego kąta orientacji
    
    std::shared_ptr<ObiektGeom> Wsk =  std::make_shared<ObiektGeom>();
    *Wsk = NowyObiekt;
    Lista_Skladowych_ObiektowGeom.push_back(Wsk);
                                // Dodanie obiektu do listy obiektów składowych
}

bool Obiekt::Przelicz_I_Zapisz_Wierzcholki ()
{

    for (std::shared_ptr<ObiektGeom> Temp: Lista_Skladowych_ObiektowGeom)
    {
        (*Temp).Przelicz_i_Zapisz_Wierzcholki();
    }

    return true;
}

/* Przeciążenie operatora wyjścia */
std::ostream& operator<<(std::ostream& Output, 
                            std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych)
{
    for (std::shared_ptr<ObiektGeom> Temp: ListaObiektowSkladowych)
        Output << (*Temp).Get_NazwaElementuSkladowego() << std::endl;

    return Output;
}