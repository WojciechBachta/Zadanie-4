#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


 const Macierz & UkladRownanLiniowych::WezMacierz() const
{
    return this->M;
}

const Wektor & UkladRownanLiniowych::WezWektor() const
{
    return this->W;
}

Macierz & UkladRownanLiniowych::WezMacierz()
{
    return this->M;
}

Wektor & UkladRownanLiniowych::WezWektor()
{
    return this->W;
}


void UkladRownanLiniowych::ZamienMacierz(const Macierz & M)
{
    this->M = M;
}

void UkladRownanLiniowych::ZamienWektor(const Wektor & W)
{
    this->W = W;
}

Wektor UkladRownanLiniowych::oblicz() const
{
    return this->M.MacierzOdwrotna() * this->W;
}

Wektor UkladRownanLiniowych::blad() const
{
    return ( this->M * this->oblicz() - this->W );
}


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.WezMacierz() >> UklRown.WezWektor();
    return Strm;
}

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown)
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
