#include "Macierz.hh"
using namespace std;
#include "Wektor.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


 //MODYFIKACJA

const Macierz Macierz::operator * () const
{
    Macierz Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        Wynik._SkladnikiM[i][j]=this->_SkladnikiM[i][j]*this->_SkladnikiM[i][j];
    }
    return Wynik;
}


Macierz::Macierz()
{
    Wektor W;
    for(int i = 0; i < ROZMIAR; i++)
    {
        this->_SkladnikiM[i] = W;
        this->_SkladnikiM[i][i] = 1;
    }
}


Macierz Macierz::operator + (const Macierz & M) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->_SkladnikiM[i] + M[i];
    }
    return Wynik;
}

Macierz Macierz::operator - (const Macierz & M) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->_SkladnikiM[i] - M[i];
    }
    return Wynik;
}

Macierz Macierz::operator* (const double l) const
{
    Macierz Wynik;
    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = this->_SkladnikiM[i] * l;
    }
    return Wynik;
}


Wektor Macierz::operator* (const Wektor W) const
{
    Wektor Wynik;
    double tmp = 0;

    for(int i = 0; i < ROZMIAR; i++)
    {
        tmp += this->_SkladnikiM[i] * W;
        Wynik[i] = tmp;
        tmp = 0;
    }

    return Wynik;
}


 const double Macierz::Wyznacznik() const
{
    Macierz M = *this;
    double Wynik = M[0][0];

    for(int i = 0; i < ROZMIAR - 1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            M[i+j+1] = (M[i+j+1]-(M[i] * ( M[i+j+1][i] / M[i][i] )));
        }
    }

    for(int i = 1; i < ROZMIAR; i++) { Wynik = Wynik*M[i][i]; }

    return Wynik;
}


const Macierz Macierz::MacierzOdwrotna() const
{
    Macierz M = *this;
    Macierz Wynik;
    double liczba;
    for(int i = 0; i < ROZMIAR-1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            liczba = ( M[i+j+1][i] / M[i][i] );
            M[i+j+1] = M[i+j+1] - M[i] * liczba;
            Wynik[i+j+1] = Wynik[i+j+1] - Wynik[i] * liczba;
        }
    }

    for(int i = 0; i < ROZMIAR-1; i++)
    {
        for(int j = 0; j < ROZMIAR - (i+1); j++)
        {
            liczba = ( M[(ROZMIAR-1)-(i+j+1)][(ROZMIAR-1)-i] / M[(ROZMIAR-1)-i][(ROZMIAR-1)-i] );

            M[ROZMIAR-i-j-2] = M[ROZMIAR-i-j-2] - M[ROZMIAR-i-1] * liczba;
            Wynik[ROZMIAR-i-j-2] = Wynik[ROZMIAR-i-j-2] - Wynik[ROZMIAR-i-1] * liczba;
        }
    }

    for(int i = 0; i < ROZMIAR; i++)
    {
        Wynik[i] = Wynik[i]/M[i][i];
    }

    return Wynik;
}




 std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm << Mac[i] << "\n";
    }
    return Strm;
}


