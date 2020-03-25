#include"Statystyka.hh"

void dodaj_zla(Statystyka & stat)
{
    ++stat.zle;
}

void dodaj_dobra(Statystyka & stat)
{
    ++stat.dobrych;
}

void zeruj(Statystyka & stat)
{
    stat.dobrych = 0;
    stat.zle = 0;
}

int ile_dobrych(Statystyka & stat)
{
    return stat.dobrych;
}

int ile_wszystkich(Statystyka & stat)
{
    return stat.dobrych + stat.zle;
}

double procent_poprawnych(Statystyka & stat)
{
    if(ile_wszystkich(stat) != 0)
    {
        //int i = ;
        //std::cout << stat.dobrych/ile_wszystkich(stat) << std::endl;
        return stat.dobrych*100/ile_wszystkich(stat);
    }
    else
    {
        std::cerr << "Brak udzielonych odpowiedzi" << std::endl;
        return 0; 
    }
    
}