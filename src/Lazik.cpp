#include "Lazik.hh"

bool Lazik::FindTheMainWheel ()
{
    if ( AktywneKolo == nullptr )
    {
        for (std::shared_ptr<ObiektGeom> Temp: Get_ListaObiektowSkladowych() )
        {
            if ( Temp->Wez_ID() == Obiekt_Kolo )
            {
                std::shared_ptr<Kolo> Wsk = std::dynamic_pointer_cast<Kolo> (Temp);
                if (Wsk != nullptr)
                {
                    AktywneKolo = Wsk;
                    return true;
                        // if after casting, the pointer does not point to null,
                        // then end function and return true (everything seems to be
                        // correct )
                }
            }
        }
    }
    else return true;
        // if AktywneKolo does not point to null, then return true;

    if ( AktywneKolo == nullptr ) return false;
        // if afterwards AktywneKolo points to null, then return false,
        // ( something has gone wrong )
}

void Lazik::TranslacjLazika()
{
    Wektor3D WspTemp;
    Wektor3D Angle  ( 0, 0, 0);
    double KatRadiany = StopnieNaRadiany ((Get_KatOrientacji())[ZERO]);
        // Konwersja kąta orientacji łazika na płaszczyźnie XY na radiany

    WspTemp[ZERO] = OdlegloscDoPrzejechania * cos(KatRadiany);
        // Wyznaczenie współrzędnej X o jaką należy przemieścić łazik
    WspTemp[JEDEN] = OdlegloscDoPrzejechania * sin(KatRadiany);
        // Wyznaczenie współrzędnej Y o jaką należy przemieścić łazik

    Get_Polozenie() = Get_Polozenie() + WspTemp;

    Angle[1] = RadianyNaStopnie (OdlegloscDoPrzejechania / (AktywneKolo->Get_Radius()));

    for ( std::shared_ptr<ObiektGeom> Temp: Get_ListaObiektowSkladowych())
    {
        if ( Temp->Wez_ID() == Obiekt_Kolo )
        {
            Temp->Wez_KatOrientacji() = (Temp->Wez_KatOrientacji() + Angle) % KAT_PELNY;
            Temp->Change_RotationMatrix();
        }
    }
    
    Count_and_Save_Cusps();
    OdlegloscDoPrzejechania = 0;
}

bool Lazik::Translate_Lazik_WheelRotation (double Angle)
{
    Wektor3D TempAngle (0, Angle, 0);
        if (AktywneKolo == nullptr) return false;
    
    OdlegloscDoPrzejechania = AktywneKolo->Get_Radius() * StopnieNaRadiany(Angle);

    TranslacjLazika();
    Count_and_Save_Cusps();
    
    return true;

}

/* Metohod to rotate the vehicle */
    bool Lazik::Rotate_Lazik()
    {
        Wektor3D Temp ( KatDoObrotuSt, 0, 0);

        Add_KatOrientacjiSt ( Temp );
        Get_MacierzRotacji().MacierzRotacji(Get_KatOrientacji());
        Count_and_Save_Cusps();

        KatDoObrotuSt = 0;

        return true;
    }