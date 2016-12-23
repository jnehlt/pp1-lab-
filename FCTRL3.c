#include <stdio.h>

int silnia(int n){
    int ns = 1 , i;
    for(i = 1 ; i <= n ; i++){
        ns *= i;
    }
    return ns;
}

int main(void){
    int D , n , i;
    do{
        scanf("%d" , &D);
    }while(D < 1 || D > 30);
    for(i = 0 ; i < D ; i++){
        do{
            scanf("%d" , &n);
        }while(n < 0 || n > 1000000000);
        if(n < 10)
            n = silnia(n);
        else
            n = 100;
        printf("%d %d\n" , (n / 10) % 10 , n % 10);
    }
    return 0;
}
