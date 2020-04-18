#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef unsigned long long ll;

ll N, M;
int K, mm;  // 방법의 수, 방법
const int tempMax = 2100;
int method[23];  // 방법 (1~22)
int winner[tempMax + 1];  // 게임의 승패 결과

						  // 패턴 길이 확인 function
int findCycleLength()
{
	int cycleSize = 0;
	for (int cs = 1; ; cs++)
	{   // 패턴의 길이가 1인 경우부터 확인
		bool flag = true;
		for (int i = 1; i + cs <= tempMax; i++)
		{   // a[i] ~ a[n + i]
			if (winner[i] != winner[i + cs])
			{
				flag = false;
				break;
			}
		}
		// 패턴을 찾았을 경우 멈추고 길이 반환
		if (flag) { cycleSize = cs; break; }
	}
	return cycleSize;
}

int main(void)
{
	scanf("%lld", &M);
	scanf("%d", &K);

	memset(winner, -1, sizeof(winner));

	// 1. 가져갈 수 있는 돌의 개수 저장
	for (int i = 1; i <= K; i++)
	{
		scanf("%d", &mm);
		method[i] = mm;
		// 가져갈 수 있는 돌의 개수와 같은 N 은 무조건 선수가 승리(상근), 0
		winner[mm] = 0;
	}

	// 2. 배열에 승패 결과를 배열에 저장 (적당한 size 로 결과를 구해놓기)
	for (int n = 1; n <= tempMax; n++)
	{
		if (winner[n] != -1) continue;

		int sum = 0;
		// ex. N-1, N-3, N-4 의 각 결과의 합이 모두 상근의 승리로 '0'일 때, N 의 결과는 창영의 승리로 '1'이 될 수 있음.
		for (int w = 1; w <= K; w++)
		{
			int metd = method[w];
			if (n - metd > 0 && winner[n - metd] != -1)
			{
				sum += winner[n - metd];
			}
		}
		if (sum == 0) winner[n] = 1;
		else winner[n] = 0;
	}

	// 3. 배열 앞에서부터 패턴을 찾고 패턴의 길이를 확인
	int cycleSize = findCycleLength();

	// 4. 패턴에 1 이 몇 번 등장하는지 확인
	int cntOne = 0;
	for (int i = 1; i <= cycleSize; i++)
		if (winner[i]) cntOne++;

	// 5. M 에 사이클이 총 몇 번 나오는지 확인
	ll cntCycle = M / cycleSize;

	// 6. 사이클 뒤에 있는 1 의 개수
	int restCycle = 0;
	for (ll i = cntCycle * cycleSize + 1; i <= M; i++)
		if (winner[i % cycleSize]) restCycle++;

	printf("%lld\n", cntCycle * cntOne + restCycle);
}


/*
[ 재정의 및 추상화 ]
- 창영이가 이기는 N 의 개수.
- 돌을 올바른 개수만큼 가져갈 수 있는 방법이 없는 사람이 게임에서 지게 됨.
- 창영이가 이기는 N 중에서 창영이가 이기는 N 의 개수를 출력한다. (1 ≤ N ≤ M)

* 창영이가 이기는 돌 개수 : N
* M
* 방법의 수 : K (1 ≤ K ≤ 22)
* (1 ≤ N ≤ M)


[ 계획 및 시도 ]
상근이가 먼저 시작

input
--------
20
3
1 2 3
--------
N 은 1, 2 ... 20 (창영이가 이기는 N 이 몇 개인지 count), 상근 : 0, 창영 : 1
N = 1, 0
N = 2, 0
N = 3, 0
N = 4, 1
N = 5, 0
N = 6, 0
N = 7, 0
N = 8, 1
...
4의 배수에서 창영이가 승리.

1. 가져갈 수 있는 돌의 개수와 같은 N 은 무조건 선수가 승리(상근), 0

2. 배열에 승패 결과를 배열에 저장(어느정도까지 결과를 구하기) - 이전 승자를 확인
- 가져갈 수 있는 돌의 개수만큼 뺀 결과가,
ex, 만일 N-1, N-3, N-4 의 각 결과의 합이 모두 상근의 승리로 '0'일 때, N 의 결과는 창영의 승리로 '1'이 될 수 있음.
여기서, 1이 포함되어있으면 창영은 승리할 수 없음.

3. 배열의 앞에서부터 패턴을 찾고 패턴의 길이를 확인
- a[i] ~ a[n + i] 를 비교하면서 cycle 을 찾아내기 (패턴을 비교하는 함수), tempMax 까지 cycleSize 만큼 계속 비교한 결과가 true 라면 해당 cycleSize 를 return
- 패턴을 찾는 방법은 3가지
앞에서부터 찾는 경우, a[i] ~ a[n], a[n+1] ~ a[2n]
=> 앞에서 패턴이 나오지 않는 000001010101 이러한 경우를 예외 상황으로 처리해줘야 할듯 하다...
뒤에서부터 찾는 경우, a[max] ~ a[max-n], a[max-n-1] ~ a[max-2n+1] => 패턴이 중간에 위치한 경우, 앞, 뒤에 1 을 더 확인해 줘야함.
중간에서 찾는 경우. a[idx + 1] ~ a[idx + n], a[idx + n + 1] ~ a[idx + 2n] => 뒤에서부터 찾는 경우와 동일.

20
3
1 2 3
=> 5
0001 0001 0001 ...

20
3
1 3 4
=> 5
0100001 0100001 0100001 ...

20
3
1 3 5
=> 10
01 01 01 01 ...

20
3
2 6 9
=> 9
100110010001001 100110010001001 ...

- XXX. 뒤에서부터 첫 번째 1의 위치를 찾고, 그 다음 1의 전 위치 찾는다. (배열을 이동할 때마다 cycleCount 를 증가), 패턴을 만들어갈 때마다 패턴 안의 1은 1씩 증가
- XXX. cycleCount 만큼 더 갔을 때, 1의 개수가 패턴 안의 1 개수와 같다면 패턴을 찾은 것이다. (이건 패턴을 확인하는 checkCycle 함수가 필요할 듯)
- XXX. 패턴을 못 찾았을 경우, 그 다음 1의 전 위치를 찾는다.(바로 앞에 1은 제외)(패턴을 못 찾을 때마다 패턴 안에 1의 개수는 계속 늘어남)
- XXX. 패턴을 배열 뒤에서부터 찾으니까 예외 상황으로 패턴이 중간에 있을 경우가 생겨버림..

4. 패턴 안에 1의 개수를 세고, 패턴이 몇 번 나오는지 확인.
-> 단, 패턴 밖에 있는 1 (앞, 뒷 부분)도 나중에 세줘야 할듯
-> 앞에서부터 패턴이 시작되는 위치를 찾는다. 앞에서의 패턴과 동일한 위치를 찾으면 해당 위치부터의 사이클 개수와 그 뒤, 앞 을 다시 확인

XXX. 돌의 개수 사이에 있는 N 은 다 0 ?!
XXX. 시작하자마자 상근이가 지는 경우도 생각해야 함.

[ 배운점 ]
*/