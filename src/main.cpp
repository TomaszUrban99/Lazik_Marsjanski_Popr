#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "ObiektGeom.hh"
#include "Obiekt.hh"
#include "Lazik.hh"
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
  Wektor3D Temp3 (50, 0, 0);
  Wektor3D Temp4 (20, 20, 0);
  Wektor3D Temp5 (50, 20, 0);
  Wektor3D Temp6 (30, 50, 0);
  Macierz3D Macierz;
  ObiektGeom Ob1 ( 3, Temp2, Temp, Skala, "Kostka", "bryly_wzorcowe/szescian1.dat","pliki_do_rysowania/Probka1");
  ObiektGeom Ob2 ( 8, Temp3, Temp4, Skala, "Kosteczka", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka2");
  ObiektGeom Ob3 ( 2, Temp, Temp6, Skala, "Autobusik", "bryly_wzorcowe/szescian2.dat", "pliki_do_rysowania/Probka4");
  ObiektGeom Ob4 ( 3, Temp2, Temp, Skala, "Collere", "bryly_wzorcowe/szescian2.dat", "pliki_do_rysowania/Probka5");
  Obiekt OBB (Temp, Skala, Temp2, "Gender");
  Lazik OBB2 (Temp4, Skala, Temp, "Trysil");
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
  OBB2.DodajObiekt(Temp3, Temp4, Ob3);
  OBB2.DodajObiekt(Temp5, Temp, Ob4);

  OBB.Przelicz_I_Zapisz_Wierzcholki();
  OBB2.Przelicz_I_Zapisz_Wierzcholki();

  Mars.Inicjalizuj_Lacze();
  Dodaj_Do_ListyRysowania(Mars.Get_Lacze());
  Mars.Dodaj_Do_Listy_Scena(OBB);
  Mars.Dodaj_Do_Listy_Scena(OBB2);
  Mars.Dodaj_Do_ListyRysowania();
  cout << "Mars" << std::endl;

  cout << "Lista obiektow na scenie: " << std::endl;
  cout << Mars.Get_Lista() << std::endl;

  cout << "Lista obiektow dla tego drugiego: " << std::endl;
  cout << Mars.Get_Lista().back()->Get_ListaObiektowSkladowych().front()->Get_NazwaPliku() << std::endl;

  Mars.Get_Lacze().Rysuj();
  cout << "Podaj odleglosc na jaka ma sie przemiescic lazik: "<< endl;
  double i;
  cin >> i;

  OBB2.Zmien_OdlegloscDoPrzejechania(i);
  OBB2.TranslacjLazika();

  Mars.Get_Lacze().Rysuj();

  cout << "Pacnij!!!" << endl;
  cin >> i;



  /* __________ Test klasy ObiektGeom.hh _______________ */


}