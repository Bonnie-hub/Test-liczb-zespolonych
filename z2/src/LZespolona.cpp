#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
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

LZespolona sprzezenie(LZespolona ZE)
{
  LZespolona Wynik;

  Wynik.im = -ZE.im;

  return Wynik;
}

double modul(LZespolona ZE)
{
  return sqrt(pow(ZE.re, 2) + pow(ZE.im, 2));
}

LZespolona utworz(int re, int im)
{
  LZespolona Wynik;

  Wynik.re = re;
  Wynik.im = im;
    
    return Wynik;
 }

void wyswietl(LZespolona ZE)
{
  std::cout << "(" << ZE.re << std::showpos << ZE.im << std::noshowpos << "i)";
}
