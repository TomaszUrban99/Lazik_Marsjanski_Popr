#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include <iostream>
#include "rozmiar.h"
#include "SWektor.hh"
#include <assert.h>
#include <utility>

constexpr double epsilon = 3;

template <typename STyp, typename SPole, uint SWymiar>
class SMacierz
{
    STyp Mx[ROZMIAR];

    public:

    STyp& operator [] (uint row) { return (this)->Mx[row]; }
    STyp operator [] (uint row) const { return (this)->Mx[row];}
    SPole& operator () (uint row, uint col) { return (this)->Mx[row][col];}
    SPole operator () (uint row, uint col) const { return (this)->Mx[row][col];}

    SMacierz<STyp, SPole, SWymiar> ZamianaKol (const uint Kol1, const uint Kol2) const;
    SMacierz<STyp, SPole, SWymiar>& ZamianaKol (const uint Kol1, const uint Kol2);
    SMacierz<STyp, SPole, SWymiar> ZamianaKol (const uint Kol1, const STyp WyrazWolny) const;
    SMacierz<STyp, SPole, SWymiar> ZamianaWier (const uint Wie1, const uint Wie2) const;
    SMacierz<STyp, SPole, SWymiar>& ZamianaWier (const uint Wie1, const uint Wie2);

    SMacierz<STyp, SPole, SWymiar>& Transpose();
    SMacierz<STyp, SPole, SWymiar>& MaxWiersz(const uint Kol, uint& liczba);

    SPole Wyznacznik() const;

    void ZerowanieKol(const uint Kol);

};

template <typename STyp, typename SPole, uint SWymiar>
std::ostream& operator << (std::ostream& output, const SMacierz<STyp, SPole, SWymiar> Macierz)
{
    for(int i=0; i<ROZMIAR; ++i) output<<Macierz[i]<<std::endl; 
    return output;
}

template <typename STyp, typename SPole, uint SWymiar>
std::istream& operator >> (std::istream& input, SMacierz<STyp, SPole, SWymiar>& Macierz)
{
    for(int Ind = 0; Ind < ROZMIAR; ++Ind) input >> Macierz[Ind];
    return input;
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz<STyp, SPole, SWymiar>& SMacierz< STyp, SPole, SWymiar>::Transpose(){ 

  for (uint i = 0; i < ROZMIAR; ++i)
  {
    for ( uint j=i; j< ROZMIAR; ++j)
    {
      std:: swap((*this)(i, j), (*this)(j, i));
    }}

    return (*this);
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz <STyp, SPole, SWymiar>& SMacierz <STyp, SPole, SWymiar>::MaxWiersz(const uint Kol, uint& liczba){
  
  assert(Kol<ROZMIAR); // Sprawdzenie czy indeks mieści się w dopuszczalnym zakresie

  SPole Temp; 
  SPole Temp2;
  uint i=1;

  Temp=modul((*this)(ROZMIAR-i, Kol));
  
  for(; i<(ROZMIAR-Kol); ++i)
  {
    Temp2=modul((*this)(ROZMIAR-(i+1), Kol));
    if(Temp2<Temp)
    {
      this->ZamianaWier(ROZMIAR-i, ROZMIAR-(i+1));
      liczba++;
    }
    else Temp=Temp2;
  }

  return *this;
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz <STyp, SPole, SWymiar>& SMacierz <STyp, SPole, SWymiar>::ZamianaWier(const uint Wie1, const uint Wie2)
{
  assert(Wie1<ROZMIAR && Wie2<ROZMIAR);
  
  std::swap((*this)[Wie1], (*this)[Wie2]);
  
  return *this;
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz <STyp, SPole, SWymiar> SMacierz <STyp, SPole, SWymiar>::ZamianaWier(const uint Wie1, const uint Wie2) const
{
  SMacierz <STyp, SPole, SWymiar> Pom=*this;

  assert(Wie1<ROZMIAR && Wie2<ROZMIAR);

  std::swap(Pom[Wie1], Pom[Wie2]);

  return Pom;
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz <STyp, SPole, SWymiar> SMacierz <STyp, SPole, SWymiar>::ZamianaKol(const uint Kol1, const uint Kol2) const
{
  assert(Kol1<ROZMIAR && Kol2<ROZMIAR);
  SMacierz <STyp, SPole, SWymiar> M3=*this; 

  for (uint i=0; i<ROZMIAR; ++i) std::swap(M3(i, Kol1), M3(i, Kol2));

  return M3;
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz <STyp, SPole, SWymiar>& SMacierz <STyp, SPole, SWymiar>::ZamianaKol(const uint Kol1, const uint Kol2)
{
  assert(Kol1<ROZMIAR && Kol2<ROZMIAR);
  
  for (uint i=0; i<ROZMIAR; ++i) std::swap((*this)(i, Kol1), (*this)(i, Kol2));
  
  return (*this);
}

template <typename STyp, typename SPole, uint SWymiar>
SMacierz <STyp, SPole, SWymiar> SMacierz <STyp, SPole, SWymiar>::ZamianaKol(const uint Kol1, const STyp WyrazWolny) const
{
  SMacierz <STyp, SPole, SWymiar> M3=*this;

  assert(Kol1<ROZMIAR);

  for (uint i=0; i<ROZMIAR; ++i) M3(i, Kol1)=WyrazWolny[i];

  return M3;
}

template <typename STyp, typename SPole, uint SWymiar>
void SMacierz <STyp, SPole, SWymiar>::ZerowanieKol(const uint Kol){

assert(Kol<(ROZMIAR-1));

   SPole Wsp;

   for(uint i=Kol; (i+1)<ROZMIAR; ++i)
   {
     Wsp=(*this)(i+1, Kol)/((*this)(Kol, Kol));
     std :: cout << "Wspolczynnik do zerowania: " << Wsp << std::endl;
     (*this)[i+1]=(*this)[i+1]-(((*this)[Kol])*Wsp);
   }
 }

/* Zrobić dwie wersje metod- jedna dla wyznacznika dla przypadku liczb zespolonych,
drugą wersję dla liczb rzeczywistych 
Dodatkowo napisać metodę liczącą moduł liczby rzeczywistej*/

template <typename STyp, typename SPole, uint SWymiar>
SPole SMacierz <STyp, SPole, SWymiar>::Wyznacznik() const
{ 
  SMacierz <STyp, SPole, SWymiar> M3=*this;
  SPole Wyznacznik;
  Wyznacznik=1;
  uint liczba=0;

  std::cout << "Macierz: " << M3 << std::endl;

  for(uint i=0; (i+1)<ROZMIAR; ++i){
    M3.MaxWiersz(i, liczba);
    if (M3(i, i)==0)
    {
      Wyznacznik=0;
      return Wyznacznik;
    }
    M3.ZerowanieKol(i);
    std::cout << "Macierz po zerowaniu kolumn: " << M3 << std::endl; 
  }

  for(uint i=0; i<ROZMIAR; ++i) Wyznacznik=Wyznacznik*M3(i,i);
  if(liczba%2!=0) Wyznacznik=Wyznacznik*(-1);
  
  if (Wyznacznik-epsilon<0 && Wyznacznik+epsilon>0)
  {
    Wyznacznik=0;
    return Wyznacznik;
  }

  return Wyznacznik;
}

#endif