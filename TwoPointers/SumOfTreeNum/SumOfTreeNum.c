#include <stdio.h>
/*
Задача: Найти все возможные комбинации трёх чисел, которые в сумме дают 0, приэтом i != j, i != k, j != k
*/
void summ();

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = sizeof(nums) / sizeof(nums[0]);
    summ(nums, size);
}

void summ(int *num, int size)
{
    int *jTemp = num, *kTemp = num;
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        jTemp = num;
        for(int j = i; j < size; j++)
        {
            kTemp = jTemp;
            if(j == i)
            {
                jTemp++;
                continue;
            }
            for(int k = j; k < size; k++)
            {  

                if(k == j)
                {
                    kTemp++;
                    continue;
                }
                sum = *num + *jTemp + *kTemp;
                if(sum == 0)
                {
                    printf("lol\n");
                    printf("j[%d][%d][%d] = %d\n",i,j,k, *kTemp);
                }
                //printf("j[%d][%d][%d] = %d\n",i,j,k, *kTemp);
                kTemp++;
            }
            jTemp++;
        }
        num++;
    }
}