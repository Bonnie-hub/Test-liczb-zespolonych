#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyswietl(WyrazenieZesp  WyrZ)
{
    std::cout << "(" << WyrZ.Arg1.re << std::showpos << WyrZ.Arg1.im << std::noshowpos << "i)";

    switch(WyrZ.Op)
    {
        case "Op_Dodaj":
            std::cout << "+";
        break;

        case "Op_Odejmij":
            std::cout << "-";
        break;

        case "Op_Mnoz":
            std::cout << "*";
        break;

        case "Op_Dziel":
            std::cout << "/";
        break;
    }

    std::cout << "(" << WyrZ.Arg2.re << WyrZ.Arg2.im << "i)";
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona Wynik;

    switch(WyrZ.Op)
    {
        case "Op_Dodaj":
            Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;

        case "Op_Odejmij":
            Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;

        case "Op_Mnoz":
            Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;

        case "Op_Dziel":
            Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
    return Wynik;
}
