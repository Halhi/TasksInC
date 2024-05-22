#include <stdio.h>
/*
Задача: сделать реверс предложения
*/
int main()
{
    char sentence[] = "Today is a great day to have a cup of tea";
    int i = 0, wordLen = 0, j = 0;
    char revSent[sizeof(sentence)];

    while(sentence[i] != '\0')
    {  
        while(sentence[i] != ' ')
        {  
            i++;
            wordLen++;
            if(sentence[i] == '\0')
                break;
        }
        revSent[sizeof(sentence) - i - 2] = ' ';

        for(j = 0; j < wordLen; j++)
        {
            revSent[sizeof(sentence) - 1 - i + j] = sentence[i - wordLen + j];
        }
        i++;
        wordLen = 0;
    }
    revSent[sizeof(sentence) - 1] = '\0';
    printf("Reverse:%s\n", revSent);
}