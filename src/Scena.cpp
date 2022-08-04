#include "Scena.hh"

void Scena::Inicjalizuj_Lacze()
{
    _Lacze.ZmienTrybRys(PzG::TR_3D);
    _Lacze.UstawZakresX(-ZAKRES_OS_OX/2, ZAKRES_OS_OX/2);
    _Lacze.UstawZakresY(-ZAKRES_OS_OY/2, ZAKRES_OS_OY/2);
    _Lacze.UstawZakresZ(0,90);
    _Lacze.UstawRotacjeXZ (40, 60);
    _Lacze.Inicjalizuj();
}

void Scena::Change_ActiveLazik(uint NumerLazika)
{
    int i = 0;
        // Variable for counting objects;

    for (std::shared_ptr<Obiekt> Temp: Lista_Obiektow_Na_Scenie)
    {
        if ( Temp->Get_ObiektID() == Lazik_ID)
        {
            if ( (++i) == NumerLazika)
            {
                std::shared_ptr<Lazik> TempDoLazika = std::dynamic_pointer_cast<Lazik>(Temp);
                _ActiveLazik = TempDoLazika;
            }
        }
    }
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
        wInfo = &(_Lacze.DodajNazwePliku(Temp->Get_NazwaPliku()));
        wInfo->ZmienKolor(Temp->Wez_KolorID());
    }
}

uint Scena::Translation_Animation_Count_Body ()
{
    return ceil ( fabs ( _ActiveLazik->Get_DistanceToMove()) / fabs ( _ActiveLazik->Get_VelocityTranslation())) * CONST_ANIMATION_TRANS_BODY;
}

uint Scena::Translation_Animation_Count_Wheel ( double AngleDegree )
{
    return ceil ( fabs (AngleDegree) / fabs ( _ActiveLazik->Get_VelocityTranslation())) * CONST_ANIMATION_TRANS_WHEEL;
}

/* Method to count the number of frames to divide the rotation movement */
uint Scena::Rotation_Animation_Count ()
{
    return ceil ( fabs (_ActiveLazik->Get_AngleToRotate()) / fabs ( _ActiveLazik->Get_VelocityRotation())) * CONST_ANIMATION_ROTATE;
}

bool Scena::Translation_Animation_Body()
{
    assert(_ActiveLazik->Get_VelocityTranslation() < CONST_ANIMATION_TRANS_BODY * (_ActiveLazik->Get_DistanceToMove()));
    uint Count = Translation_Animation_Count_Body();

    double DistancePeriod = (_ActiveLazik->Get_DistanceToMove()) / Count;

    for ( uint i = 0; i < Count; ++i)
    {
        _ActiveLazik->Get_DistanceToMove() = DistancePeriod;
        _ActiveLazik->TranslacjLazika();
        _Lacze.Rysuj();
    }

    return true;
}

bool Scena::Translation_Animation_Wheel( double AngleDegree)
{
    uint Count = Translation_Animation_Count_Wheel ( AngleDegree );
    double AnglePeriod = AngleDegree / Count;

    for ( uint i = 0; i < Count; ++i)
    {
        _ActiveLazik->Translate_Lazik_WheelRotation(AnglePeriod);
        _Lacze.Rysuj();
    }

    return true;
}

bool Scena::Rotation_Animation()
{
    uint Count = Rotation_Animation_Count ();
    double AnglePeriod = _ActiveLazik->Get_AngleToRotate() / Count;

    for ( uint i = 0; i < Count; ++i)
    {
        _ActiveLazik->Get_AngleToRotate() = AnglePeriod;
        _ActiveLazik->Rotate_Lazik();
        _Lacze.Rysuj();
    }

    _ActiveLazik->Get_AngleToRotate() = 0;

    return true;
}

std::ostream& operator<< ( std::ostream& Output, std::list<std::shared_ptr<Obiekt>>& Lista)
{
    for (std::shared_ptr<Obiekt> Temp: Lista)
        std::cout << Temp->Get_NazwaObiektu() << std::endl;

    return Output;
}
