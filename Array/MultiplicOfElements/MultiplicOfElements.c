#include <stdlib.h>
#include <stdio.h>
/*
Перемножение элементов массива, исключая i
*/
int main()
{
    int nums[4] = {1,2,3,4,};
    int n = sizeof(nums) / sizeof(nums[0]);
    int left[n];
    left[0] = 1;
    int right[n];
    right[n - 1] = 1;
/*
// Решение в лоб
    int summ = 1;
    for(int i = 0; i < n; i++)
    {
       
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                left[i] *= nums[j];
                printf("left[%d] =%d\n", j, left[j]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        nums[i] = left[i];
        printf("nums[%d] = %d\n", i, nums[i]);
    }
*/
// Решение без вложенных циклов
    for(int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for(int i = n - 1; i > 0; i--)
    {
        right[i - 1] = right[i] * nums[i];
    }
    for(int i = 0; i < n; i++)
    {
        nums[i] = left[i] * right[i];
        printf("nums[%d] = %d\n", i, nums[i]);
    }
}