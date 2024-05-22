#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/*
Задача: Определить, является ли предложение палиндромом(считаются только буквы)
*/
void boor();

int main()
{
    char sent[] = "A man, a plan, a canal: Panama";
    char tempSent[sizeof(sent)];
    int j = 0;
    
    for(int i = 0; i < sizeof(sent); i++)
    {
        sent[i] = tolower(sent[i]);
        if(sent[i] >= 97 && sent[i] <= 122)
        {
            tempSent[j] = sent[i];
            //printf("tempSent[%d]: %c\n", j, tempSent[j]);
            j++;
        }
    }
    boor(tempSent, tempSent);
}

void boor(char *a, char *b)
{
    int n = 0, c = 0;

    while(*b != '\0')
    {
        printf("b = %c\n", *b);
        b++;
        n++;
    }
    b--;
    while (c != (n / 2))
    {
        if(*b == *a)
        {
            b--;
            a++;
        }else
        {
            printf("The sentence is not a palindrome");
            break;
        }
        c++;
    }
    if(c == (n / 2))
        printf("The sentence is a palindrome");
}