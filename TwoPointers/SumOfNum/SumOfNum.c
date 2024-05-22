#include <stdio.h>
/*
Задача: Найти два числа, которые в сумме будут давать заданное число (условие: 1-е число больше единицы и
меньше второго числа, второе число больше первого и меньше длины масссива чисел)
*/
void summ();

int main()
{
    int setNum[] = {1,3,5,6,7,9,12,13,17,19,20,27,38,40};
    int res = 25;
    int sizeNum = sizeof(setNum) / sizeof(setNum[0]);
    summ(setNum, res, sizeNum);
}

void summ(int *massSetNum, int result, int arrSize)
{
    int numOne = 0, numTwo = 0;
    int *massNumTwo = massSetNum;
    int temp = 1;
    
    for(int i = 0; i < arrSize; i++)
    {
        numOne = *massSetNum;
        massNumTwo = massSetNum;
        for(int j = i; j < arrSize; j++)
        {
            numTwo = *massNumTwo;
            if(numOne + numTwo == result && numTwo < arrSize && *massSetNum != *massNumTwo && temp)
            {
                printf("\nThe number %d will be obtained from the numbers %d and %d\n\n",result, numOne, numTwo);
                temp = 0;
                break;
            }else
                massNumTwo++;
        }
        if(temp == 0)
            break;
        massSetNum++;
    }
    if(numOne + numTwo != result)
        printf("\nThe number %d cannot be obtained\n\n", result);
}