#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int io_check(int *a){
    int b , sprawdz;                                                                                        //START-INIT
    float aF , bF , a2F , b2F;                                                                              //END-INIT

    do                                                                                                      //START-IO-CHECK
    {                                                                                                       //
        system("cls");                                                                                      //
        printf("Podaj zakres (a b):\n");                                                                    //
        sprawdz = scanf("%f %f" , &a2F , &b2F);                                                             //
        fflush(stdin);                                                                                      //
        a2F = *a = aF = a2F;                                                                                //
        b2F = b = bF = b2F;                                                                                 //
        if(a2F < 1 || a2F != aF || b2F < 1 || b2F != bF || a2F >= b2F)                                      //
        {                                                                                                   //
            if(a2F >= b2F && !(a2F < 1 || a2F != aF || b2F < 1 || b2F != bF))                               //
            {                                                                                               //
                if(a2F == b2F)                                                                              //
                {                                                                                           //
                    *a = a2F;                                                                               //
                    break;                                                                                  //
                }                                                                                           //
                puts("Podales niewlasciwy zakres\nLiczba poczatkowa nie moze byc wieksza niz koncowa\n");   //
                system("pause");                                                                            //
            }                                                                                               //
            else                                                                                            //
            {                                                                                               //
                puts("Podaj liczbe naturalna");                                                             //
                sprawdz = 0;                                                                                //
                system("pause");                                                                            //
        }   }                                                                                               //
    }while(sprawdz != 2 || a2F != aF || b2F != bF || a2F > b2F);                                            //END-IO-CHECK

    return b - *a;
}

void wyznacz_wartosci(float W[], int a, int przedzial){
    int i;

    for(i = 0 ; i <= przedzial ; i++)
    {
        if(a % 2 == 0)                                                                                      //jesli parzysta
            W[i] = a / 2 + a * a;
        else                                                                                                //jesli nieparzysta
            W[i] = (a - 5) * a;
        a++;                                                                                                //zwieksz argument
    }
}

void drukuj(float W[] , int a , int przedzial , int rozmiar){
    int i;

    for(i = 0 ; i <= przedzial ; i++)
    {
        if(i % rozmiar == 0)                                                                                //jesli wyswietlisz wielokrotnosc dopuszczalnej ilosci wierszy
        {
            system("cls");                                                                                  //wyczysc okno
            printf("n\t\tW(n)\n");                                                                          //wyswietl naglówek n-argument W(n)-wartosc funkcji w punkcie
        }
        printf("%d\t\t%.0f\n" , a , W[i]);                                                                  //wyswietl wartosci w punkcie
        if(i % rozmiar == rozmiar - 1)                                                                      //jesli jestes w przedostatnim wierszu
        {
            printf("\n");                                                                                   //
            system("pause");                                                                                //czekaj na uzytkownika
        }
        a++;                                                                                                //zwieksz argument
    }
}

int main(void){
    int n , przedzial , rozmiar = 10;

    przedzial = io_check(&n);                                                                               //<---------------------\   /
    float W[przedzial];                                                                                     //ustaw wielkosc tablicy_\

    wyznacz_wartosci(W , n , przedzial);

    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);                                                          //wydobadz uchwyt
	SMALL_RECT windowSize = {0 , 0 , 30 , 1};                                                              //deklaracja wielkosci okna
	SetConsoleWindowInfo(wHnd , 1 , &windowSize);                                                           //ustaw wielkosc okna

    drukuj(W , n , przedzial , rozmiar);

    return 0;
}
