import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2840 {

	static int idx = 0;
	static boolean alpa[] = new boolean[26];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		char wheel[] = new char[N];
		// 빈칸은 ? 로 초기화
		Arrays.fill(wheel, '?');

		for (int i = 0; i < K; i++) {
			StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
			// N의 배수는 한 바퀴를 도는 것므로 % N 으로 처리
			int change = Integer.parseInt(st2.nextToken()) % N;
			char chr = st2.nextToken().charAt(0);

			// 바퀴 돌리기
			idx -= change;
			if (idx < 0)
				idx += N;

			// 해당 위치가 비어있는데
			if (wheel[idx] == '?') {
				// 이미 사용된 글자가 아니라면 해당 위치에 글자를 저장
				if (!alpa[chr - 'A']) {
					wheel[idx] = chr;
					alpa[chr - 'A'] = true;
					continue;
				}
				// 중복된 단어가 저장될 경우 종료
				System.out.println("!");
				return;
			} else {	// 해당 위치에 글자가 이미 있는데
				// 같은 단어일 경우
				// 회전시켜서 저장했던 글자가 다시 나온 경우이므로 pass
				if (wheel[idx] == chr)
					continue;
				// 다른 글자가 덮어쓰려고 할 경우 종료
				System.out.println("!");
				return;
			}
		}

		// 글자를 알 수 있는 경우 시계방향으로 출력
		for (int i = 0; i < N; i++) {
			System.out.print(wheel[idx++]);
			if (idx > N - 1)
				idx -= N;
		}
	}

}