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
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej



  Wektor Z;
  Wektor X;
  Wektor C;

  Z.Zamien(0,9);
  Z.Zamien(1,0);
  Z.Zamien(2,6);
  Z.Zamien(3,2);
  Z.Zamien(4,1);
  Z.Zamien(5,8);
  Z.Zamien(6,2);
  Z.Zamien(7,6);
  Z.Zamien(8,3);
  Z.Zamien(9,1);

  X.Zamien(0,5);
  X.Zamien(1,5);
  X.Zamien(2,8);
  X.Zamien(3,9);
  X.Zamien(4,4);
  X.Zamien(5,2);
  X.Zamien(6,0);
  X.Zamien(7,4);
  X.Zamien(8,1);
  X.Zamien(9,6);

  C.Zamien(0,4);
  C.Zamien(1,3);
  C.Zamien(2,6);
  C.Zamien(3,7);
  C.Zamien(4,2);
  C.Zamien(5,6);
  C.Zamien(6,3);
  C.Zamien(7,2);
  C.Zamien(8,7);
  C.Zamien(9,8);

  Macierz W;
  W.ZamienWiersz(0,Z);
  W.ZamienWiersz(1,X);
  W.ZamienWiersz(2,C);
  W.ZamienWiersz(3,Z);
  W.ZamienWiersz(4,X);
  W.ZamienWiersz(5,C);
  W.ZamienWiersz(6,Z);
  W.ZamienWiersz(7,X);
  W.ZamienWiersz(8,C);
  W.ZamienWiersz(9,Z);

  cout << "Macierz A:" << endl;

cout << W << endl;


  Macierz M;
  M.ZamienWiersz(0,X);
  M.ZamienWiersz(1,C);
  M.ZamienWiersz(2,Z);
  M.ZamienWiersz(3,X);
  M.ZamienWiersz(4,C);
  M.ZamienWiersz(5,Z);
  M.ZamienWiersz(6,X);
  M.ZamienWiersz(7,C);
  M.ZamienWiersz(8,Z);
  M.ZamienWiersz(9,X);

  cout << "Macierz B:" << endl;
  cout << M << endl;

  cout << endl;
  Macierz P;
  P=W-M;
  cout << "Macierz A-B:" << endl << P;
  cout << endl;
  cout << endl;
  Macierz O;
  O=*W;
  cout << "Macierz A - wyrazy do kwadratu:" << endl << O;
  cout << endl;























/*
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
  */
}
