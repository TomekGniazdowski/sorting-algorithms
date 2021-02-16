#include <iostream>
#include <time.h>
#include <windows.h>
#include "sortowanie.cpp"


using namespace std;

int main()
{


    cin.clear();
    cout.clear();

    clock_t start,stop;
    double czas,czas_sredni = 0;

    int klawiatura;
    double procent;
    int ilosc_powtorzen = 100;
    int minimalna_ilosc_elementow = 1000;
    char rodzaj_sortowania;

    while(rodzaj_sortowania != 'k')
    {
        cout << "Podaj stopien posortowania tablicy: ";
        cin >> procent;

        cout<< "Podaj ktore sortowanie zastosowac i - intospektywne, q - szybkie, s - scalanie, k - koniec: ";
        cin >> rodzaj_sortowania;

        cout << "Sortowanie tablicy " << ilosc_liczb << " - elementowej" << " posortowanej w " << procent << "%." << endl;


        if(rodzaj_sortowania == 'i')
        {
            Sortowanie <unsigned int> L1;

            unsigned int *tablica_liczb;

            tablica_liczb = new unsigned int [ilosc_liczb];

            for(int i = 0; i<ilosc_powtorzen; ++i)
            {

                L1.losuj(tablica_liczb,procent);
                L1.kopiowanie_elementow_tablicy(tablica_liczb);

                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L1.wypisz(tablica_liczb);
                start = clock();
                L1.sortowanie_introspektywne(tablica_liczb, 0, ilosc_liczb - 1, 2*log2(ilosc_liczb) );
                stop = clock();
                czas = (double)(stop-start) / (CLOCKS_PER_SEC/1000);
                //cout<<endl<<"Czas sortowania introspektywnego: "<<czas<< " s tablicy " << i <<endl;
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L1.wypisz(tablica_liczb);
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L1.sprawdz_czy_poprawnie(tablica_liczb);
                L1.czas_sredni(czas,czas_sredni);
            }
            cout << "################################################################### \n";
            cout << "Czas sredni sortowania introspektywnego: " << czas_sredni/ilosc_powtorzen << endl;
            delete [] tablica_liczb;

        }



        if(rodzaj_sortowania == 'q')
        {
            Sortowanie <unsigned int> L2;

            unsigned int *tablica_liczb;
            tablica_liczb = new unsigned int[ilosc_liczb];

            for(int i = 0; i<ilosc_powtorzen; ++i)
            {


                L2.losuj(tablica_liczb,procent);
                L2.kopiowanie_elementow_tablicy(tablica_liczb);
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L2.wypisz(tablica_liczb);
                start = clock();
                L2.sortowanie_szybkie(tablica_liczb,0,ilosc_liczb-1);
                stop = clock();
                czas = (double)(stop-start) / (CLOCKS_PER_SEC/1000);
                //cout<<endl<<"Czas sortowania szybkiego tablicy " << i << " : " <<czas<<  " s tablicy " << i <<endl;
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L2.wypisz(tablica_liczb);
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L2.sprawdz_czy_poprawnie(tablica_liczb);
                L2.czas_sredni(czas,czas_sredni);
            }
            cout << "Czas sredni sortowania szybkiego: " << czas_sredni/ilosc_powtorzen << endl;

            delete [] tablica_liczb;


        }


        if(rodzaj_sortowania == 's')
        {
            Sortowanie <unsigned int> L4;

            unsigned int *tablica_liczb;
            tablica_liczb = new unsigned int [ilosc_liczb];

            for(int i = 0; i<ilosc_powtorzen; ++i)
            {

                L4.losuj(tablica_liczb,procent);
                L4.kopiowanie_elementow_tablicy(tablica_liczb);
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L4.wypisz(tablica_liczb);
                start = clock();
                L4.sortowanie_scalanie(tablica_liczb,0,ilosc_liczb - 1);
                stop = clock();
                czas = (double)(stop-start) / (CLOCKS_PER_SEC/1000);
                //cout<<endl<<"Czas sortowania scalanie: "<<czas<< " s tablicy " << i <<endl;
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L4.wypisz(tablica_liczb);
                if(ilosc_liczb < minimalna_ilosc_elementow)
                    L4.sprawdz_czy_poprawnie(tablica_liczb);
                L4.czas_sredni(czas,czas_sredni);
            }
            cout << "Czas sredni sortowania - scalanie: " << czas_sredni/ilosc_powtorzen << endl;
            cout << "################################################################### \n";

            delete [] tablica_liczb;
        }

        else if(rodzaj_sortowania != 'k')
            cout << "Brak podanej opcji " << rodzaj_sortowania << endl;
    }

    return 0;
}
