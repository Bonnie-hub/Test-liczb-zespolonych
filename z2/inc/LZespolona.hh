#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
#include<cmath>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona utworz(double re, double im);
bool wczytaj(LZespolona &in);
bool wczytaj(std::istream &str, LZespolona &in);
void wyswietl(LZespolona ZE);
double modul(LZespolona ZE);
LZespolona sprzezenie(LZespolona ZE);

#endif
