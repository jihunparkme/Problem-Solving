#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int T, B, C;	// testcase, 예약 수, 청소 시간
int calendar[4][15] = { 
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// 2013
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// 2014
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// 2015
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }	// 2016(윤달)
};

struct rsv {
	long long time;
	int use;
	rsv(long long time, int use) : time(time), use(use) {}
};

long long makeMinute(int Y, int M, int D, int h, int m) {
	long long year = (Y - 2013) * 365;
	long long day = D + year;
	for (int i = 1; i < M; i++) {
		day += calendar[Y - 2013][i];
	}
	long long minute = (day * 24 * 60) + (h * 60) + m;
	return minute;
}

bool comp(const rsv& r1, const rsv& r2) {
	if (r1.time != r2.time)
		return r1.time < r2.time;
	else
		return r1.use < r2.use;
}

int main()
{
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d %d", &B, &C);
		vector<rsv> room;
		while (B--) {
			char code;
			int Y, M, D, h, m;
			scanf_s("%*s", &code);
			scanf_s("%d-%d-%d", &Y, &M, &D);
			scanf_s("%d:%d", &h, &m);
			rsv in(makeMinute(Y, M, D, h, m), 1);
			scanf_s("%d-%d-%d", &Y, &M, &D);
			scanf_s("%d:%d", &h, &m);
			rsv out(C + makeMinute(Y, M, D, h, m), 0);	// 퇴실 시 청소시간 포함
			room.push_back(in);
			room.push_back(out);
		}
		sort(room.begin(), room.end(), comp);
		long long rst = 0, used = 0;
		for(int i=0; i < room.size(); i++){
			if (room[i].use) {
				used++;
				rst = max(rst, used);
			}
			else used--;
		}
		printf("%lld\n", rst);
	}
	return 0;
}

/*
- 예약 코드는 최대 20글자, 날짜는 2013년부터 2016년 사이의 예약만
- 입력 : 테스크 케이스 \n 예약 코드, 입실 시간, 퇴실 시간
- 출력 : 필요한 방의 최소 개수(윤년에 유의), 2016년도는 윤년.

[접근]
날짜를 계산하기 위해 하나로 통일시켜주는게 좋을 듯 하다.
우선 청소 시간이 분으로 되어있으므로 날짜를 분으로 변환.
예약이 시간순으로 진행되는 것이 아니므로 시간을 정렬하는 것이 필요.
시간을 정렬하는데 입-퇴실을 분류해야하므로 구조체를 사용.
구조체를 vector에 쌓고 정렬.
정렬된 vector를 순차적으로 접근하면서 입실일 경우 증가, 퇴실할 경우 감소.

[시도]
1. 우선 날짜를 분으로 변환하고,
분으로 변환된 모든 날짜(퇴실일 경우 청소 시간 추가)와 방의 입-퇴실 여부를 구조체로 만들어 벡터에 저장.

2. 벡터에 저장된 시간을 정렬,
정렬 시 시간이 같을 경우는 입실이 먼저 나오게 정렬하고, 다를 경우는 분이 작은 순서로 정렬

3. 정렬된 벡터를 순차적으로 접근. 입-퇴실 여부를 확인하면서 입실했을 경우 used를 증가시켜주고,
퇴실했을 경우 used를 감소. used는 결국 0을 결과로 보이므로, 임의 변수에 max used를 저장

[배운점]
날짜를 time.h 라이브러리를 사용해서 분으로 변환하려고 했는데
scanf에서 형식지정자에 문자형식을 넣어주면 입력한 날짜 형식에서 숫자만 얻을 수 있다는 것을 구글링하다 생각났다.

sort함수는 세 번째 인자에 함수를 넣을 수 있는데, 이 함수가 판단한 "a가 b보다 앞에 올 조건"에 따라서 구간을 재배열 한다.
이것은 입실 시간과 퇴실 시간이 같을 경우를 정렬할 때, 분과 입-퇴실에 따라 정렬해주어야 하는데, 이 경우에 유용했다.
*/