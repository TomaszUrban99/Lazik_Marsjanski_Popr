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

bool Scena::Dodaj_Do_Listy_Scena(Obiekt& NowyObiekt)
{

    if (NowyObiekt.Get_ListaObiektowSkladowych().empty()) return false;
   
    std::shared_ptr<Obiekt> WskOb = std::make_shared<Obiekt>(NowyObiekt);
    Lista_Obiektow_Na_Scenie.push_back(WskOb);
            
    return true;
}

void Scena::Dodaj_Do_ListyRysowania()
{
    std::list<std::shared_ptr<Obiekt>>::iterator Iter = Lista_Obiektow_Na_Scenie.begin();

    for ( long unsigned int i = 0; i < Lista_Obiektow_Na_Scenie.size(); ++i)
    {
        Dodaj_Do_Listy_Obiekty((*Iter));
        ++Iter;
    }
}

void Scena::Dodaj_Do_Listy_Obiekty(std::shared_ptr<Obiekt> NowyObiekt)
{
    std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = (NowyObiekt->Get_ListaObiektowSkladowych()).begin();
    PzG::InfoPlikuDoRysowania *wInfo;
    
    for ( long unsigned int i = 0; i < (NowyObiekt->Get_ListaObiektowSkladowych().size()); ++i)
    {
        wInfo = &(Lacze.DodajNazwePliku((*Iter)->Get_NazwaPliku()));
        wInfo->ZmienKolor((*Iter)->Wez_KolorID());
        ++Iter;
    }
}
