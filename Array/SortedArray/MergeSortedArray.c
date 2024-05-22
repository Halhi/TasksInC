#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0, j = 0, templ = 0, imaxnum = 0, maxnumber = -1000;
    int nums1[7] = {6,4,3,9,0,0,1};
    int nums2[4] = {8,2,6,0};
    int nums3[sizeof(nums1)/sizeof(nums1[0]) + sizeof(nums2)/sizeof(nums2[0])];
    // инициализация общего массива
    for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
    {
        if(i < sizeof(nums1)/sizeof(nums1[0]))
        {
            nums3[i] = nums1[i];
        }else{
            nums3[i] = nums2[i - sizeof(nums1)/sizeof(nums1[0])];
        }
    }
    // сортировка массива
    for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
    {
        for(int j = 0; j < sizeof(nums3)/sizeof(nums3[0]); j++)
        {
            if(nums3[i]<nums3[j])
            {
                templ = nums3[j];
                nums3[j] = nums3[i];
                nums3[i] = templ;
            }
        }

    }
    // фильтрация от повторений
    for(int i =0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
    {
        if (j == 0 || nums3[j - 1] != nums3[i]) // инициализация кол-ва повторений
        {
            nums3[j] = nums3[i];
            j++;
        }
    }
    // Нахождение максимального значения
    for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
        printf("nums3[%d] = %d\n", i, nums3[i]);
    for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
    {
        if(nums3[i] > maxnumber)
        {
            maxnumber = nums3[i];
            imaxnum = i;
        }
    }
    printf("Index of the max number - %d\nMax number - %d\n", imaxnum, maxnumber);
    // Сдвиг массива
    int shift = 0; // шаг сдвига
    int c = (abs(shift)) % (sizeof(nums3) / sizeof(nums3[0]));
    printf("c = %d\n", c);
    int g[c];
    j = 0;
    // сдвиг вправо
    if(shift < 0)
    {
        int temp = sizeof(nums3)/sizeof(nums3[0]) - c;
        for (int i = 0; i < c; i++)
        {
            
            g[i] = nums3[temp + i]; 
            printf("g[%d] = %d\n", i, g[i]);
        }
        for(int j = 0; j < c; j++)
        {
            for(int i = sizeof(nums3)/sizeof(nums3[0]); i >= 0; i--)
            {
                nums3[i] = nums3[i - 1];
            }
        }
        for (int i = 0; i < c; i++)
        {
            nums3[i] = g[sizeof(g)/sizeof(g[0]) - c + i];
        }
        for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
            printf("nums3[%d] = %d\n", i, nums3[i]);
    }
    // Сдвиг влево
    else if(shift >= 0)
    {
        for (int i = 0; i < c; i++)
        {
            g[i] = nums3[i];
        }
        for(int j = 0; j < c; j++)
        {
            for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
            {
                nums3[i] = nums3[i + 1];
            }
        }
        for (int i = 0; i < c; i++)
        {
            nums3[sizeof(nums3)/sizeof(nums3[0]) - c + i] = g[i];
        }
        for(int i = 0; i < sizeof(nums3)/sizeof(nums3[0]); i++)
            printf("nums3[%d] = %d\n", i, nums3[i]);
    }
}