#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "ProbkaRegolitu.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "LazikSFR.hh"
#include "Wektor3D.hh"
#include "Scena.hh"

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
  std::list<std::shared_ptr<ProbkaRegolitu>> TempProbka;
  std::shared_ptr<Lazik> TempProbka2;
  std::shared_ptr<LazikSFR> LazikTemp;

  char klawisz[2] = "m";

  LazikSFR Ob1(Random, 0, PolozenieFSR, Skala, "FSR", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/FSR");
  Lazik Ob2(Kolor_JasnoNiebieski, 0, PolozenieCuriosity, Skala, "Curiosity", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Curiosity");
  Lazik Ob3(Kolor_JasnoNiebieski, 0, PolozeniePerservance, Skala, "Perservarance", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Perservarance");
  ProbkaRegolitu Ob4 (Kolor_Czerwony, 0, PolozenieProbka1, SkalaProbka, "Probka1", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka1");
  ProbkaRegolitu Ob5 (Kolor_Czerwony, 0, PolozenieProbka2, SkalaProbka, "Probka2", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka2");

  Scena Mars(Ob1);

  Mars.DodajDoListyObiektow(Ob1);
  Mars.DodajDoListyObiektow(Ob2);
  Mars.DodajDoListyObiektow(Ob3);
  Mars.DodajDoListyObiektow(Ob4);
  Mars.DodajDoListyObiektow(Ob5);
  
  Mars.Inicjalizuj_Lacze();
  if (!Inicjalizuj_PowierzchnieMarsa(Mars.Wez_Lacze())) return 1;

  Mars.DodajDoListyRysowania();
  Mars.Zmien_AktywnyLazik(0);

  list<shared_ptr<ObiektGeom>>::iterator Iter = Mars.Wez_Liste().begin();

  while (Iter != Mars.Wez_Liste().end())
  {
    (**Iter).Przelicz_i_Zapisz_Wierzcholki();
    (**Iter).WyznaczObrysObiektu();
    if((*Iter)->Obiekt_ID() == ID_Lazik ) cout << "Lazik: " << (**Iter) << endl;
    ++Iter;
  }

  cout << endl << "Start programu gnuplot" << endl << endl;
  (Mars.Wez_Lacze()).Rysuj();

  cout << "Nacisnij klawisz ENTER, aby przejsc dalej" << endl;
  cin.ignore(100,'\n');

  while((klawisz[0])!='k')
  {
    double Temp;

    switch(klawisz[0])
    {
      case 'j':
        
        cout << "Aktywny lazik: " << endl;
        cout << *(Mars.Wez_AktywnyLazik()) << endl;
        cout << "Podaj odleglosc" << endl;
        cin >> Temp;
        (*(Mars.Wez_AktywnyLazik())).Zmien_OdlegloscDoPrzejechania(Temp);
        cout << "Podaj szybkosc" << endl;
        cin >> Temp;
        (Mars.Wez_AktywnyLazik())->Zmien_Szybkosc(Temp);
        if(!Mars.AnimacjaTranslacji()) 
        { if(Mars.Wez_AktywnyLazik()->Wez_StanKolizji() == TK_PrzejazdNadProbka)
              cout << "Czy podniesc probke? (Jeśli tak wciśnij klawisz 'r')" << endl;
          else
            cout << "Kolizja!!! Ruch zatrzymany" << std::endl;
        }
      
        cout << "Nacisnij klawisz ENTER, aby przejść dalej." << endl;
        cin.ignore(100,'\n');
      
      break;

      case 'o':

        double Temp2;

        cout << "Podaj kat obrotu" << endl;
        cin >> Temp;
        cout << "Podaj predkosc obrotu" << endl;
        cin >> Temp2;
        if(!(Mars.AnimacjaObrotu(Temp, Temp2)))
        { if(Mars.Wez_AktywnyLazik()->Wez_StanKolizji() == TK_PrzejazdNadProbka)
              cout << "Czy podniesc probke? (Jeśli tak wciśnij klawisz 'r')" << endl;
          else
            cout << "Kolizja!!! Ruch zatrzymany" << std::endl;
        }
        cout << "Nacisnij klawisz ENTER, aby przejść dalej." << endl;
        cin.ignore(100,'\n');
      
      break;

      case 'm':

        cout << "Menu programu lazik marsjanski" << endl;
        cout << "j - jazda na wprost" << endl;
        cout << "o - obrot lazika" << endl;
        cout << "d - wyswietl aktywny lazik" << endl;
        cout << "s - selekcja lazika" << endl;
        cout << "k - koniec programu" << endl;
        cout << "l - wyswietl liste probek na scenie" << endl;
      
      break;

      case 'd':
          cout << *(Mars.Wez_AktywnyLazik()) << endl;
      break;

      case 's':

        int Numer;
        cout << "Podaj numer lazika, ktory chcesz wybrac" << endl;
        cin >> Numer;
        Mars.Zmien_AktywnyLazik(Numer);
      
      break;

      case 'l':

      TempProbka = Mars.Wyswietl_Laziki();
      cout << TempProbka << std::endl;

      break;

      case 'r':
        
        cout << Mars.Wez_AktywnyLazik()->Obiekt_ID() << endl;
        if (Mars.Wez_AktywnyLazik()->Obiekt_ID() == ID_Lazik)
        {
          Mars.Wez_AktywnyLazik()->PodejmijProbke();
          Mars.UsunProbke(Mars.Wez_AktywnyLazik()->Wez_ListeProbek().back());
        }
        else cout << "To nie jest łazik do zbierania probek" << endl;

      break;

      case 't':

        if (Mars.Wez_AktywnyLazik()->Obiekt_ID() == ID_Lazik)
        {
          cout << "Lista próbek łazika: " << endl;
          cout << Mars.Wez_AktywnyLazik()->Wez_ListeProbek() << endl;
        }
      
      break;

      default :

        cout << "Nierozpoznana komenda" << endl;
      
      break;
    }

    cout << "Wektory PODSUMOWANIE:" << endl;
    cout << "Ogółem: " << PolozenieFSR.getCount() << endl;
    cout << "Aktualnie: " << PolozenieFSR.getCurrentCount() << endl;

    cout << "Podaj komende (m - wyswietl menu) " << endl;
    cin >> klawisz;

    
  }

  return 0;
}
