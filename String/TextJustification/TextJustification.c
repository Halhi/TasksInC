#include <stdio.h>
/*
Задача: Выровнить текст по назначенной ширине (переделать)
*/
int main()
{
    int maxWidth = 16;
    char words[7][16] = {"This", "is", "an", "example", "of", "text", "justification"};
    char endwords[3][16];
    int i = 0, j = 0, n = 0, c = 0, b = 0, t = 0;

    for(i = 0; i < sizeof(words) / sizeof(words[0]); i++)
    {  
        while(words[i][j] != '\0')
            j++;
        b += j;
        j = 0;
        while(words[i][j] != '\0')
        {
            if(maxWidth - b > 0)
            {
                endwords[c][n] = words[i][j];
                n++;
                j++;
            }else
            {
                while (n < sizeof(endwords[0]))
                {
                    endwords[c][n] = ' ';
                    n++;
                }
                endwords[c][n - 1] = '\0';
                n = 0;
                c++;
                b = 0;
            }
        }
        if(i != (sizeof(words) / sizeof(words[0])) - 1)
        {
            endwords[c][n] = ' '; 
            n++;
            b++;
        }
        else
        {
            while (n < sizeof(endwords[0]) - 1)
            {
                endwords[c][n] = ' ';
                n++;
            }
        }
    }

    for(i = 0; i < sizeof(endwords) / sizeof(endwords[0]); i++)
    {  
        b = 0, j = 0, c = 0;
        while(endwords[i][j] != '\0')
        {
            if(endwords[i][j + 1] != ' ')
                b++;
            if(endwords[i][j] != ' ' && (endwords[i][j + 1] == ' ' || endwords[i][j + 1] == '\0'))
                c++;
            j++;
        }
        for(t = 0; t < (sizeof(endwords[0]) - 1 - b) / c; t++)
        {
            
            for(j = 0; j < sizeof(endwords[0]); j++)
            {
                if(endwords[i][j - 1] != ' ' && endwords[i][j] == ' ')
                {
                    for(n = sizeof(endwords[0]) - 2; n >= j; n--)
                    {
                        endwords[i][n] = endwords[i][n - 1];
                    }
                    endwords[i][j] = ' ';
                }
            }
        }
    }

    for(i = 0; i < 3; i++)
    {
        j = 0;
        while(endwords[i][j] != '\0')
            j++;
        printf("endwords[%d] = %s\n", i, endwords[i]);
    }
}