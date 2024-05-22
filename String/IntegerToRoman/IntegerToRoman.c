#include <stdlib.h>
#include <stdio.h>
/*
Задача: перевод целых чисед в римские
*/
int main()
{
    int integer =3333;
    int n = 0, lenNum = 0, tempInteg = integer, i = 0;
    char roman[4][10][5] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "CX"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}};

    for(tempInteg; tempInteg > 0; tempInteg /= 10)
    {
        lenNum++;
    }

    int temp[lenNum];
    
    for (i = 0; integer > 0; integer /= 10, i++)
        temp[lenNum - 1 - i] = integer % 10;
    for(i = 0;  i < lenNum ; i++)
        printf("%s", roman[lenNum-1-i][temp[i]]);

}