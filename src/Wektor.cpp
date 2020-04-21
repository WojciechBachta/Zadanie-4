#include "Wektor.hh"
#include <cmath>
#include <iostream>
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

//Modyfikacja

 const Wektor Wektor::operator * (const Wektor &W)
 {
    Wektor Wynik;
    Wynik._SkladnikiW[0]=this->_SkladnikiW[1]*W._SkladnikiW[2]-this->_SkladnikiW[2]*W._SkladnikiW[1];
    Wynik._SkladnikiW[1]=(this->_SkladnikiW[0]*W._SkladnikiW[2]-this->_SkladnikiW[2]*W._SkladnikiW[0])*(-1);
    Wynik._SkladnikiW[2]=this->_SkladnikiW[0]*W._SkladnikiW[1]-this->_SkladnikiW[1]*W._SkladnikiW[0];
    return Wynik;
 }



    std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
    {
        Strm << "[" << Wek.Wez(0);
        for(int i=1; i<ROZMIAR; i++)
        {
            Strm << ", " << Wek.Wez(i);
        }
        Strm << "]";
        return Strm;
    }

    std::istream& operator >> (std::istream &Strm, Wektor &Wek)
    {
        for(int i = 0; i < ROZMIAR; i++)
        {
            Strm >> Wek[i];
        }
        return Strm;
    }


    const Wektor Wektor::operator + (const Wektor &W) const
    {
        Wektor Wynik;
        for(int i=0; i<ROZMIAR; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] + W._SkladnikiW[i];
        }
        return Wynik;
    }

    const Wektor Wektor::operator - (const Wektor & W) const
      {
        Wektor Wynik;
        for(int i=0; i<ROZMIAR; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] - W._SkladnikiW[i];
        }
        return Wynik;
    }
    const Wektor Wektor::operator * (double Z) const
    {
        Wektor Wynik;
        for(int i=0; i<ROZMIAR; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] *Z;
        }
        return Wynik;
    }

    double Wektor::operator * (const Wektor &W) const
    {
        double Wynik;
        for(int i=0; i<ROZMIAR; i++)
        {
            Wynik = Wynik + this->_SkladnikiW[i] * W._SkladnikiW[i];
        }
        return Wynik;
    }

    const Wektor Wektor::operator / (double Z) const
    {
        Wektor Wynik;
        for(int i=0; i<ROZMIAR; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] /Z;
        }
        return Wynik;
    }


    double Wektor::dlugosc() const
      {
          double wynik;
          for(int i = 0; i < ROZMIAR; i++)
          {
              wynik += this->_SkladnikiW[i]*this->_SkladnikiW[i];
          }
          return sqrt(wynik);
      }

