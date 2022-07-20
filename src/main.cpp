#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "ObiektGeom.hh"
#include "Obiekt.hh"
#include "PowierzchniaMarsa.hh"
#include "lacze_do_gnuplota.hh"
#include "Scena.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
  Wektor3D Temp (30, 0, 0);
  Wektor3D Skala (10, 10, 10);
  Wektor3D Temp2 (0, 0, 0);
  Wektor3D Temp3 (100, 0, 0);
  Wektor3D Temp4 (40, 0, 0);
  Macierz3D Macierz;
  ObiektGeom Ob1 ( 3, Temp2, Temp, Skala, "Kostka", "bryly_wzorcowe/szescian1.dat","pliki_do_rysowania/Probka1");
  ObiektGeom Ob2 ( 8, Temp3, Temp4, Skala, "Kosteczka", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka2");
  Obiekt OBB (Temp, Skala, Temp2, "Gender");
  Scena Mars;

  cout << "Polozenie obiektow: " << endl;
  cout << Ob1.Wez_Polozenie() << endl;
  cout << Ob2.Wez_Polozenie() << endl;

  cout << "Polozenie glownego obiektu: " << endl;
  cout << OBB.Get_Polozenie() << endl;

  

  cout << "Lista obiektow skladowych: " << endl;
  cout << OBB.Get_ListaObiektowSkladowych() << endl;
  OBB.DodajObiekt(Temp, Temp2, Ob1);
  OBB.DodajObiekt(Temp2, Temp4, Ob2);
  
  /*Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Ob2.Przelicz_i_Zapisz_Wierzcholki();*/

  OBB.Przelicz_I_Zapisz_Wierzcholki();

  std::cout << "Polozenia obiektow: " << std::endl;
  cout << Ob1.Wez_Polozenie() << endl;
  cout << Ob2.Wez_Polozenie() << endl;

  cout << "Lista obiektow skladowych: " << endl;
  cout << OBB.Get_ListaObiektowSkladowych() << endl;

  Mars.Inicjalizuj_Lacze();
  Dodaj_Do_ListyRysowania(Mars.Get_Lacze());
  Mars.Dodaj_Do_Listy_Scena(OBB);
  Mars.Dodaj_Do_ListyRysowania();
  cout << "Mars" << std::endl;
  
  

  Mars.Get_Lacze().Rysuj();
  cout << "Pacnij cos"<< endl;
  int i;
  cin >> i;

  /* __________ Test klasy ObiektGeom.hh _______________ */


}