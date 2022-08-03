#include "Kolo.hh"

bool Kolo::Count_the_Radius()
{
    Wektor3D Temp (0, 0, 0);
    Wektor3D Temp2;

    std::ifstream Input (Get_FileName_Origin());
    
    Input >> Temp;
    Input >> Temp2;

        while ( Temp[1] != Temp2[1] )
            if ( Temp [1] != Temp2 [1]) Input >> Temp2;
               

    if ( Temp[1] == Temp2[1])
        Radius = (Get_Skala())[0] * (Temp.DistanceBetweenTwoPoints(Temp2));
    else
        Radius = 0;
}