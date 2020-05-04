#include "LZespolona.hh"
#include <cmath>
//#include "WyrazenieZesp.hh"
#include <iostream>
using namespace std;

LZespolona stworz(double r, double i)
{
    LZespolona z;
    z.re=r;
    z.im=i;
    return z;
}

LZespolona &LZespolona::operator = (double  Liczba)
{
  this->re = Liczba;
  this->im = 0;
  return *this;
}


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

 istream& operator >> (istream& wej, LZespolona& z)
{
    char znak;
    wej >> znak;
    if(znak != '(') wej.setstate(std::ios::failbit);
    wej >> z.re >> z.im >> znak;
    if(znak != 'i') wej.setstate(std::ios::failbit);
    wej >> znak;
    if(znak != ')') wej.setstate(std::ios::failbit);
    return wej;
}

 ostream& operator << (ostream& wyj, const LZespolona& z)
 {
    wyj << "(" << z.re << showpos << z.im << noshowpos << "i)";
    return wyj;
 }


 void Wyswietl(LZespolona z)
 {
     cout<<"(";
     if(z.im<0)
     {
         cout<<z.re<<z.im<<"i";
     }
     else
     {
         cout<<z.re<<"+"<<z.im<<"i";
     }
     cout<<")";
 }

LZespolona Sprzezenie(LZespolona z)
 {
        z.im=z.im*(-1);
        return z;
 }

double Modul2(LZespolona z)
{
    return z.re*z.re+z.im*z.im;
}

LZespolona operator % (LZespolona x, LZespolona y)
{
    LZespolona wynik{0,0};
    int pom;

    if((x.re<y.re) && (x.im<y.im))
        return x;
    else if((x.re>y.re) && (x.im>y.im))
    {
        pom=(x.re/y.re);
        wynik.re=(x.re-(pom*y.re));
        pom=(x.im/y.im);
        wynik.im=(x.im-(pom*y.im));
        return wynik;
    }
    else if((x.re>y.re) && (x.im<y.im))
    {
        pom=(x.re/y.re);
        wynik.re=(x.re-(pom*y.re));
        wynik.im=x.im;
    return wynik;
    }
    else
    {
        pom=(x.im/y.im);
        wynik.im=(x.im-(pom*y.im));
        wynik.re=x.re;
    return wynik;
    }
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re-Skl1.im*Skl2.im;
  Wynik.im = Skl1.re * Skl2.im+Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2;
  Wynik.im = Skl1.im * Skl2;
  return Wynik;
}

LZespolona  operator * (double  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1 * Skl2.re;
  Wynik.im = Skl1 * Skl2.im;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
      LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

LZespolona  operator / (double  Skl1,  LZespolona  Skl2)
{
      LZespolona  Wynik;

  Wynik.re = Skl2.re / Skl1;
  Wynik.im = Skl2.im / Skl1;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik=Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
    if((abs(Skl1.re-Skl2.re) < 0.0001) && (abs(Skl1.im-Skl2.im) < 0.0001))
        return true;
    return false;

}

bool operator != (LZespolona Skl1, LZespolona Skl2)
{
    return !(Skl1 == Skl2);
}



