import java.util.Scanner;

public class Solution4615_2 {
	// 시계방향
	static int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int M = sc.nextInt(); // 돌을 놓는 횟수
			int board[][] = new int[N + 1][N + 1];
			// 초기 세팅
			board[N / 2][N / 2] = 2;
			board[N / 2 + 1][N / 2 + 1] = 2;
			board[N / 2 + 1][N / 2] = 1;
			board[N / 2][N / 2 + 1] = 1;

//			for (int tst = 0; tst <= N; tst++) {
//				System.out.println(Arrays.toString(board[tst]));
//			}
//			System.out.println("\n\n");
			
			for (int i = 0; i < M; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				int rock = sc.nextInt();

				board[x][y] = rock;
				for (int d = 0; d < 8; d++) {
					int xx = x + dx[d];
					int yy = y + dy[d];
					// 범위를 벗어나거나, 주변이 0 or 같은 돌이면 pass
					if (xx < 1 || yy < 1 || xx > N || yy > N) continue;
					if (board[xx][yy] == 0 || board[xx][yy] == rock) continue;
					// 주변이 다른 돌이면, 그 방향으로 같은 돌이 위치하는지 확인
					boolean existSame = false;
					while(true) {
						xx += dx[d];
						yy += dy[d];
						if(xx > N || yy > N || xx < 1 || yy < 1) break;
						if(board[xx][yy] == 0) break;
						if(board[xx][yy] == rock) {
							existSame = true;
							break;
						}
					}
					// 그 방향에 같은 돌이 있다면 사이에 있는 상대돌을 내꺼로
					while(existSame) {
						xx -= dx[d];
						yy -= dy[d];
						board[xx][yy] = rock;
						
						if(xx == x && yy == y) break;
					}
				}
				
//				for (int tst = 0; tst <= N; tst++) {
//					System.out.println(Arrays.toString(board[tst]));
//				}
//				System.out.println("\n\n");
			}
			
			int cntB = 0, cntW = 0;
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(board[i][j] == 1) cntB++;
					else if(board[i][j] == 2) cntW++;
				}
			}

			System.out.println("#" + tc + " " + cntB + " " + cntW);
		}

	}

}
// 1: 흑돌, 2: 백돌