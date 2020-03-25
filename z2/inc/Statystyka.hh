#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include"LZespolona.hh"

struct Statystyka
{
    int zle;
    int dobrych;
};

void dodaj_zla(Statystyka & stat);
void dodaj_dobra(Statystyka & stat);
void zeruj(Statystyka & stat);
int ile_dobrych(Statystyka & stat);
int ile_wszystkich(Statystyka & stat);
double procent_poprawnych(Statystyka & stat);

#endif