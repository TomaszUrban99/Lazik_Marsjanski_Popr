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
    double KatRadiany = StopnieNaRadiany ((Get_KatOrientacji())[ZERO]);
        // Konwersja kąta orientacji łazika na płaszczyźnie XY na radiany

    WspTemp[ZERO] = OdlegloscDoPrzejechania * cos(KatRadiany);
        // Wyznaczenie współrzędnej X o jaką należy przemieścić łazik
    WspTemp[JEDEN] = OdlegloscDoPrzejechania * sin(KatRadiany);
        // Wyznaczenie współrzędnej Y o jaką należy przemieścić łazik

    Get_Polozenie() = Get_Polozenie() + WspTemp;

    Count_and_Save_Cusps();

    OdlegloscDoPrzejechania = 0;
}

bool Lazik::Translate_Lazik_WheelRotation (double Angle)
{
    Wektor3D TempAngle (0, Angle, 0);
        if (AktywneKolo == nullptr) return false;
    
    OdlegloscDoPrzejechania = AktywneKolo->Get_Radius() * StopnieNaRadiany(Angle);

    for ( std::shared_ptr<ObiektGeom> Temp: Get_ListaObiektowSkladowych())
    {
        if (Temp->Wez_ID() == Obiekt_Kolo)
            {
                Temp->Wez_KatOrientacji() = (Temp->Wez_KatOrientacji() + TempAngle) % KAT_PELNY;
                Temp->Change_RotationMatrix();
            }
    }

    TranslacjLazika();
    Count_and_Save_Cusps();
    
    return true;

}