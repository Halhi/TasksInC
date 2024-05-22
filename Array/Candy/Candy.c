#include <stdlib.h>
#include <stdio.h>
/*
Рассчитать минимально необходимое кол-во конфет, которое надо взять с собой, чтобы хватило всем детям(минимум одна конфета
каждому). Дети имеют рейтинг, исходя из которого рассчитвается кол-во конфет. Ребёнок с наибольшим рейтингом должен получать
больше конфет, чем соседние дети. Пример рейтинг[3] = {4,3,5}, Кол-во конфет[3] = {2,1,2}
*/
int main()
{
    int rating[10] = {1,2,1,4,5,8,3,1,6,0};
    int children = sizeof(rating) / sizeof(rating[0]);
    int candy[children];
    int numCan = 0;
    for(int i = 0; i < children; i++)
        candy[i] = 1;
    // Расчёт необходимого кол-ва конфет
    for(int i = 0; i < children; i++)
    {
        if(i == 0 && rating[i] > rating[i + 1])
            candy[i] += 1;
        else if(i > 0 && rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;
    }
    for(int i = children - 1; i >= 0; i--)
    {
        if(i == children - 1 && rating[i] > rating[i - 1])
            candy[i] += 1;
        else if(i < children - 1 && rating[i] > rating[i + 1])
        {
            if(candy[i] > candy[i + 1] + 1)
                candy[i] = candy[i];
            else
                candy[i] = candy[i + 1] + 1;
        }
    }
    for(int i = 0; i < children; i++)
    {
        numCan += candy[i];
        printf("candy[%d] =%d\n", i, candy[i]);
    }
    printf("minimum number of candies for children - %d\n", numCan);
}