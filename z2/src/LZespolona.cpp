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

void wyswietl(LZespolona ZE)
{
  std::cout << "(" << ZE.re << std::showpos << ZE.im << std::noshowpos << "i)";
}

LZespolona utworz(int re, int im)
{
  LZespolona Wynik;

  Wynik.re = re;
  Wynik.im = im;
    
    return Wynik;
 }

bool wczytaj(LZespolona &in)
{
  char znak;
  cin>>znak;

  if(znak != ")") return false;
    
  cin>>in.re;
  cin>>in.im;
  cin>>znak;

  if(znak != "i") return false;
    
  cin>>znak;

  if(znak != ")") return false;
    
  return true;
}

bool wczytaj(std::istream &str, LZespolona &in)
{
  char znak;
  str>>znak;

  if(znak != ")") return false;
    
  str>>in.re;
  str>>in.im;
  str>>znak;

  if(znak != "i") return false;
    
  str>>znak;
  
  if(znak != ")") return false;
    
  return true;
}
