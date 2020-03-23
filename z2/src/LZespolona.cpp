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

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl2.re*Skl1.im;

  return Wynik;
}

LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik, Licznik;
  double Mianownik;

  Licznik = Skl1 * sprzezenie(Skl2);
  Mianownik = pow(modul(Skl2),2);

  Wynik.re = Licznik.re/Mianownik;
  Wynik.im = Licznik.im/Mianownik;

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

 bool operator == (LZespolona &Skl1, LZespolona &Skl2)
 {
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    return true;
  else
    return false;
 }

std::istream & operator >> (std::istream & str, LZespolona &in)
{
  char znak;
  str>>znak;

  if(znak != '(') {
    str.setstate(std::ios::failbit);
  };

  str>>in.re;
  str>>in.im;
  str>>znak;

  if(znak != 'i') {
    str.setstate(std::ios::failbit);
  };
    
  str>>znak;
  
  if(znak != ')') {
    str.setstate(std::ios::failbit);
  };
}

std::ostream & operator << (std::ostream & str, LZespolona &out)
{
  std::str << "(" << out.re << std::showpos << out.im << std::noshowpos << "i)";
}