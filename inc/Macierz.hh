#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>

#include "Wektor.hh"
using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {

    Wektor _SkladnikiM[ROZMIAR];

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:


   Wektor WezWiersz(int wiersz)const{
   return _SkladnikiM[wiersz];
   }
   void ZamienWiersz(int wiersz, Wektor W){
    _SkladnikiM[wiersz]=W;
   }
    const Wektor & operator[] (int index) const{
    return _SkladnikiM[index];
    }
    Wektor & operator[] (int index){
    return _SkladnikiM[index];
    }

    Macierz(); //jednostkowa

    Macierz operator + (const Macierz & M) const;
    Macierz operator - (const Macierz & M) const;
    Macierz operator * (const double l) const;
    Wektor operator * (const Wektor W) const;

    const Macierz MacierzOdwrotna() const;
    const Macierz operator * () const;
    const double Wyznacznik() const;

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
