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
   
    std::shared_ptr<Obiekt> WskOb = std::make_shared<Obiekt>();
    *WskOb = NowyObiekt;
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
    for ( std::shared_ptr<ObiektGeom> Temp: NowyObiekt->Get_ListaObiektowSkladowych())
    {
        PzG::InfoPlikuDoRysowania *wInfo;
        wInfo = &(Lacze.DodajNazwePliku(Temp->Get_NazwaPliku()));
        wInfo->ZmienKolor(Temp->Wez_KolorID());
    }
}

std::ostream& operator<< ( std::ostream& Output, std::list<std::shared_ptr<Obiekt>>& Lista)
{
    for (std::shared_ptr<Obiekt> Temp: Lista)
        std::cout << Temp->Get_NazwaObiektu() << std::endl;

    return Output;
}
