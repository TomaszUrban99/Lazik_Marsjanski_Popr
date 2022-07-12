#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "SWektor.hh"
#include "rozmiar.h"
#include "OperacjeMat.hh"

constexpr int ZERO = 0;
constexpr int ONE = 1;
constexpr int TWO = 2;

/*!
    \brief Klasa modelująca pojęcie trójwymiarowego wektora.

    Klasa Wektor3D jest klasą pochodną klasy powstałej z szablonu SWektor zdefiniowanego
    w pliku nagłówkowym SWektor.hh.

    Atrybuty klasy Wektor3D:

    #1 tablica wartości typu double o rozmiarze równym stałej ROZMIAR z pliku
    nagłówkowego "rozmiar.h"

    #2 static int Count - zmienna statyczna przechowująca liczbę powstałych 
    obiektów klasy Wektor3D

    #3 static int CurrentCount - zmienna statyczna przechowująca liczbę aktualnie istniejących
    obiektów klasy Wektor3D

*/
class Wektor3D : public SWektor<double, ROZMIAR> {

    static int Count;
    static int Current_Count;

    public:
    
    /*!
        \brief Bezparametryczny konstruktor klasy Wektor3D.

        Podczas tworzenia klasy zwiększana o jeden jest wartość zmiennych
        Count oraz Current_Count przechowujących odpowiednio liczbę powstałych obiektów
        oraz liczbę aktualnie istniejących obiektów.
    */
    Wektor3D()
    {
        ++Count;
        ++Current_Count;
    }

    /*!
        \brief Konstruktor kopiowania dla obiektów klasy Wektor3D.
        Podczas wywołania zwiększana jest o jeden wartość atrybutów Cout i Current_Count.
        \param Wektor3D& - referencja do obiektu klasy 3D, który kopiowany
        jest do obiektu, dla którego metoda została wywołana.
    */
    Wektor3D(Wektor3D&)
    {
        ++Count;
        ++Current_Count;
    }

    /*! 
        \brief Konstruktor parametryczny obiektu klasy Wektor3D
        \param double X, Y, Z - początkowe współrzędne obiektu
    */
    Wektor3D (double X, double Y, double Z)
    {
        (*this)[ZERO] = X;
        (*this)[ONE] = Y;
        (*this)[TWO] = Z;

        ++Count;
        ++Current_Count;
    }

    Wektor3D(const Wektor3D&)
    {
        ++Count;
        ++Current_Count;
    }

    /*!
        \brief Destruktor klasy Wektor3D.

        Podczas niszczenia obiektu klasy Wektor3D, destruktor zmniejsza o jeden
        wartość zmiennej statycznej Current_Count przechowującej liczbę aktualnie
        istniejących obiektów klasy Wektor3D.
    */
    ~Wektor3D(){--Current_Count;}

    /*!
        \brief Metoda zwracająca liczbę powstałych obiektów klasy Wektor3D.
        \retval int Count - wartość typu int przechowująca liczbę powstałych obiektów klasy
        Wektor3D.
    */
    int getCount() const {return Count;}

    /*!
        \brief Metoda zwracająca liczbę aktualnie istniejących obiektów klasy Wektor3D.
        \retval int Current_Count - wartość typu int przechowująca liczbę aktualnie
        istniejących obiektów klasy Wektor3D.
    */
    int getCurrentCount() const {return Current_Count;}

    /*!
        \brief Przeciążenie operatora mnożenia typu element to element.
        
        Operacja mnożenia tego typu polega na pomnożeniu przez siebie elementów
        przechowywanych na odpowiednich miejscach. Metoda nie modyfikuje parametrów
        wywołania.
        
        \param Wektor3D Wektor2 - kopia obiektu, przez który mnożony 
        będzie obiekt klasy Wektor3D, dla którego metoda została wywołana.

        \retval Obiekt klasy Wektor3D będący wynikiem mnożenia element to element
        dwóch wektorów będących parametrami wywołania metody.
    */
    Wektor3D operator*(Wektor3D& Wektor2) const;

    void operator=(SWektor<double, ROZMIAR> Wektor2){
        for(int i = 0; i < ROZMIAR; ++i) (*this)[i] = Wektor2[i];}
    
    /* Metody klasy Wektor3D */

    /*!
        \brief Metoda zamieniająca poszczególne pola obiektu klasy Wektor3D, zawierające
        wyrażone w stopniach kąty.

        Metoda umożliwia zamianę wartości kątów wyrażonych w stopniach na radiany. Działanie
        opiera się na wykorzystaniu funkcji StopnieNaRadiany zadeklarowanej w pliku nagłówkowym
        OperacjeMat.hh.

        KonwersjaNaRadiany nie modyfikuje obiektu, dla której została wywołana.

        \retval Wektor3D Temp - obiekt klasy Wektor3D przechowujący wartości kątów z obiektu, dla którego
        metoda została wywołana, wyrażone w radianach.
    */
    Wektor3D KonwersjaNaRadiany() const;
    
    /*!
        \brief Metoda wyznaczająca cosinusy kątów przechowywanych w obiekcie, dla którego metoda
        została wywołana.

        Działanie metody opiera się na wykorzystaniu funkcji cos() zdefiniowanej w biliotece math.h.
        Z kolejnych wartości kątów przechowywanych w obiekcie, dla którego metoda została wywołana
        wyznaczane są wartości cosinusów przy użyciu funkcji cos().

        Warunkiem poprawnego działania metody jest wyrażenie wejściowych kątów w RADIANACH.

        Obiekt wejściowy nie jest modyfikowany.

        \retval Wektor3D Temp - wektor zawierający cosinusy kątów z pól o odpowiadających sobie
        indeksach pól
    */
    Wektor3D Cosinus() const;
    
    /*!
        \brief Metoda wyznaczająca sinusy kątów przechowywanych w obiekcie, dla którego metoda
        została wywołana.

        Działanie metody opiera się na wykorzystaniu funkcji sin() zdefiniowanej w biliotece math.h.
        Z kolejnych wartości kątów przechowywanych w obiekcie, dla którego metoda została wywołana
        wyznaczane są wartości cosinusów przy użyciu funkcji sin().

        Warunkiem poprawnego działania metody jest wyrażenie wejściowych kątów w RADIANACH.

        Obiekt wejściowy nie jest modyfikowany.

        \retval Wektor3D Temp - wektor zawierający sinusy kątów z pól o odpowiadających sobie indeksach
        pól.
    */
    Wektor3D Sinus () const;

};

#endif