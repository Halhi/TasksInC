#include <stdio.h>
/*
Задача: Найти наибольший объём в массиве, который может был заполнен водой (числа в массиве - высота земли)
*/
void water();

int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int arrSize = sizeof(height) / sizeof(height[0]);
    water(height, arrSize); 
}

void water(int *massHeig, int size)
{
    int water = 0, *begArr = massHeig, *endArr = begArr + size - 1;
    while (begArr < endArr)
    {
        int heigth;
        if(*begArr < *endArr)
            heigth = *begArr;
        else
            heigth = *endArr;
        int w = (endArr - begArr) * heigth;
        if(w > water)
            water = w;
            while(*begArr <= heigth && begArr < endArr)
                begArr++;
            while(*endArr <= heigth && begArr < endArr)
                endArr--; 
    }
    printf("The maximum volume that can be filled with water is %d", water);
}
