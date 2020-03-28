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

LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2) //Jeśli bedzie dzielenie przez zero funkcja zwraca zero. Ale czy to dobrze?
{
  LZespolona Wynik, Licznik;
  double Mianownik;

  Licznik = Skl1 * sprzezenie(Skl2);
  Mianownik = pow(modul(Skl2),2);

  if(Mianownik == 0)
  {
    std::cerr << "Dzielenie przez zero" << std::endl;
    Wynik.re = 0; 
    Wynik.im = 0;
    return Wynik;
  }
  
  else
  {
    Wynik.re = Licznik.re/Mianownik;
    Wynik.im = Licznik.im/Mianownik;
    std::cout << Wynik.re << " " << Wynik.im << "i" << std::endl;
    return Wynik;
  }
  

  
}

LZespolona sprzezenie(LZespolona ZE)
{
  LZespolona Wynik;
  if(ZE.im < 0.00000001 && ZE.im > -0.00000001)
    return ZE;
  else
  {
    Wynik.im = -ZE.im;
    return Wynik;
  }
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

 bool operator == (LZespolona Skl1, LZespolona Skl2)
 {
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    return true;
  else
    return false;
 }

 bool operator != (LZespolona Skl1, LZespolona Skl2)
 {
    return !(Skl1 == Skl2);
 }

std::istream & operator >> (std::istream & str, LZespolona &in)
{
  char znak;
  str>>znak;

  if(znak != '(') {
    str.setstate(std::ios::failbit);
  }

  str>>in.re;
  str>>in.im;
  str>>znak;

  if(znak != 'i') {
    str.setstate(std::ios::failbit);
  }
    
  str>>znak;
  
  if(znak != ')') {
    str.setstate(std::ios::failbit);
  }
  return str;
}

std::ostream & operator << (std::ostream & str, LZespolona &out)
{
  str << "(" << out.re;
  if(out.im >= 0)
    str << "+" << out.im << "i)";

  else
    str << out.im << "i)";
  
  return str;
}