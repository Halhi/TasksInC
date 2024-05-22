#include <stdio.h>
#include <stdlib.h>
/*
программа по расчёту лучшего дня для покупки и продажи акций
*/
int main()
{
    float bestPurch;
    float bestSale;
    float cost[8] = {4, 10, 3, 6, 2, 3, 1, 1.7};
    float money = 10;
    float differ = 0;
    int numShares = 0;
    
    if(money < 0)
    {
        printf("Negative balance\n");
        exit(0);
    }

    for(int i = 0; i < sizeof(cost) / sizeof(cost[0]); i++)
    {
        if(cost[i] <= money)
        {
            for(int j = i; j < sizeof(cost) / sizeof(cost[0]); j++)
            {
                if(cost[i] < cost[j] && (numShares = money / cost[i]) * cost[j] > differ)
                {
                    bestPurch = cost[i];
                    bestSale = cost[j];
                    differ = numShares * cost[j];
                }
            }
        }
    }
    printf("Best purchase price - %f\nBest sellinf price - %f\nBenefits of operation - %f\n", bestPurch, bestSale, differ);
}