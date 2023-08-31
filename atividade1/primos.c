#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);

    if (is_prime(num))
    {
        printf("1 - O numero %d e prime. \n", num);
    }
    else
    {
        printf("0 - O numero %d nao e primo. \n", num);
    }
    return 0;
}