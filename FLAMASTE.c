#include <stdio.h>
#include <stdlib.h>

int main(void){
    char a[200] , b;
    int C , i , F;

    scanf("%d" , &C);
    if(C > 50 || C < 1)
        return 0;
    while((b = getchar()) != '\n' && b != EOF);

    while(C)
    {
    	for(i=0;i<200;i++)
    		a[i] = 0;

        fflush(stdin);
        if(fgets(a , 200 , stdin) == NULL)
            return 0;

        for(i = 0 ; i < 200 ; i++)
        {
            if(a[i] == 10 || a[i] == 0 || i == 199)
                break;
            if(a[i] < 65 || a[i] > 90)
                return 0;
        }

        for(i = 0 ; i < 200 ; i++)
        {
            F = 3;
            if(a[i] == 10 || i == 199)
                break;
            while(a[i] == a[i+1] && a[i] == a[i+2] && i < 198){F++; i++;}
            if(F != 3){
                printf("%c%d" , a[i] , F-1);
                i++;
            }
            else
                printf("%c" , a[i]);
        }
        printf("\n");
        C--;
    }
    return 0;
}
