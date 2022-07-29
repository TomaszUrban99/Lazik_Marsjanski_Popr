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
std::string Obiekt::_TempFileCusps = "pliki_do_rysowania/Temp.dat";

int main()
{
  /* Zmienne do zapisywania ścieżek plikow z bryłami wzorcowymi */
    const std::string Graniastotlup = "bryly_wzorcowe/graniastoslup6-OY.dat";
    const std::string Szescian1 = "bryly_wzorcowe/szescian1.dat";

    char Command [2] = "p";

  Wektor3D Temp (30, 0, 0);
  Wektor3D Skala (10, 10, 10);
  Wektor3D Skala2 (10, 10, 10);
  Wektor3D Skala3 (30, 10, 10);
  Wektor3D Temp2 (0, 0, 0);
  Wektor3D Temp3 (50, 0, 0);
  Wektor3D Temp4 (20, 20, 0);
  Wektor3D Temp5 (50, 20, 0);
  Wektor3D Temp6 (30, 50, 5);
  Wektor3D KatOkr (0, 0, 0);
  Wektor3D Temp7 (30, 30, 5);

  /* Wektory do opisu wzglednych polozen */
      Wektor3D KoloPrawePrzednie ( 10, 10, 0);
      Wektor3D KoloLewePrzednie ( 10, -10, 0);
      Wektor3D KoloPraweTylne (-10, 10, 0);
      Wektor3D KoloLeweTylne (-10, -10, 0);
      Wektor3D KadlubPol (0, 0, 0);
      Wektor3D KatOkr2 (20, 50, 0);

  /* Zadeklarowanie obiektow */
    /* Lazik 1 */
      Lazik Trysil (Temp7, Skala, Temp, "Trysil");
        /* Kola */
          Kolo KoloPP ( 8, Temp2, Temp, Skala, "L1/PP", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloPP.dat");
                Trysil.DodajObiekt ( KoloPrawePrzednie, KatOkr, KoloPP);
          Kolo KoloPL ( 8, Temp2, Temp, Skala, "L1/PL", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloPL.dat");
                Trysil.DodajObiekt ( KoloLewePrzednie, KatOkr, KoloPL);
          Kolo KoloTP ( 8, Temp2, Temp, Skala, "L1/TP", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloTP.dat");
                Trysil.DodajObiekt ( KoloPraweTylne, KatOkr, KoloTP);
          Kolo KoloTL ( 8, Temp2, Temp, Skala, "L1/TL", Graniastotlup, "pliki_do_rysowania/Lazik1/KoloTL.dat");
                Trysil.DodajObiekt ( KoloLeweTylne, KatOkr, KoloTL);
        /* Kadlub */
          Kadlub Kadlub2 ( 3, Temp2, Temp, Skala3, "L1/Kadlub", Szescian1, "pliki_do_rysowania/Lazik1/Kadlub.dat");
                Trysil.DodajObiekt ( KadlubPol, KadlubPol, Kadlub2);
  Scena Mars;

  Trysil.Count_and_Save_Cusps();

  Mars.Inicjalizuj_Lacze();
  Dodaj_Do_ListyRysowania(Mars.Get_Lacze());
  Mars.Dodaj_Do_Listy_Scena(Trysil);
  Mars.Dodaj_Do_ListyRysowania();

  Mars.Change_ActiveLazik(1);

  cout << "Nazwa aktywnego lazika: " << endl;
  cout << Mars.Get_ActiveLazik()->Get_NazwaObiektu() << endl;

  Mars.Get_Lacze().Rysuj();
  cout << "Podaj odleglosc na jaka ma sie przemiescic lazik: "<< endl;
  double i;
  cin >> i;

  Mars.Get_Lacze().Rysuj();

  cout << "Pacnij!!!" << endl;
  cin >> i;

  while (Command[0] != 'e')
  {
    switch (Command[0])
    {
      case 'f' :
      {
        cout << "Podaj odleglosc do przejechania " << endl;
        cin >> i;

        Mars.Get_ActiveLazik()->Zmien_OdlegloscDoPrzejechania(i);
        Mars.Get_ActiveLazik()->TranslacjLazika();
        Mars.Get_Lacze().Rysuj();
      }
      break;
    }

    cout << "What do you want to do?" << endl;
    cout << "f - translate Lazik" << endl;
    cin >> Command [0];
  }




  /* __________ Test klasy ObiektGeom.hh _______________ */


}