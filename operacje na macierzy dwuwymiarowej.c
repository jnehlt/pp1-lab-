#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void wyswietl(float A[] , const int n , const int m , int chk){
    int i , transpon = 0;

    if(chk != 0)
    {
        for(i = 0 ; i < m / 2 ; i++)
        {
            printf("\t");
            if(chk == 1 && i == m / 2 - 1)
                printf("\tPo zamianie kolumn\n");
            else if(chk == 2 && i == m / 2 - 1)
                printf("\tPo zamianie wierszy\n");
            else if(chk == 3 && i == m / 2 - 1)
                printf("\tPo zamianie wzgledem srodka\n");
            else if(chk == 4 && i == m / 2 - 1)
            {
                printf("\tPo Transponowaniu\n");
                transpon = 1;
            }
        }
    }

    for(i = 0 ; i < n * m ; i++)
    {
        if(A[i] < 0)
            printf("%.4f    " , A[i]);
        else
            printf(" %.4f    " , A[i]);
        if(transpon == 0)
        {
            if((i + 1) % m == 0)
                printf("\n");
        }
        else
        {
            if((i + 1) % n == 0)
                printf("\n");
        }
    }

    if(transpon == 0)
    {
        for(i = 0 ; i < m ; i++)
            printf("===========");
        printf("\n");
    }
    else
    {
        for(i = 0 ; i < n ; i++)
            printf("===========");
        printf("\n");
    }
}

int zamien_kolumny(float A[] , const int n , const int m , int chk){
    int i , j , srodek = m / 2;
    float bufor;

    for(j = 0 ; j < n ; j++)
    {
        for(i = 0 ; i < srodek ; i++)
        {
            bufor = A[j * m + i];
            A[j * m + i] = A[j * m + m - 1 - i];
            A[j * m + m - 1 - i] = bufor;
        }
    }

    return 1;
}

int zamien_wiersze(float A[] , const int n , const int m , int chk){
    int i , j , srodek = n / 2;
    float bufor;

    for(j = 0 ; j < srodek ; j++)
    {
        for(i = 0 ; i < m ; i++)
        {
            bufor = A[j * m + i];
            A[j * m + i] = A[n * m - 1 - m + i + 1 - m * j];
            A[n * m - 1 - m + i + 1 - m * j] = bufor;
        }
    }

    return 2;
}

int zamien_wzgledem_srodka_macierzy(float A[] , const int n , const int m , int chk){
    int j , srodek = n * m / 2;
    float bufor;

    for(j = 0 ; j < srodek ; j++)
    {
        bufor = A[j];
        A[j] = A[m * n - (j + 1)];
        A[m * n - (j + 1)] = bufor;
    }

    return 3;
}

int transponuj(float A[] , const int n , const int m , int chk){
    int i , j = 0 , k = m;
    float bufor;

//    if(m > n)
//    {
//        int o = m - (m - n);
//        float buf[n];
//
//        for(i = 0 ; i < n ; i++)
//        {
//            buf[i] = A[(i + 1) * m - 1];
//            printf("buf[i] = %.4f\n" , buf[i]);
//        }
//
//
//        for(j = 0 ; j < n ; j++)
//        {
//            for(i = 0 ; i < n && i < k && k > 1 ; i++)
//            {
//                if(k - 1 - i == 0)
//                    break;
//                if(m * (m - (k - 1) + i) + j >= m * n)
//                    break;
//                printf("m - (k - 1) + i + j * m = %d\n" , m - (k - 1) + i + j * m);
//                printf("m * (m - (k - 1) + i) + j = %d\n" ,m * (m - (k - 1) + i) + j);
//                printf("i = %d, k = %d, m = %d, n = %d\n" , i , k , m , n);
//                bufor = A[m - (k - 1) + i + j * m];
//                printf("bufor = %.4f\n" , bufor);
//                printf("A = %.4f\n" , A[m * (m - (k - 1) + i) + j]);
//                printf("A1 = %.4f\n" , A[m - (k - 1) + i + j * m]);
//                A[m - (k - 1) + i + j * m] = A[m * (m - (k - 1) + i) + j];
//                A[m * (m - (k - 1) + i) + j - o] = bufor;
//            }
//            k--;
//        }
//    }
    if(m == n)
    {
        for(j = 0 ; j < n ; j++)
        {
            for(i = 0 ; i < k && k > 1 ; i++)
            {
                if(k - 1 - i == 0)
                   break;
                bufor = A[m - (k - 1) + i + j * m];
                A[m - (k - 1) + i + j * m] = A[m * (m - (k - 1) + i) + j];
                A[m * (m - (k - 1) + i) + j] = bufor;
            }
            k--;
        }
    }
    else
    {
        printf("Tego jeszcze nie umiem :'(\n Sprobuj macierz kwadratowa :)\n");
        system("Pause");
        return 0;
    }

    return 4;
}

int zamien_losowo(float A[] , const int n , const int m , int chk){
    int i , j , srodek = n * m / 2 , what = 0;
    float buf1;
    int B[n * m] , buf2;

 //wkrotce
}

int main (void){
    srand(time(NULL));
    const int n = 10 , m = 10;                /*<-wymiary A*/
    const float min = -1.5 , max = 1.5;     /*<-zakres*/
    int i , chk = 0;
    float A[n*m];                           //Niech macierz dwuwymiarowa bedzie jednowymiarowa.

    for(i = 0 ; i < n * m ; i++)
        A[i] = (max - min) * rand() / RAND_MAX + min;

    wyswietl(A , n , m , chk);
    chk = zamien_kolumny(A , n , m , chk);
    wyswietl(A , n , m , chk);
    chk = zamien_wiersze(A , n , m , chk);
    wyswietl(A , n , m , chk);
    chk = zamien_wzgledem_srodka_macierzy(A , n , m , chk);
    wyswietl(A , n , m , chk);
    //chk = zamien_losowo(A , n , m , chk);
    chk = transponuj(A , n , m , chk);
    wyswietl(A , n , m , chk);

    return 0;
}
