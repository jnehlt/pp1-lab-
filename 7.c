#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generuj(double tab[] , int n , const double dol , const double gora)
{
    //////////////////
    srand(time(NULL) ^ clock());
    //////////////////

    int i;
    for(i = 0 ; i < n*n ; i++)
        tab[i] = dol + (double) rand() / RAND_MAX * (gora - dol);
}

/*
void wyswietl(double tab[] , int n)
{
    int i;
    for(i = 0 ; i < n*n ; i++)
    {
        if(i > 0 && i % n == 0)
            printf("\n");
        printf("%lf\t" , tab[i]);
    }
}
*/

int czy_przek_domin(double tab[] , const int n)
{
    int i , j , i2 , i3;
    double przek , suma_kolumny;
    printf("\n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            if(i == j)
            {
                przek = tab[i * n + j];     //
                if(przek < 0)               //przekatniowa
                    przek *= -1;            //

                i2 = i * n + j;
                suma_kolumny = 0;
                i3 = 1;
                while(i2 + n * i3 < n*n)                                                            //
                {                                                                                   //
                    suma_kolumny += tab[i2 + n * i3] < 0 ? -tab[i2 + n * i3] : tab[i2 + n * i3];    //sumuj elementy pod przekatniowa
                    i3++;                                                                           //
                }                                                                                   //

                i3 = 1;
                while(i2 - n * i3 >= 0)                                                             //
                {                                                                                   //
                    suma_kolumny += tab[i2 - n * i3] < 0 ? -tab[i2 - n * i3] : tab[i2 - n * i3];    //sumuj elementy nad przekatniowa
                    i3++;                                                                           //
                }                                                                                   //
            }
            if(suma_kolumny >= przek)   //sprawdz czy przekatniowa spelnia warunek macierzy przekatniowo dominujacej
                return 0;
        }
    }
    return 1;
}


int main(void){
    const int n = 5;                        //rozmiar wiersza tablicy
    const double dol = -10 , gora = 10;     //zakres generatora liczb pseudolosowych
    double tab[n*n];
    int czy = 0;

    generuj(tab, n , dol , gora);
    //wyswietl(tab , n);

//////////////////////////////////////////////////////////////////
    while(czy_przek_domin(tab , n))                             //
    {                                                           //
        if(czy >= n - 1)                                        //
        {                                                       //
            printf("Macierz przekatniowo dominujaca");          //
            return 0;                                           //
        }                                                       //
        czy++;                                                  //
    }                                                           //
//////////////////////////////////////////////////////////////////
                                                        //
    printf("Macierz nie jest przekatniowo dominujaca"); //
//////////////////////////////////////////////////////////

    return 0;
}
