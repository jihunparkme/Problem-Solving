#include<stdio.h>

using namespace std;

int n[10];
char a[100];

int main() {
    freopen("input.txt", "rt", stdin);
    int i, max = 0;

    scanf("%s", &a);

    for (i = 0; a[i] != '\0'; i++)
        n[a[i] - 48]++;

    for (i = 1; i < 10; i++)
    {
        if (n[max] < n[i])
            max = i;
        else if (n[max] == n[i])
            max = max > i ? max : i;
    }

    printf("%d\n", max);

    return 0;
}
