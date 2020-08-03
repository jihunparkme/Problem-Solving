import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution1954 {

	static int dx[] = {0,1,0,-1};
	static int dy[] = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=T; tc++) {
			
			int N = Integer.parseInt(br.readLine());
			int[][] snail = new int[N][N];
			
			int idx = 1;
			int x = 0, y = 0;
			int d = 0;
			
			while(true) {
				// 숫자를 다 채우면 종료
				if(idx > N*N) break;
						
				snail[x][y] = idx++;
				
				// 범위를 벗어나거나 다음칸에 이미 값이 채워진 경우, 방향전환
				if(x + dx[d] < 0 || y + dy[d] < 0 || x + dx[d] >= N ||  y + dy[d]>= N || 
						snail[x + dx[d]][y + dy[d]] != 0) {
					d++;
					if(d == 4) d = 0; 
				}
				// 해당 방향으로 전진
				x += dx[d];
				y += dy[d];
			}
			
			System.out.println("#"+tc);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(snail[i][j] + " ");
				}
				System.out.println();
			}
			
		}
	}

}
