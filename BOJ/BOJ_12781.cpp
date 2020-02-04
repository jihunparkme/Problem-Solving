#include <iostream>

using namespace std;

int p[8];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int s = ((x2 - x1)*(y3 - y1)) - ((y2 - y1)*(x3 - x1));
	if (s == 0) return 0;
	return (s > 0 ? 1 : -1);
}

int isIntersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int ab = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);	// vector A-B 기준
	int cd = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);	// vector C-D 기준
	return ab < 0 && cd < 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// Input point
	for (int i = 0; i < 8; i++) {
		cin >> p[i];
	}

	cout << isIntersection(p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]) << '\n';
}

/*
CCW(C, D, A)와 CCW(C, D, B)의 곱이 음수면 그 직선이 교차
- 한 선분의 벡터를 기준으로, 다른 선분의 두 점들이 같은 회전뱡향에 있는지, 다른 회전방향에 있는지 검사
- 두 선분에 대해 이러한 판단을 수행하여 모두 만족하면 교차하는 것
- CCW의 공식은 (x2-x1)(y3-y1) - (y2-y1)(x3-x1)
*/

/* 
[접근] 우선 피자를 4등분하려면 두 직선이 교차를 해야 한다는 것을 알아냈습니다.
여기서 두 직선이 교차하는지 판별하는 식이 필요했고, 구글에 "두 직선 교차", "두 선분 교차"라고 검색을 해본 결과
CCW 알고리즘과 벡터의 외적(벡터곱)에 대한 개념을 접하게 되었습니다.

[시도] 유사한 이론을 가지고 있는 "CCW 알고리즘&벡터의 외적"을 활용하여 선분 교차 판별을 시도하였습니다.

[배운점] CCW 알고리즘과 벡터의 외적을 활용하여 선분 교차 여부를 쉽게 판별할 수 있습니다.
CCW는 보통 세 가지의 return값을 가지는데
1. 반시계 방향인 경우(return 1), S > 0
2. 시계 방향인 경우(return -1), S < 0
3. 세 점이 평행한 경우(return 0), S = 0
으로 분류됩니다.

CCW는 삼각형의 면적을 구하는 공식+벡터를 이용하여 구해지게 되고
S = (x2-x1)(y3-y1) - (y2-y1)(x3-x1), S의 결과에 따라 위 세 가지의 값을 return하게 됩니다.

여기서, 한 선분의 벡터를 기준으로, 다른 선분의 두 점들이 같은 회전뱡향에 있는지, 다른 회전방향에 있는지 검사가 필요합니다. 
만일, 다른 방향에 있다면, 두 선분이 교차한다고 할 수 있습니다.
그렇게 되기 위해서 한 선분 벡터 기준(A-B)으로, 다른 선분의 두 점들(C, D)의 곱이 음수가 되어야 합니다.
(다른 회전방향 = 반시계 방향(1) X 시계 방향(-1)

단, 서로 다른 방향을 나타내는데에도 불구하고 두 선분이 서로 교차하지 않는 경우를 확인하기 위하여
두 선분(A-B, C-D)에 대해 이러한 판단을 수행하여 모두 만족하면 교차한다라고 판별할 수 있습니다.
*/