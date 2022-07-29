#include "Lazik.hh"

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