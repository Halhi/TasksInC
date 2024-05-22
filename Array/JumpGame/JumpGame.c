#include <stdlib.h>
#include <stdio.h>
/*
Игра "прыжки по массиву"
*/
int main()
{
    int mass[15] = {1,3,1,2,1,2,2,1,3,1,2,1,2,5,1}; // массив для игры
    int step = 0;
    int index = 0;
    for (step; step < (sizeof(mass) / sizeof(mass[0])) - 1; step)
    {
        step += mass[step];
        index++;
        if(step == (sizeof(mass) / sizeof(mass[0])) - 1)
        {
            printf("You won in %d jumps\n", index);
            break;
        }
        if(step > (sizeof(mass) / sizeof(mass[0])) - 1 || mass[step] == 0)
        {
            printf("You lost\n");
            break;
        }
        if(mass[step] < 0)
        {
            printf("You can't go back");
            break;
        }
        //printf("mass[%d] = %d\n", step, mass[step]);
        //printf("step = %d\n", step);
    }
}

