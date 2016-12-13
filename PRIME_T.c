/****************************************
 *                PRIME_T               *
 * check is given number a prime number *
 ***************************************/

#include <stdio.h>
#include <math.h>

int io_check(){
    int n , chk = 0;
    float nf2;
    char chk_in;
    do{
        chk_in = 1;
        system("cls");
        printf("Enter a number of natural\n");
        chk = scanf("%f" , &nf2);
        chk_in = getchar();
        fflush(stdin);
        if(chk_in != 10)        //NL
            chk = 0;
        n = nf2;
    }while(!chk || n <= 0 || n > 100000 || n != nf2);

    return n;
}

int is_prime(int n){
    int i , sq , logic = 0;
    sq = sqrt(n);

    if(n == 1)
        return 0;
    for(i = 2 ; i <= sq ; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void show(int logic , int n){
    system("cls");
    if(logic == 0)
        printf("%d is not a prime number.\n" , n);
    else
        printf("%d is a prime number.\n" , n);
}


int main(void){
    int n , logic;

    n = io_check();
    logic = is_prime(n);
    show(logic , n);

    return 0;
}
