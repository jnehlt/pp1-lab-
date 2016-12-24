#include <stdio.h>
#include <stdlib.h>

int main(void){
    int t;
    unsigned long a , b;

    scanf("%d" , &t);
    if(t > 10 || t < 1)
        return 0;

    while(t)
    {
        scanf("%lu %lu" , &a , &b);
        if(a < 1 || b < 1 || a > 1000000000 || b > 1000000000)
            return 0;

        switch (a % 10)
        {
            case 1:
                {
                                    printf("1");
                    break;
                }
            case 2:
                {
                    if(b % 4 == 1)  printf("2");
                    if(b % 4 == 2)  printf("4");
                    if(b % 4 == 3)  printf("8");
                    if(b % 4 == 0)  printf("6");
                    break;
                }
            case 3:
                {
                    if(b % 4 == 1)  printf("3");
                    if(b % 4 == 2)  printf("9");
                    if(b % 4 == 3)  printf("7");
                    if(b % 4 == 0)  printf("1");
                    break;
                }
            case 4:
                {
                    if(b % 2 == 0)  printf("6");
                    else            printf("4");
                    break;
                }
            case 5:
                {
                                    printf("5");
                    break;
                }
            case 6:
                {
                                    printf("6");
                    break;
                }
            case 7:
                {
                    if(b % 4 == 1)  printf("7");
                    if(b % 4 == 2)  printf("9");
                    if(b % 4 == 3)  printf("3");
                    if(b % 4 == 0)  printf("1");
                    break;
                }
            case 8:
                {
                    if(b % 4 == 1)  printf("8");
                    if(b % 4 == 2)  printf("4");
                    if(b % 4 == 3)  printf("2");
                    if(b % 4 == 0)  printf("6");
                    break;
                }
            case 9:
                {
                    if(b % 2 == 0)  printf("1");
                    else            printf("9");
                    break;
                }
            case 0:
                {
                                    printf("0");
                    break;
                }
        }
        t--;
        printf("\n");
    }
    return 0;
}
