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
        if(spr % size == 0)                             //jeœli osi¹gniesz krotnoœæ maksymalnej iloœci jednoczeœnie wyœwietlanych wierszy
        {
            system("cls");                              //czyœæ ekran i...
            printf("Imie\t\t\tNazwisko\t\t\tAdres\n");  //...wyœwietl nag³ówek
        }
        for(i = 0 ; i < 24 ; i++)
        {
            if(dane[spr][j][i] == '\n')                 //znak nowej lini jest automatycznie dodawany na koñcu ka¿dego wprowadzonego ci¹gu znaków (FGETS)
            {                                           //jeœli go napotkasz
                i=0;                                    //wyzeruj wartoœæ ostatniego wymiaru
                printf("\t\t\t");                       //bêdzie kolejny wyraz wiêc zrób miejsce
                j++;                                    //zmieñ przeszukiwany wymiar
                if(j == 3)                          //ale je¿eli osi¹gniesz niedozwolone 'j'
                {
                    printf("\n");                   //to znaczy ¿e wyœwietli³eœ ju¿ Imiê, Nazwisko i Adres
                    break;                          //zatem przerwij pêtlê
                }
            }
            printf("%c" , dane[spr][j][i]);
        }
        if((spr + 1) % size == 0)                       //jeœli kolejne wyœwietlenie bêdzie krotnoœci¹ maksymalnej iloœci jednoczeœnie wyœwietlanych wierszy
            system("Pause");                            //zrób pauzê... zaraz wszystko zniknie (spr % size == 0)
    }

    return 0;
}
