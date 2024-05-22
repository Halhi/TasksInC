#include <stdio.h>
#include <ctype.h>
/*
Задача: Узнать, находится ли одна строка в другой строке
*/
int main()
{
    char mainStr[] = "A black cat runs after another black cat";
    char findStr[] = "cat";

    int i = 0, j = 0, n = 0, s = 0;

    for(i = 0; i < sizeof(mainStr); i++)
    {
        mainStr[i] = tolower(mainStr[i]);
        if(i < sizeof(findStr))
            findStr[i] = tolower(findStr[i]);
    }

    for(i = 0; i < sizeof(mainStr); i++)
    {
        if(mainStr[i] == findStr[0])
        {
            for(j = 1; j < sizeof(findStr); j++)
            {
                if(mainStr[i + j] != findStr[j])
                    break;
                if(j == sizeof(findStr) - 2)
                {
                    n++;
                    if(n == 1)
                        s = i + j;
                }
            }
        }
    }
    
    if(n > 0)
    {
        for (i = 0; i < sizeof(findStr); i++)
            printf("%c", mainStr[s - sizeof(findStr) + 1 + i] );
        printf(" occurs %d times, the first occurrence on the %d element", n, s - sizeof(findStr) + 3);
    }else
        printf("There is no such word in the sentence");
}