import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1946 {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {

			int idx = 0;
			int N = Integer.parseInt(br.readLine());
			sb = new StringBuilder();
			// input
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				char alpa = st.nextToken().charAt(0);
				int cnt = Integer.parseInt(st.nextToken());

				for (int c = 0; c < cnt; c++) {
					sb.append(alpa);
					idx++;
					if (idx >= 10) {
						sb.append('\n');
						idx = 0;
					}
				}
			}
			System.out.println("#" + tc);
			System.out.println(sb);
		}
	}

}
