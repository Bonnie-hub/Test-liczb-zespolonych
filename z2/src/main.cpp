#include <iostream>
#include "BazaTestu.hh"
#include"Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona LZesp;
  Statystyka stat;
  zeruj(stat);

  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
  {
    int licznik = 0;
    cout << " Oblicz wartość danego wyrażenia zespolonego: ";
    cout << WyrZ_PytanieTestowe << endl;
    //LZespolona Pom = Oblicz(WyrZ_PytanieTestowe);
    //cout << Pom << endl;
    cin >> LZesp;
    
    while((cin.fail() || LZesp != Oblicz(WyrZ_PytanieTestowe))&& licznik < 2)
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(10000,'\n');
        ++licznik;
        cout << "Źle wpisano liczbę zespoloną" << endl;
        cout << endl;
        cout << "Pozostałych prób: " << 3 - licznik << endl;
      }

      else if(LZesp != Oblicz(WyrZ_PytanieTestowe))
      {
        ++licznik;
        cout << "Źle obliczono wyrażenie zespolone" << endl;
        cout << endl;
        cout << "Pozostałych prób: " << 3 - licznik << endl;
      }
      cin >> LZesp;
    }
    if(licznik >= 2)
      dodaj_zla(stat);
    else
      dodaj_dobra(stat);
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  cout << "Udzielonych odpowiedzi: " << ile_wszystkich(stat) << endl;
  cout << endl;
  cout << "Poprawnych odpowiedzi: " << ile_dobrych(stat) << endl;
  cout << endl;
  cout << "Procent poprawnych: " << procent_poprawnych(stat) << endl;
  cout << endl;

}