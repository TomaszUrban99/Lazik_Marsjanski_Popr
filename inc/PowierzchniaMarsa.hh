#ifndef MARS_HH
#define MARS_HH

#include <iostream>
#include <fstream>
#include <string>

#include "lacze_do_gnuplota.hh"

#define ZAKRES_OS_OX 300 // Zakres osi OX
#define ZAKRES_OS_OY 300 // Zakres osi OY
#define ROZMIAR_KRATKI 10 // Rozmiar pojedynczej kratki
#define NazwaPlikuDoRysowania "pliki_do_rysowania/powierzchnia_planety.dat"
    // Nazwa pliku wraz z ścieżką, z którego program GNUPlot będzie rysował powierzchnie
#define KOLOR_SCENY 4 // identyfikator koloru w jakim wyświetlana będzie scena

/*!
    \brief Funkcja przekazujaca programowi GNUPlot wytyczne dotyczące
    sposobu rysowania powierzchni sceny (Marsa)
*/
bool Stworz_Model_Powierzchni ( std::ofstream& Output);

/*!
    \brief Funkcja otwierająca strumień wejściowy do pliku o nazwie podanej
    jako argument wywołania.

    \param std::string NazwaPliku - nazwa pliku, do którego będzie tworzony strumień
        wejściowy
    
    \retval true - poprawne otwarcie strumienia wejściowego
    \retval false - niepoprawne otwarcie strumienia wejściowego
*/
bool Stworz_Model_Powierzchni_ZapisDoPliku ( std::string NazwaPliku);

/*!
    \brief Funkcja dodająca model powierzchni sceny do listy obiektów rysowanych
        przez program GNUPlot.
    
    \param PzG::LaczeDoGNUPlota& Lacze - referencja do łącza z programem GNUPlot

    \retval true - poprawne stworzenie modelu, otwarcie strumienia wyjściowego i dodanie
        do listy obiektów rysowanych przez program GNUPlot
    \retval false - niepoprawne stworzenie modelu, otwarcie strumienia wyjściowego. Obiekt
        nie został dodany do listy obiektów rysowanych przez program GNUPlot.
*/
bool Dodaj_Do_ListyRysowania ( PzG::LaczeDoGNUPlota& Lacze);

#endif