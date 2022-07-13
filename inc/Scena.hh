#ifndef SCENA_HH
#define SCENA_HH

#include <list>
#include <memory>
#include "Obiekt.hh"
#include "lacze_do_gnuplota.hh"

class Scena {

    std::list<std::shared_ptr<Obiekt>> Lista_Obiektow_Na_Scenie;
    PzG::LaczeDoGNUPlota Lacze;

    public:

};

#endif