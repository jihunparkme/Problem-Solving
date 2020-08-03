import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution1983 {

	static Integer[] store, res;
	static String[] grade = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {

			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			store = new Integer[N];
			res = new Integer[N];

			// 총점을 구하자
			for (int i = 0; i < N; i++) {
				StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
				int t1 = Integer.parseInt(st2.nextToken());
				int t2 = Integer.parseInt(st2.nextToken());
				int t3 = Integer.parseInt(st2.nextToken());

				store[i] = total(t1, t2, t3);
			}
			System.arraycopy(store, 0, res, 0, N);
			Arrays.sort(res, Comparator.reverseOrder());
			int range = N / 10; // 같은 평점을 받을 수 있는 학생 비율
			int desScore = store[K - 1]; // 찾고자하는 학생의 총점
			int desRank = 0;
			// 해당 학생이 몇 등을 했는지
			for (int i = 0; i < N; i++) {
				if (res[i] == desScore) {
					desRank = i;
					break;
				}
			}
			System.out.println("#" + tc + " " + grade[desRank / range]);
		}

	}

	private static int total(int t1, int t2, int t3) {
		return t1 * 35 + t2 * 45 + t3 * 20;
	}
}
