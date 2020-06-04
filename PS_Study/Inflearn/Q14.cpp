#include<stdio.h>

using namespace std;

int reverse(int &x)
{
    int tmp = 0;

    while (x)
    {
        tmp = tmp * 10 + (x % 10);
        x /= 10;
    }

    return tmp;
}

bool isPrime(int &x)
{
    if (x == 1)
        return false;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main() {
    freopen("input.txt", "rt", stdin);
    int n, num, i, isPrm;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);

        num = reverse(num);

        isPrm = isPrime(num);

        if (isPrm)
            printf("%d ", num);
    }

    puts("");

    return 0;
}
