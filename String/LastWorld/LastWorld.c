#include <stdio.h>
#include <string.h>
/*
Задача: вывод последнего слова в предложении и его длину
*/
int main()
{
    char bid[20] = "Hello World";
    char sep[20];
    int words = 0, i = 1, j = 0;

    if(bid[0] != ' ')
    {
        words++;
        sep[0] = bid[0];
        j++;
    }
    while (bid[i] != '\0')
    {
        if(bid[i] != ' ')
        {
            if(bid[i - 1] == ' ')
            {
                words = 1;
                j = 0;
                sep[j] = bid[i];
                j++;
            }else
            {
                words++;
                sep[j] = bid[i];
                j++;
            }
        }
        i++;
    }
    printf("The last word: ");
    for(i = 0; i < words; i++)
    {
        printf("%c", sep[i]);
    }
    printf("\nWord length: %d\n", words);
    
    
}