#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "ObiektGeom.hh"
#include "Obiekt.hh"
#include "PowierzchniaMarsa.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
  Wektor3D Temp (30, 0, 0);
  Wektor3D Skala (10, 10, 10);
  Wektor3D Temp2 (0, 0, 0);
  Macierz3D Macierz;
  ObiektGeom Ob1 ( 3, Temp2, Temp, Skala, "Kostka", "bryly_wzorcowe/szescian1.dat","pliki_do_rysowania/Probka1");
  Obiekt OBB (Temp, Skala, Temp2, "Gender");

  std::shared_ptr<ObiektGeom> Collere = make_shared<ObiektGeom>(Ob1);
  OBB.DodajObiekt(Temp, Temp2, Collere);

  cout << "Lista obiektow skladowych: " << endl;
  cout << OBB.Get_ListaObiektowSkladowych() << endl;

  PzG::LaczeDoGNUPlota Lacze;

  Lacze.Rysuj();
  cout << "Pacnij cos"<< endl;
  int i;
  cin >> i;

  /* __________ Test klasy ObiektGeom.hh _______________ */


}