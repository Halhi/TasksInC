#include <stdlib.h>
#include <stdio.h>
/*
Расчёт индекса Хирша
*/

int main()
{
    int mass[10] = {6,4,8,7,6,7,8,5,7,7};
    int templ = 0;
    int max = 0;
    int n = sizeof(mass)/sizeof(mass[0]);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mass[i]<mass[j])
            {
                templ = mass[j];
                mass[j] = mass[i];
                mass[i] = templ;
            }
        }

    }

    for(int i = 0; i < n; i++)
    {
        if(mass[i] >= n - i && n - i > max)
            max = n - i;
    }
    printf("Hirsch index = %d", max);

}