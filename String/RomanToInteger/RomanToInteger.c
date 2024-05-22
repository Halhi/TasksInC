#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
/*
Задача: перевод римских цифр в целые числа
*/
int main()
{
    int integer = 0;
    char romNum[100] = "mcxi";
    int intmass[sizeof(romNum)];
    for(int i = 0; i < sizeof(romNum); i++)
    {
        romNum[i] = toupper(romNum[i]);
        if(romNum[i] == 'I')
            intmass[i] = I;
        else if(romNum[i] == 'V')
            intmass[i] = V;
        else if(romNum[i] == 'X')
            intmass[i] = X;
        else if(romNum[i] == 'L')
            intmass[i] = L;
        else if(romNum[i] == 'C')
            intmass[i] = C;
        else if(romNum[i] == 'D')
            intmass[i] = D;
        else if(romNum[i] == 'M')
            intmass[i] = M;
        else
            intmass[i] = 0;
    }
    integer = intmass[sizeof(romNum) - 1];
    for(int i = sizeof(romNum); i > 1; i--)
    {
        if(intmass[i - 1] <= intmass[i - 2])
        {
            integer += intmass[i - 2];
        }
        else
        {
            integer -= intmass[i - 2];
        }
    }
    printf("Roman number %s in integers is %d\n",romNum, integer);
}