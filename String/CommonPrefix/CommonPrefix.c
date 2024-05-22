#include <stdio.h>
#include <ctype.h>
/*
Задача: поиск самой длинной строки общего префикса среди массива слов
*/
int main()
{
    char arrWords[3][20] = {"Galaxy", "gamma", "Gac"};
    int prefLen = 0, temp = 0, excep = 0;

    for(int i = 0; i < sizeof(arrWords[0]); i++)
        for(int j = 0; j < sizeof(arrWords) / sizeof(arrWords[0]); j++ )
        {
            arrWords[j][i] = toupper(arrWords[j][i]);
            //printf("arrWords[%d][%d] = %c\n", j, i, arrWords[j][i]);
        }
    
    for(int i = 0; i < sizeof(arrWords[0]); i++)
    {
        if(excep)
            break;
        for(int j = 1; j < sizeof(arrWords) / sizeof(arrWords[0]); j++ )
        {   
            if(arrWords[0][i] == arrWords [j][i] && arrWords[0][i] != '\0')
            {
                temp++;
                if(temp == (sizeof(arrWords) / sizeof(arrWords[0])) - 1)
                {
                    prefLen++;
                    temp = 0;
                }      
            }
            if(arrWords[0][i] != arrWords [j][i])
            {
                excep = 1;
                break;
            }  
        }  
    }
    
    
    printf("prefex length = %d\nLongest common prefix - ", prefLen);
    if(prefLen != 0)
        for(int i =0; i < prefLen; i++)
            printf("%c", arrWords[0][i]);
    else
        printf("missing");
}