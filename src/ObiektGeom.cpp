#include "ObiektGeom.hh"

bool ObiektGeom::WyznaczObrysObiektu()
{
    Wektor3D WspTymcz;
    Wektor2D WspTymcz2;
    
    std::ifstream Input(this->Wez_NazwaPlikDoRysowania());

    Input >> WspTymcz;

    WspTymcz2 = this->KonwersjaNaDwuwymiarowy(WspTymcz);

    this->Obrys.Zmien_Wierz_DolnyLewy(WspTymcz2);
    this->Obrys.Zmien_Wierz_GornyPrawy(WspTymcz2);
    
    do
    {
        this->Znajdz_DolnyLewy(WspTymcz);
        this->Znajdz_GornyPrawy(WspTymcz);
        
        Input >> WspTymcz;

    } while (!Input.fail());
    
    if(!Input.eof()) return false;

    return true;
}

void ObiektGeom::Znajdz_GornyPrawy(Wektor3D& WektorWspolrzednych)
{
    if(WektorWspolrzednych[0] > ((this->Obrys.Wez_Wierz_GornyPrawy())[0]))
        {(this->Obrys.Wez_Wierz_GornyPrawy()[0]) = WektorWspolrzednych[0];}
    
    if (WektorWspolrzednych[1] > ((this->Obrys.Wez_Wierz_GornyPrawy())[1]))
        {(this->Obrys.Wez_Wierz_GornyPrawy()[1]) = WektorWspolrzednych[1];}
}

void ObiektGeom::Znajdz_DolnyLewy(Wektor3D& WektorWspolrzednych)
{

    if(WektorWspolrzednych[0] < ((this->Obrys.Wez_Wierz_DolnyLewy())[0]))
        {(this->Obrys.Wez_Wierz_DolnyLewy())[0] = WektorWspolrzednych[0];}
    
    if(WektorWspolrzednych[1] < (this->Obrys.Wez_Wierz_DolnyLewy()[1]))
        {(this->Obrys.Wez_Wierz_DolnyLewy())[1] = WektorWspolrzednych[1];}

}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
    std::ifstream Input((*this).NazwaPliku_BrylaWzorcowa);
    if(Input.fail()){ return false; }

    std::ofstream Output((*this).NazwaPliku_PlikDoRysowania);
    if(Output.fail()){return false;}

    if(!Przelicz_i_Zapisz_Wierzcholki(Input, Output)) return false;

    return true;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::istream& Input, std::ostream& Output)
{
    int IndeksWiersza = ZERO;
    Wektor3D WspWierz;

    do 
    {
        Input>>WspWierz;
        if(!Input.fail())
        {
            WspWierz = (this->MacierzRotacji)*((this->Skala)*WspWierz) +(this->Polozenie);

            if (IndeksWiersza==ZERO){
                Obrys.Wez_Wierz_DolnyLewy() = KonwersjaNaDwuwymiarowy(WspWierz);
                Obrys.Wez_Wierz_GornyPrawy() = KonwersjaNaDwuwymiarowy(WspWierz);
            }
            else
            {
                this->Znajdz_DolnyLewy(WspWierz);
                this->Znajdz_GornyPrawy(WspWierz);
            }
            
            Output << WspWierz << std::endl;
            if(Output.fail()) {return false;}
            
            ++IndeksWiersza;
            if (IndeksWiersza%4 == 0){ Output << std::endl;}
        }
        
    }while(!Input.fail());

    if(!Input.eof()){return false;}
     
    return true;
}

bool ObiektGeom::WyliczSzerokosc_Obiektu()
{
    Wektor3D Temp1;
    Wektor3D Temp2;
    int i = 0;
    
    std::ifstream Input (NazwaPliku_BrylaWzorcowa);
    
    do
    {
        if(!(Input >> Temp1)) return false;
        std::cout << "Pierwszy pobrany: " << Temp1 << std::endl;
        if(!(Input >> Temp2)) return false;
        std::cout << "Drugi pobrany: " << Temp1 << std::endl;

        if (Temp1[2]!=Temp2[2])
            if(!(Input >> Temp2)) return false;

        ++i;

    } while (i<4 && Temp1[2]!=Temp2[2]);

    /*if (Temp1[2] != Temp2[2]) return false;*/

    std::cout << "Skala obiektu: " << Skala[1] << std::endl;

    SzerokoscObiektu = (Skala[1] * fabs (Temp1[1] - Temp2[1]));

    std::cout << "Sz: " << SzerokoscObiektu << std::endl;

    return true;
}

Wektor2D ObiektGeom::KonwersjaNaDwuwymiarowy(Wektor3D& Wektor2) const
{
    Wektor2D NowyWektor;
    for (uint i = 0; i < 2; ++i) {NowyWektor[i] = Wektor2[i];}

    return NowyWektor;
}

std::ostream& operator<<(std::ostream& Output, ObiektGeom& DanyLazik)
{
    Output << "Nazwa Lazika: " << DanyLazik.Wez_NazwaObiektu() << std::endl;
    Output << "Polozenie lazika: " << DanyLazik.Wez_Polozenie() << std::endl;
    Output << "Kat orientacji lazika [st]: " << DanyLazik.Wez_KatOrientacjiSt() << std::endl;

    return Output;
}