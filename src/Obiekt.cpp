#include "Obiekt.hh"

void Obiekt::Przelicz_I_Zapisz_Wierzcholki ()
{
    for (std::shared_ptr<ObiektGeom> Temp: Lista_Skladowych_ObiektowGeom)
        (*Temp).Przelicz_i_Zapisz_Wierzcholki();
}

/* Przeciążenie operatora wyjścia */
std::ostream& operator<<(std::ostream& Output, 
                            std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych)
{
    for (std::shared_ptr<ObiektGeom> Temp: ListaObiektowSkladowych)
        Output << (*Temp).Get_NazwaElementuSkladowego() << std::endl;

    return Output;
}