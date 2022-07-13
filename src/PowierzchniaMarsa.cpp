#include "PowierzchniaMarsa.hh"

/* 
    Funkcja tworząca model powierzchni sceny 
*/
bool Stworz_Model_Powierzchni ( std::ofstream& Output)
{
    for ( int i = -ZAKRES_OS_OX/2; i <= ZAKRES_OS_OX/2; i += ROZMIAR_KRATKI)
    {
        for ( int j = -ZAKRES_OS_OY/2; j<=ZAKRES_OS_OY/2; j += ROZMIAR_KRATKI)
                            Output << i << " " << j << " 0" << std::endl;
        Output << std::endl;
    }

    return !Output.fail();
}

/* 
    Funkcja otwierająca strumień wyjściowy do pliku o 
        nazwie podanej jako argument wywołania
*/
bool Stworz_Model_Powierzchni_ZapiszDoPliku ( std::string NazwaPliku)
{
    std::ofstream Output (NazwaPliku);
    
    if ( !Output.is_open()){
        std::cerr << "Nie udalo sie otworzyc pliku: " << std::endl;
        std::cerr << NazwaPliku << std::endl;
        return false;
    }

    return Stworz_Model_Powierzchni(Output);
}

/*
    Funkcja dodająca model powierzchni sceny do listy obiektów rysowanych
    przez program GNUPlot
*/
bool Dodaj_Do_ListyRysowania ( PzG::LaczeDoGNUPlota& Lacze)
{
    if (!Stworz_Model_Powierzchni_ZapiszDoPliku ( NazwaPlikuDoRysowania )) return false;

    PzG::InfoPlikuDoRysowania *wInfoPliku;

    wInfoPliku = &Lacze.DodajNazwePliku(NazwaPlikuDoRysowania);
    wInfoPliku->ZmienKolor (KOLOR_SCENY);

    return true;
}