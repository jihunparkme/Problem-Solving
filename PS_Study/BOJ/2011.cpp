#include <cstdio>
#include <string.h>
#define mod 1000000
using namespace std;

int DP[5001];
char A[5001] = { ' ', };

int main(void)
{
	int i;
	//freopen("input.txt", "rt", stdin);
	scanf("%s", A + 1);
	if (A[1] == '0') {
		printf("0\n");
		return 0;
	}
	
	DP[0] = DP[1] = 1;
	for (i = 2; i < strlen(A); i++) {
		if(A[i] != '0')
			DP[i] += DP[i - 1] % mod;
		
		if (A[i - 1] == '1' || A[i - 1] == '2' && A[i] <= '6')
			DP[i] += DP[i - 2] % mod;
	}

	printf("%d\n", DP[strlen(A) - 1] % mod);

	return 0;
}