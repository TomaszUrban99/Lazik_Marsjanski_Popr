#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "Kolory.hh"
#include "Wektor3D.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  Wektor3D PolozenieFSR (0, 0, 0);
  Wektor3D PolozeniePerservance (22, 30, 0);
  Wektor3D PolozenieCuriosity (50, 50, 0);
  Wektor3D Skala (20, 20, 10);
  Wektor3D SkalaProbka (5, 5, 2);
  Wektor3D PolozenieProbka1 (-20, -20, 0);
  Wektor3D PolozenieProbka2 (-25, -30, 0);

  char klawisz[2] = "m";
}