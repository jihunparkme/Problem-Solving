#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int a[101], tmp[101];

void divide(int lt, int rt) {
	int mid;
	int p1, p2, p3;

	// 후위 순회
	if (lt < rt) {
		mid = (lt + rt) / 2;

		/////////////////////////////
		// 분할 정복 (Divide & Conquer)
		/////////////////////////////

		// 왼쪽 자식 노드 호출
		divide(lt, mid);

		// 오르쪽 자식 노드 호출
		divide(mid + 1, rt);

		/////////////////////////////
		// 병합 (Combine)
		/////////////////////////////

		// 자식 노드 호출을 마친 뒤에야 부모 노드의 정렬 작업
		p1 = lt;
		p2 = mid + 1;
		p3 = lt;

		while (p1 <= mid && p2 <= rt) {
			if (a[p1] < a[p2]) tmp[p3++] = a[p1++];
			else tmp[p3++] = a[p2++];
		}

		// 정렬하지 않아도 되었던 나머지 원소들을 담기
		while (p1 <= mid) tmp[p3++] = a[p1++];
		while (p2 <= rt) tmp[p3++] = a[p2++];

		// tmp 에 저장된 정렬된 원소들을 원본에 복사
		for (int i = lt; i <= rt; i++)
			a[i] = tmp[i];
	}
}

int main() {
	int n, i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	divide(1, n);

	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);

	return 0;
}