#include <stdlib.h>
#include <stdio.h>
/*
Задача по заполнению ям водой. Дан массив и надо посчитать, какая площадь будет заполнена водой(ширина равна 1).
*/
int main()
{
    int groundHeight[9] = {2,0,0,1,0,0,3,0,1};
    int n = sizeof(groundHeight) / sizeof(groundHeight[0]);
    int maxleft = 0, maxright = 0, square = 0, i = 0;
    while(i < n - 1)
    {
        if(groundHeight[i] > maxleft)
            maxleft = groundHeight[i];
        if(groundHeight[n - i - 1] > maxright)
            maxright = groundHeight[n - i - 1];
        if(maxleft < maxright)
            square += maxleft - groundHeight[i++];
        else
            square += maxright - groundHeight[(n--) - 1];
        //printf("maxleft[%d] = %d\tvolume = %d\tmaxrigth[%d] = %d\n", i,maxleft,square, n - i - 1,maxright);
    }
    //printf("maxleft = %d\t maxright = %d\n", maxleft, maxright);
    printf("Water area is %d", square);
}