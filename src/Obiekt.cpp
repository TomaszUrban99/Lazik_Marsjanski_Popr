#include "Obiekt.hh"

void Obiekt::Count_and_Save_Cusps ()
{
    for (std::shared_ptr<ObiektGeom> Temp: Lista_Skladowych_ObiektowGeom)
        Temp->Count_and_Save_Cusps(_RotationMatrix, _Polozenie);
}

/* Przeciążenie operatora wyjścia */
std::ostream& operator<<(std::ostream& Output, 
                            std::list<std::shared_ptr<ObiektGeom>> ListaObiektowSkladowych)
{
    for (std::shared_ptr<ObiektGeom> Temp: ListaObiektowSkladowych)
        Output << (*Temp).Get_NazwaElementuSkladowego() << std::endl;

    return Output;
}