#include <stdlib.h>
#include <stdio.h>
/*
Решение задачи: На кольцевом маршруте находится n заправок, где кол-во бензина на станции есть gas[i]. У машины
неогр. бензопак, поездка от станции к станции стоит cost[i]. Начинается поездка на одной из заправок с 0 баком.
Вернуть номер(а) заправки(ок), начиная с которой(ых) возможно будет проехать полный круг.
*/
int main()
{
    int gas[10] = {1,2,3,4,5,6,7,8,9,10};
    int cost[10] = {3,4,5,1,2,6,8,7,5,9};
    int n = sizeof(gas) / sizeof(gas[0]);
    int benz = 0;
    int numberStation;

    for(numberStation = 1; numberStation <= n; numberStation++)
    {
        int j = numberStation - 1;
        int c = 1;
        benz = gas[j];
        // обработка ошибок
        if(numberStation > n || numberStation <= 0)
        {
            printf("Such a station does not exit\n");
            exit(1);
        }
        for(int i = 0; i < n; i++)
        {
            if(gas[i] < 0 || cost[i] < 0)
            {
                printf("Gas or station cannot be negative");
                exit(1);
            }
        }

        // расчёт топлива на маршрут
        for(int i = 0; i < n; i++)
        {
            if(benz < cost[j])
            {
                c = 0;
            }      
            if(j < n - 1)
            {
                benz = benz - cost[j] + gas[j+1];
                j++;
            }else if(j >= n - 1)
            {
                j = 0;
                benz = benz - cost[n - 1] + gas[0];
            }
        }
        if(benz - gas[j] >= 0 && c == 1)
        {
            printf("\nStarting from station %d, you will have enough gasoline for a full circle\n\n", numberStation);
        }
    }
}