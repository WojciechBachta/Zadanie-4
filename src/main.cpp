#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"








using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej


  cout << endl << " Start programu " << endl << endl;

std::fstream plik;
plik.open( "macierz.txt", std::ios::in );

plik >> UklRown;

Wektor Wyniki=UklRown.oblicz();

  cout << UklRown << "\n\n";
  cout << "     Rozwiazanie: " << Wyniki << "\n";
  cout << endl;
  cout << "     x1 = "<< Wyniki.Wez(0) <<endl;
  cout << "     x2 = "<< Wyniki.Wez(1) <<endl;
  cout << "     x3 = "<< Wyniki.Wez(2) <<endl;
  cout << endl;
  cout << "     Wektor bledu:  Ax - b  = " << UklRown.blad() << "\n";
  cout << "     Dlugosc wektora bledu: |Ax - b| = " << UklRown.blad().dlugosc() << "\n";
  cout << "     Wyznacznik = " << UklRown.WezMacierz().Wyznacznik() << "\n";
  cout << endl;
}
