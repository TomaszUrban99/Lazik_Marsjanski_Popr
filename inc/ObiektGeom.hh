#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"

/*!
    \brief Typ wyliczeniowy klasyfikujący rodzaj poszczególnych obiektów geometrycznych
*/
enum Obiekt_ID { Obiekt_G, Obiekt_Kolo, Obiekt_Kadlub};

class ObiektGeom
{
    /* Atrybuty klasy ObiektGeom */

    int KolorID;
    
    Wektor3D KatOrientacji;
    Wektor3D Polozenie;
    Wektor3D Skala;

    Macierz3D MacierzRotacji;

    std::string Nazwa_ElementuSkladowego;
    std::string NazwaPliku_BrylaWzorcowa;
    std::string NazwaPliku_PlikDoRysowania;

    public:

    /* Konstruktory i destruktory klasy ObiektGeom */

    ObiektGeom () = default;

    ObiektGeom ( int Kolor, Wektor3D& KatPoczatkowy,
                    Wektor3D& PolozeniePoczatkowe, Wektor3D& SkalaPoczatkowa,
                    std::string NazwaElementuSkladowego, 
                    std::string NazwaPlikuBrylaWzorcowa,
                    std::string NazwaPlikuBrylaDoRysowania )
    {
        KolorID = Kolor;
        KatOrientacji = KatPoczatkowy;
        MacierzRotacji.MacierzRotacji(KatOrientacji);
        Polozenie = PolozeniePoczatkowe;
        Skala = SkalaPoczatkowa;
        Nazwa_ElementuSkladowego = NazwaElementuSkladowego;
        NazwaPliku_BrylaWzorcowa = NazwaPlikuBrylaWzorcowa;
        NazwaPliku_PlikDoRysowania = NazwaPlikuBrylaDoRysowania;
    }

    ObiektGeom (const ObiektGeom&) = default;

    virtual ~ObiektGeom() = default;

    /* Identyfikacja klasy ObiektGeom */
        virtual enum Obiekt_ID Wez_ID () const = 0;

    /* Interfejs klasy ObiektGeom */

    /* KolorID */

        /* Dostęp do identyfikatora koloru */
            int Wez_KolorID () const { return KolorID; }
            int& Wez_KolorID () { return KolorID; }

        /* Zmiana koloru */
            void Zmien_KolorID (int NowyKolorID) { KolorID = NowyKolorID;}

    /* Kat Orientacji */
        
        /* Dostep do wartosci/referencji */
            Wektor3D& Wez_KatOrientacji () { return KatOrientacji;}
            Wektor3D Wez_KatOrientacji () const { return KatOrientacji;}
        
        /* Zmiana wartosci pola */
            void Zmien_KatOrientacji (Wektor3D& NowyKatOrientacjiSt)
                { KatOrientacji = NowyKatOrientacjiSt; }
            void Zmien_KatOrientacji (const Wektor3D NowyKatOrientacjiSt)
                { KatOrientacji = NowyKatOrientacjiSt; }
        
        /*  Rotation matrix - access */
            Macierz3D& Get_RotationMatrix () { return MacierzRotacji; }
            Macierz3D Get_RotationMatrix () const { return MacierzRotacji; }
        
        /* Rotation matrix- value change */
            void Change_RotationMatrix () { MacierzRotacji.MacierzRotacji(KatOrientacji);}
        
    /* Polozenie */

        /* Dostep do wartosci/referencji */
            Wektor3D& Wez_Polozenie () { return Polozenie; }
            Wektor3D Wez_Polozenie () const { return Polozenie; }
        
        /* Zmiana wartosci pola */
            void Zmien_Polozenie (Wektor3D& NowePolozenie)
                { Polozenie = NowePolozenie; }
            void Zmien_Polozenie ( const Wektor3D NowePolozenie)
                { Polozenie = NowePolozenie; }
    
    /* Skala */

        /* Zmiana wartosci pola */
            void Zmien_Skale (Wektor3D& NowaSkala)
                { Skala = NowaSkala; }
            void Zmien_Skale ( const Wektor3D NowaSkala)
                { Skala = NowaSkala; }
    
    /* Nazwa bryły */

        /* Dostep do zawartosci pola Nazwa_ElementuSkladowego */
            std::string Get_NazwaElementuSkladowego ()
                { return Nazwa_ElementuSkladowego; }
        
    /* Nazwa pliku z bryla wzorcowa */
    
        /* Zmiana wartosci pola */
            void Zmien_NazwaPliku_BrylaWzorcowa ( std::string& NowaNazwa )
                { NazwaPliku_BrylaWzorcowa = NowaNazwa; }
            void Zmien_NazwaPliku_BrylaWzorcowa ( const std::string NowaNazwa )
                { NazwaPliku_BrylaWzorcowa = NowaNazwa; }
        
    /* Nazwa pliku do rysowania przez program */

        /* Zmiana wartosci pola */
            void Zmien_NazwaPliku_PlikDoRysowania ( std::string& NowaNazwa )
                { NazwaPliku_PlikDoRysowania = NowaNazwa; }
            void Zmien_NazwaPliku_PlikDoRysowania ( const std::string NowaNazwa)
                { NazwaPliku_PlikDoRysowania = NowaNazwa; }
        
        /* Uzyskanie dostępu do nazwy pliku do rysowania */
            std::string& Get_NazwaPliku () { return NazwaPliku_PlikDoRysowania; }
            std::string Get_NazwaPliku () const { return NazwaPliku_PlikDoRysowania; }
    
    /* Metody klasy ObiektGeom */

    /*!
        \brief Metoda umożliwiajaca przeliczenie i zapisz wierzchołku dla danego obiektu
        klasy ObiektGeom

        Metoda otwiera:
            #1 Strumien wejścia z pliku z którego wczytywane będą wierzchołki bryły wzorcowej. 
            Nazwa pliku przechowywana jest w polu NazwaPliku_BrylaWzorcowa
            #2 Strumien wyjścia do pliku, do którego będą zapisywane wyliczone współrzędne. Otrzymane
            wartości będą w kolejnym etapie wykorzystywane do rysowania danej bryły przez program GNUplot.
        
        Po otwarciu i sprawdzeniu poprawności przeprowadzonych operacji, uruchamiana jest metoda
        Przelicz_i_Zapisz_Wierzcholki (std::istream Input, std::ostream Output). Jawnymi argumentami
        wywołania są kolejno:
            #1 uchwyt do strumienia wejściowego 
            #2 uchwyt do strumienia wyjściowego
        
        \retval true - poprawne operacje odczytu, zapisu oraz poprawne działanie metody
        Przelicz_i_Zapisz_Wierzcholki (std::istream Input, std::ostream Output)
        \retval false - błąd w działaniu, na którymkolwiek etapie działania programu
    */
    bool Przelicz_i_Zapisz_Wierzcholki ();
    
    /*!
        \brief Metoda przeliczajaca wspolrzedne obiektu klasy ObiektGeom

        Metoda na podstawie:
            #1 Macierzy rotacji przechowywanej w polu MacierzRotacji
            #2 Polozenia przechowywanego w polu Polozenie
            #3 Skali przechowywanej w polu Skala
            #4 Wspolrzednych bryły wzorcowej przechowywanych w pliku o nazwie
            NazwaPliku_BrylaWzorcowa,
        
        pobiera współrzędne bryły wzorcowej ze strumienia wejściowego, wylicza aktualne współrzędne
        a wynik zapisuje do strumienia wyjściowego.

        \arg std::istream& Input - strumień wejściowy, z którego pobierane będą współrzędne bryły wzorcowej
        \arg std::ostream& Output - strumień wyjściowy, do którego zapisywane będą wyliczone wartości współrzędnych
    */
    bool Przelicz_i_Zapisz_Wierzcholki ( std::istream& Input, std::ostream& Output);

    bool Count_and_Save_Cusps ( Macierz3D& RotationMatrix, Wektor3D& Location);

    bool Count_and_Save_Cusps ( Macierz3D& RotationMatrix, Wektor3D& Location,
                                std::istream& Input, std::ostream& Output );
    
};

#endif