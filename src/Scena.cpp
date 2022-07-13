#include "Scena.hh"

void Scena::Inicjalizuj_Lacze()
{
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresX(-ZAKRES_OS_OX/2, ZAKRES_OS_OX/2);
    Lacze.UstawZakresY(-ZAKRES_OS_OY/2, ZAKRES_OS_OY/2);
    Lacze.UstawZakresZ(0,90);
    Lacze.UstawRotacjeXZ (40, 60);
    Lacze.Inicjalizuj();
}