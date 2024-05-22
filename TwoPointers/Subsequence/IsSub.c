#include <stdio.h>
/*
Задача: Определить, является ли одна строка подпоследовательностью другой строки ("ace" подпослед. abcde)
*/
void subSeq();

int main()
{
    char line[] = "abcde";
    char subline[] = "ace";

    subSeq(line, subline);
    
/*
    while (line[i] != '\0')
    {
        if(line[i] == subline[j])
        {
            j++;
        }
        i++;
    }
    if(j == sizeof(subline) - 1)
        printf("String is a sub-sequence of another string\n");
    else
        printf("String is not a sub-sequence of another string\n");
*/
}

void subSeq(char *a, char *b)
{
    while(*a != '\0')
    {
        if(*a == *b)
            b++;
        a++;
    }
    if(*b == '\0')
        printf("String is a sub-sequence of another string\n");
    else
        printf("String is not a sub-sequence of another string\n");
}