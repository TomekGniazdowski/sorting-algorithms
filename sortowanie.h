#include <iostream>
#include <cmath>
#define ilosc_liczb 1000000


template <typename T>
class Sortowanie
{
    T *tablica_pomocnicza;
    T *tablica_pomocnicza_do_spr_ilosci;

public:

    Sortowanie();
    ~Sortowanie();

    void wypisz(T *tab);
    void kopiowanie_elementow_tablicy(T *tab);
    void losuj(T *tab,double procent);

    void sprawdz_czy_poprawnie(T *tab);
    double czas_sredni(double czas, double &suma);

    void sortowanie_szybkie(T *tab,int lewy, int prawy);
    int znajdz_pivot(T *tab, int lewy, int prawy);

    void sortowanie_introspektywne(T *tab, int lewy, int prawy, int glebokosc_rekurencji);

    void sortowanie_kopcowanie(T *tab, int dolna_granica, int gorna_granica);
    void tworz_kopiec_MAX(T *tab, int gorna_granica, int rodzic );

    void sortowanie_scalanie(T *tab,int lewy, int prawy);
    void scal(T *tab, int lewy, int srodek, int prawy);
};
