#include <stdio.h>
/*
Задача: вывод предложения зигзагом
*/
int main()
{
    char sen[] = "PAYPALISHIRING";
    int lenZig = 3;

    int step = 2 * lenZig - 2;
    int i = 0, j = 0, myStep = 0, it = 0;
    char zigArr[sizeof(sen)];

    for(i = 0; i < sizeof(sen); i++)
        zigArr[i] = ' ';
    
    for(i = 0; i < lenZig; i++)
    {
        j = i;
        myStep = step - 2 * i;
        while (j < sizeof(sen))
        {
            zigArr[it++] = sen[j];
            if(!(i == 0 || i == lenZig - 1))
            {
                if(j + myStep < sizeof(sen))
                {
                    zigArr[it++] = sen[j + myStep];
                }
            }
            j += step;
        }
    }
    
    for (i = 0; i < sizeof(sen); i++)
    {
        if(i < 4)
            printf("%c\t\t", zigArr[i]);
        if(i == 3 || i == 11)
            printf("\n");
        if(i >= 4 && i < 11)
            printf("%c\t", zigArr[i]);
        if(i >= 11)
            printf("%c\t\t", zigArr[i]);
    }
}       