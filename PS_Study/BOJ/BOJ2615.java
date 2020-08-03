import java.util.Scanner;

public class BOJ2615 {

	static int board[][];
	static int N = 19;
	static int dx[] = {0, 1, 1, 1};
	static int dy[] = {1, 1, 0, -1};
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int i = 0, j = 0, d = 0, winner = 0;
		// 바둑판은 19x19 (idx 1부터)
		board = new int[25][25];
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				board[i][j] = sc.nextInt();
			}
		}
		// 오목을 발견했는가
		boolean isFind = false;
		for(i=1; i<=N; i++) {
			for(j=1; j<=N; j++) {
				if(board[i][j] == 0) continue;
				// 해당 좌표의 돌이 1 또는 2일 경우
				int rock = board[i][j];
				// 주변에 같은 색 돌이 있는지 확인
				for(d=0; d<4; d++) {
					int xx = i + dx[d];
					int yy = j + dy[d];
					// 주변이 다른 색이거나, 범위를 벗어날 경우 pass
					if(board[xx][yy] != rock) continue;
					if(xx < 1 || yy < 1 || xx > N || yy > N) continue;
					// 주변이 같은 색일 경우, 몇 개가 있는지 확인
					// 이 단계에서는 2개째 카운트된 상황
					int cnt = 2;
					while(true) {
						xx += dx[d];
						yy += dy[d];
						// 탐색 도중 다른 색이 나오거나, 범위를 벗어날 경우 break
						if(board[xx][yy] != rock) break;
						if(xx < 1 || yy < 1 || xx > N || yy > N) break;
						// 그렇지 않을 경우 카운트
						cnt++;
					}
					// 바둑알이 연속적으로 다섯 알 놓이면 그 색이 승리
					// 바둑알이 여섯 알 이상 연속적으로 놓인 경우 이긴게 아님.
					// cnt == 5 이지만 이전에 방향에 자신과 같은 돌이 있다면 pass (놓쳤던 부분..)
					if(cnt == 5 && board[i-dx[d]][j-dy[d]] != rock) {
						isFind = true;
						winner = rock;
						break;
					}
				}
				if(isFind) break;
			}
			if(isFind) break;
		}
		
		// 아직 승부가 결정되지 않았을 경우
		if(!isFind) System.out.println('0');
		else {
			if(d == 3) {
				// 연속된 다섯 개의 바둑알 중에서 가장 왼쪽에 있는 바둑알
				// (연속된 다섯 개의 바둑알이 세로로 놓인 경우, 그 중 가장 위에 있는 것)
				System.out.printf("%d\n%d %d\n", winner, i+4, j-4);
			}
			else 
				System.out.printf("%d\n%d %d\n", winner, i, j);
		}
		
	}

}
// 1: 검은색, 2: 흰색