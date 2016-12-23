#include <stdio.h>
#include <math.h>

int main(){
    int n , m , i , sq , ck;

    scanf("%d" , &n);
        if(n >= 100000)
            return 0;
    do{
        ck = 1;
        scanf("%d" , &m);
        if(m <= 10000)
        {
            sq = sqrt(m);
            for(i = 2 ; i <= sq ; i++)
            {
                if(m % i == 0)
                {
                    ck = 0;
                }
            }
            if(ck == 0 || m == 1)
                printf("NIE\n");
            else
                printf("TAK\n");
            n--;
        }
    }while(n);

    return 0;
}
