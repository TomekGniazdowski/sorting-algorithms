#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

#include "sortowanie.h"

//tworzenie dwoch tablic pomocniczych 1 - przy sortowaniu, 2 - przy sprawdzaniu sortowania
template <class T>
Sortowanie <T> :: Sortowanie()
{
    tablica_pomocnicza = new T [ilosc_liczb];
    tablica_pomocnicza_do_spr_ilosci = new T [ilosc_liczb];
}


//usuniecie tablic pomocniczych
template <class T>
Sortowanie <T> :: ~Sortowanie()
{
    delete [] tablica_pomocnicza;
    delete [] tablica_pomocnicza_do_spr_ilosci;
}


//kopiowanie elementow do tablicy pomocniczej
template <class T>
void Sortowanie <T>  :: kopiowanie_elementow_tablicy(T *tab)
{
    for(int i = 0; i<ilosc_liczb; ++i)
        tablica_pomocnicza_do_spr_ilosci[i] = tab[i];
}


//funkcja sprawdzajaca czy kolejnosc elementow i ich ilosc w tablicy jest poprawna
template <class T>
void Sortowanie <T>  :: sprawdz_czy_poprawnie(T *tab)
{
    int aktualny;

    for(int i = 0; i< ilosc_liczb - 1 ; ++i)
    {
        aktualny = tab[i];

        if(aktualny > tab[i+1])
        {
            std::cout << "##################################################################################" << std::endl;
            std::cout << "Blad na pozycji: " << i << std::endl;
            std::cout << tab[i] << std::endl;
            std::cout << tab[i+1] << std:: endl;
            std::cout << "##################################################################################" << std::endl;
        }
        else if(i == ilosc_liczb - 2)
            std::cout << "Bez bledow w kolejnosci." << std::endl;
    }

    for(int i = 0; i< ilosc_liczb; ++i)
    {
        int aktualna_zliczana_wartosc = i;
        int ilosc_elementow_org = 0;
        int ilosc_elementow_kop = 0;
        int k = 0;
        int j = 0;

        while(k < ilosc_liczb && j < ilosc_liczb)
        {
            if(tab[j] == aktualna_zliczana_wartosc)
                ilosc_elementow_org = ilosc_elementow_org + 1;

            if(tablica_pomocnicza_do_spr_ilosci[k] == aktualna_zliczana_wartosc)
                ilosc_elementow_kop = ilosc_elementow_kop + 1;

            k = k + 1;
            j = j + 1;
        }

        if(ilosc_elementow_kop != ilosc_elementow_org)
        {
            std::cout << "##################################################################################" << std::endl;
            std::cout << "Niepoprawna ilosc elementow! " << i << std::endl;
            std::cout << "##################################################################################" << std::endl;
        }
        else if(i == ilosc_liczb - 1)
            std::cout << "Bez bledow w ilosci elementow. \n" << std::endl;
    }
}


//funkcja liczaca sume czasow sorotwania
template <class T>
double Sortowanie <T>  :: czas_sredni(double czas, double &suma)
{
    suma = suma + czas;
    return suma;
}


//funkcja losujaca wartosci elementow tablicy
template <class T>
void Sortowanie <T> ::losuj(T *tab, double procent)
{
//    const int start  = 0;
//    const int stop    = ilosc_liczb;
//    std::random_device dev;
//    std::mt19937 generator(dev());
//    std::uniform_int_distribution<int> num(start, stop);

    for(int i = 0; i < (procent/100)*ilosc_liczb; ++i)
            tab[i] = i;

    for(int i = (procent/100)*ilosc_liczb; i<ilosc_liczb; ++i)
        tab[i] = rand()%ilosc_liczb;

//    for(int i = 0;i<ilosc_liczb;++i)
//        tab[i] = ilosc_liczb - i;


}

//funkjca wypisujaca elemnty tablicy
template <class T>
void Sortowanie <T> ::wypisz(T *tab)
{
    for(int licznik = 0; licznik<ilosc_liczb; ++licznik)
    {
        std::cout << tab[licznik];
        std::cout << " ";
    }
    std::cout << '\n';
    std::cout << '\n';
}


//sortowanie szybkie
template <class T>
void Sortowanie <T>  :: sortowanie_szybkie(T *tab, int lewy, int prawy)
{
    if(lewy < prawy){
        int os = znajdz_pivot(tab,lewy,prawy); //funkcja znajdujaca pivot
        sortowanie_szybkie(tab,lewy, os - 1); //sortowanie szybkie zastosowane dla lewej czesci podtablicy
        sortowanie_szybkie(tab,os + 1, prawy); //sortowanie szybkie zastosowane dla prawej czesci podtablicy
}
}

//funkcja znajdujaca pivot
template <class T>
int Sortowanie <T>  :: znajdz_pivot(T *tab, int lewy, int prawy)
{
    int i = lewy;
    int j  = lewy;
    int srodek = (lewy+prawy)/2;

    int os = tab[srodek];

    std::swap(tab[srodek],tab[prawy]);

    while(i <= prawy)
    {
        if(tab[i] <= os && i != prawy)
        {
            std::swap(tab[i],tab[j]);
            j = j + 1;
        }

        i = i + 1;

    }

    std::swap(tab[j],tab[prawy]);

    return j;

}

template <class T>
void Sortowanie <T> :: sortowanie_introspektywne(T *tab, int lewy, int prawy, int glebokosc_rekurencji)
{
    if(lewy < prawy){

    if (glebokosc_rekurencji == 0)//jezeli ilosc rekurencji jest wieksza od zadanej ilosci uruchamia sie sortowanie przez kopcowanir
    {
        for(int i = 0; i < prawy - lewy + 1 ; ++i)
            tablica_pomocnicza[i] = tab[lewy + i];

        sortowanie_kopcowanie(tablica_pomocnicza, 0, prawy - lewy + 1);

        for(int i = 0; i< prawy - lewy + 1; ++i)
            tab [lewy+i] = tablica_pomocnicza[i];
    }


    else//w kazdym innym przypadku uruchamiane jest sortowanie szybkie
    {
            int os = znajdz_pivot(tab,lewy,prawy);
            sortowanie_introspektywne(tab,lewy, os - 1,glebokosc_rekurencji - 1);
            sortowanie_introspektywne(tab,os + 1, prawy,glebokosc_rekurencji - 1);
    }

    }

}

//funkcja tworzaca kopiec maxymalny (kazdy rodzic wiekszy od swojego potomka)
template <class T>
void Sortowanie <T> :: tworz_kopiec_MAX(T *tab, int gorna_granica,  int rodzic)
{
    int wiekszy = rodzic;
    int lewy = 2 * rodzic + 1;
    int prawy = 2 * rodzic + 2;

    if(lewy <= (gorna_granica - 1) && tab[lewy] > tab[wiekszy])
        wiekszy = lewy;

    if(prawy <= (gorna_granica - 1) && tab[prawy] > tab[wiekszy])
        wiekszy = prawy;

    //funkcja dziala do momentu, gdy rodzic jest wiekszy od swoich potomkow
    if(wiekszy != rodzic)
    {
        std::swap(tab[wiekszy],tab[rodzic]);
        tworz_kopiec_MAX(tab,gorna_granica,wiekszy);
    }

}

template <class T>
void Sortowanie <T> :: sortowanie_kopcowanie(T *tab, int dolna_granica, int gorna_granica)
{
    //funkcja tworzaca kopiec maksymalny
    for(int i = gorna_granica/2 - 1; i>=dolna_granica ; --i)
    {
        tworz_kopiec_MAX(tab,gorna_granica,i);
    }

    //element maksymalny jest sciagany ze szczytu kopca i zamieniany z ostatnim elementem,
    //funkjca kopcowania jest wywolywana dla pozostalej czesci tablicy

    for(int i = gorna_granica - 1 ; i >= dolna_granica ; --i )
    {
        std::swap(tab[dolna_granica],tab[i]);
        tworz_kopiec_MAX(tab,i,dolna_granica);
    }

}

//funkcja scalania do sortowana przez scalanie
template <class T>
void Sortowanie<T>  :: scal(T *tab, int lewy, int srodek,int prawy)
{

    int i = lewy;
    int j = srodek + 1;


    for(int licznik = lewy; licznik<=prawy; ++licznik)
        tablica_pomocnicza[licznik] = tab[licznik];

    for(int licznik = lewy; licznik <= prawy; ++licznik)
    {

        if(tablica_pomocnicza[j] < tablica_pomocnicza[i] && i <= srodek && j <= prawy)
        {
            tab[licznik] = tablica_pomocnicza[j];
            j = j + 1;
        }

        else if(tablica_pomocnicza[j] >= tablica_pomocnicza[i] && i <= srodek && j <= prawy)
        {
            tab[licznik] = tablica_pomocnicza[i];
            i = i + 1;
        }

        else if(j > prawy)
        {
            tab[licznik] = tablica_pomocnicza[i];
            i = i + 1;
        }

        else if(i > srodek)
        {
            tab[licznik] = tablica_pomocnicza[j];
            j = j + 1;
        }
    }
}

template <class T>
void Sortowanie <T> :: sortowanie_scalanie(T *tab, int lewy,int prawy)
{
    if(prawy<=lewy)
        return;

    int srodek = (lewy + prawy)/2; //wyznaczany jest srodek poddtablicy

    sortowanie_scalanie(tab,lewy,srodek); //funkcja scalania dla lewej czesci podtablicy

    sortowanie_scalanie(tab, srodek + 1,prawy); //funkcja scalanie dla prawej czesci podtablicy

    scal(tab, lewy,srodek,prawy); //funkcja scalania

}
