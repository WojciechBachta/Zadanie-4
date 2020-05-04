#ifndef SUKLADROWNANLINIOWYCH_HH
#define SUKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "SMacierz.hh"
#include "SWektor.hh"
#include "rozmiar.h"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>
class SUkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

  SMacierz<STyp,SWymiar> M;
  SWektor<STyp,SWymiar> W;

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */



   //UkladRownanLiniowych() {};
   SMacierz<STyp,SWymiar> & WezMacierz();
   SWektor<STyp,SWymiar> & WezWektor();
   const SMacierz<STyp,SWymiar> & WezMacierz() const;
   const SWektor<STyp,SWymiar> & WezWektor() const;
   void ZamienMacierz(const SMacierz<STyp,SWymiar> & M);
   void ZamienWektor(const SWektor<STyp,SWymiar> & W);

   SWektor<STyp,SWymiar> oblicz() const;
   SWektor<STyp,SWymiar> blad() const;
};


template <typename STyp, int SWymiar>
const SMacierz<STyp,SWymiar> & SUkladRownanLiniowych<STyp,SWymiar>::WezMacierz() const
{
    return this->M;
}

template <typename STyp, int SWymiar>
const SWektor<STyp,SWymiar> & SUkladRownanLiniowych<STyp,SWymiar>::WezWektor() const
{
    return this->W;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> & SUkladRownanLiniowych<STyp,SWymiar>::WezMacierz()
{
    return this->M;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> & SUkladRownanLiniowych<STyp,SWymiar>::WezWektor()
{
    return this->W;
}

template <typename STyp, int SWymiar>
void SUkladRownanLiniowych<STyp,SWymiar>::ZamienMacierz(const SMacierz<STyp,SWymiar> & M)
{
    this->M = M;
}

template <typename STyp, int SWymiar>
void SUkladRownanLiniowych<STyp,SWymiar>::ZamienWektor(const SWektor<STyp,SWymiar> & W)
{
    this->W = W;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanLiniowych<STyp,SWymiar>::oblicz() const
{
    return this->M.MacierzOdwrotna() * this->W;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SUkladRownanLiniowych<STyp,SWymiar>::blad() const
{
    return ( this->M * this->oblicz() - this->W );
}


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
    Strm >> UklRown.WezMacierz() >> UklRown.WezWektor();
    return Strm;
}
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &Strm, const SUkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        Strm << "       [ ";
        for(int j = 0; j < ROZMIAR; j++)
        {
            Strm << UklRown.WezMacierz()[i][j] << " ";
        }
        Strm << "] ";

        Strm << "[ x" << i+1 << " ]";

        if( i == (int)(ROZMIAR/2) )
        {
            Strm << " = ";
        }
        else
        {
            Strm << "   ";
        }
        Strm << "[ " << UklRown.WezWektor()[i] << " ]\n";
    }

    return Strm;
}


#endif
