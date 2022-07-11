#include "ObiektGeom.hh"

/* 
    Metoda do otwierania strumieni wejścia/wyjścia oraz do obliczenia aktualnych współrzędnych
    za pośrednictwem metody Przelicz_i_Zapisz_Wierzcholki (std::istream& Input, std::ostream& Output)
*/
bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
    std::ifstream Input (NazwaPliku_BrylaWzorcowa);
        if(Input.fail()) return false;
    
    std::ofstream Output (NazwaPliku_PlikDoRysowania);
        if(Output.fail()) return false;

    if(Przelicz_i_Zapisz_Wierzcholki(Input, Output)) return true;

    return false;
}

/* Metoda do odczytu, obliczenia i zapisu wyliczonych współrzędnych */
bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::istream& Input, std::ostream& Output)
{
    int Indeks = 0;     // Zmienna pomocnicza do zliczania liczby pobranych wierszy
    Wektor3D WspWierz;  // Zmienna tymczasowa do przechowywania wiersza wspolrzednych
                        // pobranych z pliku
    
    while(!Input.fail())
    {
        Input >> WspWierz; // Pobranie współrzednych jednego wierzcholka z pliku z bryłą wzorcową
            if(Input.fail()) return false;
        
        WspWierz = MacierzRotacji * ( Skala * WspWierz ) + Polozenie;
            // Wyliczenie nowych współrzędnych
        
        Output << WspWierz; // Zapis współrzędnych do pliku, z którego będzie rysował GNUplot
            if(Output.fail()) return false;
        
        ++Indeks; // Po wykonaniu kompletu operacji (odczyt, zapis, obliczenia) zwiększ wartość zmiennej
                // Indeks o jeden
    }
    
    if(!Input.eof() || ( Indeks%4 != 0 )) return false;
        // Sprawdzenie czy działanie pętli nie zakończyło się w wyniku napotkania znaku końca pliku
        // oraz sprawdzenie, czy liczba wierszy jest poprawna tzn. czy jest podzielna przez 4

    return true; // Gdy operacje przebiegły zgodnie z planem zwróć wartość true
}