#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
//#include <iomainp>
using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

    double _SkladnikiW[ROZMIAR];


  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */


   public:


    double Wez(unsigned int index)const {
        return _SkladnikiW[index];
    }
    void Zamien(unsigned int index, double wartosc){
        _SkladnikiW[index]=wartosc;
    }

    double operator[](int Ind) const {return _SkladnikiW[Ind];}
    double& operator[](int Ind) {return _SkladnikiW[Ind];}

    const Wektor operator + (const Wektor &W) const;
    const Wektor operator - (const Wektor &W) const;
    const Wektor operator * (double Z) const;
    double operator * (const Wektor &W) const;
    const Wektor operator / (double Z) const;
    const Wektor operator * (const Wektor &W);

    double dlugosc() const;


};




/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
