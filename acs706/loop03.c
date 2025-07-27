#include <stdio.h>
int main()
{
    int total, i, j;
    scanf("%d", &total);

    for (i = 2; i <= total; i++)
    {
        int prime = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime == 1)
            printf("%d ", i);
    }
    return 0;
}