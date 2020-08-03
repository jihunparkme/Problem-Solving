import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution1208 {

	static int T = 10;
	static int N = 100; // 가로 길이는 항상 100
	static int dump;
	static int[] land = new int[N];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int tc = 1; tc <= T; tc++) {
			dump = Integer.parseInt(br.readLine());
			
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < N; i++) 
				land[i] = Integer.parseInt(st.nextToken());

			flatten(0);

			Arrays.sort(land);
			System.out.println("#" + tc + " " + (land[N - 1] - land[0]));
		}

	}

	private static void flatten(int cnt) {
		// cnt를 다 채우면 return
		if (cnt >= dump)
			return;
		// 먼저 정렬을 해주고
		Arrays.sort(land);
		land[0]++; // 최저점을 1 늘리고
		land[N - 1]--;	// 최고점을 1 줄이고
		flatten(cnt + 1);
	}

}
