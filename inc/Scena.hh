#ifndef SCENA_HH
#define SCENA_HH

#include <list>
#include <memory>

#include "Obiekt.hh"
#include "PowierzchniaMarsa.hh"
#include "lacze_do_gnuplota.hh"

class Scena {

    std::list<std::shared_ptr<Obiekt>> Lista_Obiektow_Na_Scenie;
    PzG::LaczeDoGNUPlota Lacze;

    public:

    /* Interfejs klasy Scena */

    /* Lacze do GNUPlota */
        PzG::LaczeDoGNUPlota& Get_Lacze () { return Lacze; }

    void Inicjalizuj_Lacze();
    bool Dodaj_Do_Listy_Scena (Obiekt& NowyObiekt);

    void Dodaj_Do_ListyRysowania ();

    void Dodaj_Do_Listy_Obiekty ( std::shared_ptr<Obiekt> NowyObiekt );

};

#endif