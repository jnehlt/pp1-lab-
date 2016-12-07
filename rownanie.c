/*****************************************************************************
 * Napisz funkcje, ktora rozwiazuje uklad dwoch rownan z dwiema niewiadomymi *
 *   majac dane wspolczynniki przy niewiadomych oraz wektor prawej strony    *
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void input(float A[] , float B[]){          //wprowadzanie danych i walidacja
    int i , chk;

    for(i=0 ; i < 4 ; i++)
    {
        do
        {
            fflush(stdin);
            printf("Podaj wartosc wspolczynnika ");
            if(i % 2 == 1)
                printf("y\n= "); //y
            else
                printf("x\n= "); //x
            chk = scanf("%f" , &A[i]);
        }while(!chk);
    }

    for(i = 0 ; i < 2 ; i++)
    {
        do
        {
            fflush(stdin);
            printf("Podaj prawa strone ");
            if(i == 0)
                printf("pierwszego rownania\n");
            if(i == 1)
                printf("drugiego rownania\n");
            chk = scanf("%f" , &B[i]);
        }while(!chk);
    }

    system("cls");

    for(i = 0 ; i < 2 ; i++)
    {
        if(A[i * 1 + i] == -1)                          //x
            printf("- x " , A[i * 1 + i]);              //
        else if(A[i * 1 + i] == 1)                      //
            printf("x " , A[i * 1 + i]);                //
        else if(A[i * 1 + i] < 0)                       //
            printf("- %.0fx " , A[i * 1 + i] * -1);     //
        else if(A[i * 1 + i] >= 0)                      //
            printf("%.0fx " , A[i * 1 + i]);            //end_x

        if(A[i * 1 + i + 1] == -1)                      //y
            printf("- y ");                             //
        else if(A[i * 1 + i + 1] == 1)                  //
            printf("+ y ");                             //
        else if(A[i * 1 + i + 1] < 0)                   //
            printf("- %.0fy " , A[i * 1 + i + 1] * -1); //
        else if(A[i * 1 + i + 1] >= 0)                  //
            printf("+ %0.fy " , A[i * 1 + i + 1]);      //end_y

        if(B[i] >= 0)                                   //=
            printf("= %.0f\n" , B[i]);                  //
        if(B[i] < 0)                                    //
            printf("= - %.0f\n" , B[i] * -1);           //end_=
    }
}

void wyswietl(int chk , float x , float y , float W , float Wx , float Wy){
    printf("\n=================================\n");
    if(chk == 0)
    {
        x = Wx / W;
        y = Wy / W;
        printf("x = %.2f\ny = %.2f\n" , x , y);
    }
    if(chk == 2)
        printf("Brak rozwiazan.\n");
    if(chk == 3)
        printf("Nieskonczenie wiele rozwiazan\n");
}

void oblicz(float A[] , float B[]){     //metoda wyznaczikow
    int i , chk = 0;
    float W, Wx, Wy;
    float x , y;

                                        //      | A[0]   A[1] |
                                        //  W = |             | = A[0]*A[3] - A[2]*A[1];
                                        //      | A[2]   A[3] |

    W = A[0] * A[3] - A[2] * A[1];      //      | B[0]   A[1] |
    Wx = B[0] * A[3] - B[1] * A[1];     // Wx = |             | = B[0]*A[3] - B[1]*A[1];
    Wy = A[0] * B[1] - A[2] * B[0];     //      | B[1]   A[3] |

                                        //      | A[0]   B[0] |
                                        // Wy = |             | = A[0]*B[1] - A[2]*B[0];
                                        //      | A[2]   B[1] |
    if(W == 0)
        chk++;
    if(Wx == 0)
        chk++;
    if(Wy == 0)
        chk++;

    wyswietl(chk , x , y , W , Wx , Wy);
}

int main(void){
    float A[4]; //wspolczynniki (2x2)
    float B[2]; //prawa strona  (1x2)

    input(A , B);
    oblicz(A , B);

    return 0;
}
