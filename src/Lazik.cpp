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
    
    for (std::shared_ptr<ObiektGeom> Temp: Get_ListaObiektowSkladowych())
    {
        Temp->Wez_Polozenie() = Temp->Wez_Polozenie() + WspTemp;
        Temp->Przelicz_i_Zapisz_Wierzcholki();
    }

    OdlegloscDoPrzejechania = 0;
}