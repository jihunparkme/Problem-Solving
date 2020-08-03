import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1974 {

	static int N;
	static int[][] map;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());
		N = 9;

		for (int tc = 1; tc <= T; tc++) {

			// Input
			map = new int[N][N];
			for (int x = 0; x < N; x++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				for (int y = 0; y < N; y++) {
					map[x][y] = Integer.parseInt(st.nextToken());
				}
			}
			
			// 먼저 가로, 세로 확인
			if(!checkLine()) {
				System.out.println("#" + tc + " " + '0');
				continue;
			}
			
			boolean isFail = false;
			// 3x3 각 지점의 좌측상단부터 확인
			for (int x = 0; x < N; x += 3) {
				for (int y = 0; y < N; y += 3) {
					// 3x3 칸에서 실패하면
					if (!check3x3(x, y)) {
						isFail = true;
						break;
					}
				}
				// 실패하면 종료
				if (isFail) {
					System.out.println("#" + tc + " " + '0');
					break;
				}
			}
			// 3x3 실패 시
			if (isFail) continue;
			
			 System.out.println("#" + tc + " " + '1');
		}
	}

	public static boolean check3x3(int x, int y) {
		boolean ck3x3[] = new boolean[N+1];

		for (int i = x; i < x + 3; i++) {
			for (int j = y; j < y + 3; j++) {
				// 3x3 확인
				if (ck3x3[map[i][j]])
					return false;
				ck3x3[map[i][j]] = true;
			}
		}

		return true;
	}
	
	public static boolean checkLine() {
		int xx, yy;
		
		xx = 0; yy = 0;
		for (int d = 0; d < N; d++) {
			boolean ckH[] = new boolean[N+1];
			boolean ckV[] = new boolean[N+1];
			
			// 가로 확인
			for(int i=0; i<N; i++) {
				if(ckH[map[d][i]]) return false;
				ckH[map[d][i]] = true;
			}
			// 세로 확인
			for(int i=0; i<N; i++) {
				if(ckV[map[i][d]]) return false;
				ckV[map[i][d]] = true;
			}
		}
		
		return true;
	}
}
