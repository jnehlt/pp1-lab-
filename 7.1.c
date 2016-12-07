#include <stdio.h>
#include <stdlib.h>

int main(void){
    int ileStd , spr , i = 0 , j = 0 , size = 4;

    do
    {
        system("cls");
        printf("Podaj liczbe studentow:\n");
        spr = scanf("%d" , &ileStd);
        fflush(stdin);
    }while(!spr);

    char dane[ileStd][3][25];                       //deklaracja tablicy

    for(spr = 0 ; spr < ileStd ; spr++)
    {
        system("cls");
        printf("Imie: ");
        fgets(&dane[spr][0][0] , 24 , stdin);
        fflush(stdin);
        printf("Nazwisko: ");
        fgets(&dane[spr][1][0] , 24 , stdin);
        fflush(stdin);
        printf("Adres: ");
        fgets(&dane[spr][2][0] , 24 , stdin);
        fflush(stdin);
    }

    for(spr = 0 ; spr < ileStd ; spr++)
    {
        j = 0;
        if(spr % size == 0)                             //je�li osi�gniesz krotno�� maksymalnej ilo�ci jednocze�nie wy�wietlanych wierszy
        {
            system("cls");                              //czy�� ekran i...
            printf("Imie\t\t\tNazwisko\t\t\tAdres\n");  //...wy�wietl nag��wek
        }
        for(i = 0 ; i < 24 ; i++)
        {
            if(dane[spr][j][i] == '\n')                 //znak nowej lini jest automatycznie dodawany na ko�cu ka�dego wprowadzonego ci�gu znak�w (FGETS)
            {                                           //je�li go napotkasz
                i=0;                                    //wyzeruj warto�� ostatniego wymiaru
                printf("\t\t\t");                       //b�dzie kolejny wyraz wi�c zr�b miejsce
                j++;                                    //zmie� przeszukiwany wymiar
                if(j == 3)                          //ale je�eli osi�gniesz niedozwolone 'j'
                {
                    printf("\n");                   //to znaczy �e wy�wietli�e� ju� Imi�, Nazwisko i Adres
                    break;                          //zatem przerwij p�tl�
                }
            }
            printf("%c" , dane[spr][j][i]);
        }
        if((spr + 1) % size == 0)                       //je�li kolejne wy�wietlenie b�dzie krotno�ci� maksymalnej ilo�ci jednocze�nie wy�wietlanych wierszy
            system("Pause");                            //zr�b pauz�... zaraz wszystko zniknie (spr % size == 0)
    }

    return 0;
}
