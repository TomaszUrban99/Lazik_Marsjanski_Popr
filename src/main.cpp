#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
  Wektor3D Temp (30, 0, 0);
  Macierz3D Macierz;

  cout << "Macierz rotacji: " << endl;
  Macierz.MacierzRotacji(Temp);
  cout << Macierz << endl;


  /* __________ Test klasy ObiektGeom.hh _______________ */


}