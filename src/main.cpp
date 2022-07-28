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
#include "Kolo.hh"
#include "Kadlub.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
  /* Zmienne do zapisywania ścieżek plikow z bryłami wzorcowymi */
    const std::string Graniastotlup = "bryly_wzorcowe/graniastoslup6-OY.dat";
    const std::string Szescian1 = "bryly_wzorcowe/szescian1.dat";

  Wektor3D Temp (30, 0, 0);
  Wektor3D Skala (10, 10, 10);
  Wektor3D Skala2 (10, 10, 10);
  Wektor3D Temp2 (0, 0, 0);
  Wektor3D Temp3 (50, 0, 0);
  Wektor3D Temp4 (20, 20, 0);
  Wektor3D Temp5 (50, 20, 0);
  Wektor3D Temp6 (30, 50, 5);
  Wektor3D KatOkr (0, 0, 0);

  /* Zadeklarowanie obiektow */
    /* Lazik 1 */
      /* Kola */
        Kolo KoloPP ( 8, Temp2, Temp, Skala, "L1/PP", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloPP.dat");
        Kolo KoloPL ( 8, Temp2, Temp, Skala, "L1/PL", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloPL.dat");
        Kolo KoloTP ( 8, Temp2, Temp, Skala, "L1/TP", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloTP.dat");
        Kolo KoloTL ( 8, Temp2, Temp, Skala, "L1/TL", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloTL.dat");
      /* Kadlub */
        Kadlub Kadlub2 ( 3, Temp2, Temp, Skala, "L1/Kadlub", Szescian1, "pliki_do_rysowania/Lazik1/Kadlub.dat");
      
  Kadlub Ob1 ( 3, Temp2, Temp, Skala, "Kostka", "bryly_wzorcowe/szescian1.dat","pliki_do_rysowania/Probka1");
  Kadlub Ob2 ( 8, Temp3, Temp4, Skala, "Kosteczka", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka2");
  Kadlub Ob3 ( 2, Temp, Temp6, Skala, "Autobusik", "bryly_wzorcowe/szescian2.dat", "pliki_do_rysowania/Probka4");
  Kadlub Ob4 ( 3, Temp2, Temp, Skala, "Collere", "bryly_wzorcowe/szescian2.dat", "pliki_do_rysowania/Probka5");
  Kolo Ob5 ( 6, KatOkr, Temp5, Skala2, "Kolo", "bryly_wzorcowe/graniastoslup6-OY.dat", "pliki_do_rysowania/Probka6.dat");
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
  OBB2.DodajObiekt(Temp6, Temp2, Ob5);

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
  cout << Mars.Get_Lista().back()->Get_ListaObiektowSkladowych().back()->Get_NazwaPliku() << std::endl;

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