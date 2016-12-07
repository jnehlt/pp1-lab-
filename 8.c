#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

float tablicuj(double Y[] , double X[] , const int N , double A , double B , double C , double beta , double deltax , double eps)
{
	int i;
	double x;
															//obliczenia
	for(i = 0 , x = 0 ; i < N ; i++ , x += deltax)
	{
		X[i] = x;
		Y[i] = A * exp(-beta * X[i]) / (B * x * x + C);		//	e^-x <==> exp(x) <--- biblioteka cmath
		if(Y[i] < eps) break;
	}

	return i;
}

void druk_wyniku(double Y[],double X[],int imax, int size){

	int i;

	for(i = 0 ; i < imax ; i++)
	{
		if(i % size == 0)
        {
            system("cls");
            printf("X\t\tF(x)\n");
        }
        printf("%.2f\t\t%5.4f\n" , X[i] , Y[i]);
        if(i % size == size - 1)
            system("Pause");
	}
}

int main(void)
{
	const int N=100;
	int i , imax , size=20;
	double A=1 , B=1 , C=1 , beta=1;
	double deltax=0.1 , eps=0.01;
	double X[N] , Y[N];

	imax=tablicuj(Y , X , N , A , B , C , beta , deltax , eps);
															//	ustawnienia okna konsoli *windows.h*
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = {0 , 0 , 40 , 21};
	SetConsoleWindowInfo(wHnd , 1 , &windowSize);
															//wydruk stronami (25 wierszy)
	druk_wyniku(Y , X , imax , size);

	return 0;
}
