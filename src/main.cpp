#include <iostream>
#include <fstream>

//#include "Macierz.hh"
#include "SUkladRownanLiniowych.hh"
#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include "SMacierz.hh"






using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  SUkladRownanLiniowych<double,ROZMIAR>   UklRown;   // To tylko przykladowe definicje zmiennej


/*
    SMacierz<LZespolona, ROZMIAR> M;
    SWektor<LZespolona, ROZMIAR> W;
    SWektor<LZespolona, ROZMIAR> H;
    SWektor<LZespolona, ROZMIAR> G;
    LZespolona Z={2,5};
    LZespolona X={4,1};
    LZespolona C={1,5};
    LZespolona V={3,1};
    LZespolona B={2,8};
    LZespolona N={5,9};


    W.Zamien(0,Z);
    W.Zamien(1,X);

    H.Zamien(0,C);
    H.Zamien(1,V);

    G.Zamien(0,B);
    G.Zamien(1,N);

    M.ZamienWiersz(0, W);
    M.ZamienWiersz(1, H);

    UklRown.ZamienMacierz(M);
    UklRown.ZamienWektor(G);
*/
  cout << endl << " Start programu " << endl << endl;

std::fstream plik;
plik.open( "macierz.txt", std::ios::in );

plik >> UklRown;

SWektor<double,ROZMIAR> Wyniki=UklRown.oblicz();

  cout << UklRown << "\n\n";
    //cout << "Macierz odwrotna:" <<endl;
      //cout << UklRown.WezMacierz().MacierzOdwrotna() <<endl;
  cout << "     Rozwiazanie: " << Wyniki << "\n";
  cout << endl;
  cout << "     x1 = "<< Wyniki.Wez(0) <<endl;
  cout << "     x2 = "<< Wyniki.Wez(1) <<endl;
  cout << "     x3 = "<< Wyniki.Wez(2) <<endl;
  cout << "     x4 = "<< Wyniki.Wez(3) <<endl;
  cout << "     x5 = "<< Wyniki.Wez(4) <<endl;
  cout << "     x6 = "<< Wyniki.Wez(5) <<endl;
  cout << endl;
  cout << "     Wektor bledu:  Ax - b  = " << UklRown.blad() << "\n";
  //cout << "     Dlugosc wektora bledu: |Ax - b| = " << UklRown.blad().dlugosc() << "\n";
  cout << "     Wyznacznik = " << UklRown.WezMacierz().Wyznacznik() << "\n";
  cout << endl;


}

