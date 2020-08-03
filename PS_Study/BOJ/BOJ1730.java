import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1730 {

	// 수직과 수평 방향을 따로 지정
	static int[][] vertical, horizontal;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int i, j, N;
		
		// 목판에는 n행 n열의 격자모양
		N = Integer.parseInt(br.readLine());
		// 목판 초기화
		vertical = new int[N][N];
		horizontal = new int[N][N];
		// 움직임 
		char motions[] = br.readLine().toCharArray();
		
		// 처음 로봇의 조각도를 올려놓는 위치는 맨 왼쪽 맨 위의 꼭짓점
		int x = 0, y = 0;
		for (i = 0; i < motions.length; i++) {
			int xx = x, yy = y;
			char motion = motions[i];
			//  위쪽 'U', 아래쪽 'D', 왼쪽'L', 오른쪽'R'
			// 작동 도중 로봇 팔이 격자 바깥으로 나가면 무시하고 그 다음 명령을 진행
			if (motion == 'U') {
				xx--;
				if(xx < 0) continue;
				vertical[xx][yy] = vertical[x][y] = 1;
				x = xx;
			}
			else if (motion == 'D') {
				xx++;
				if(xx >= N) continue;
				vertical[xx][yy] = vertical[x][y] = 1;
				x = xx;
			}
			else if (motion == 'L') {
				yy--;
				if(yy < 0) continue;
				horizontal[xx][yy] = horizontal[x][y] = 1;
				y = yy;
			}
			else if (motion == 'R') {
				yy++;
				if(yy >= N) continue;
				horizontal[xx][yy] = horizontal[x][y] = 1;
				y = yy;
			}
		}
		
		// 로봇팔이 지나지 않은 점은 '.'으로, 로봇팔이 수직 방향으로만 지난 점은 '|'으로, 
		// 로봇팔이 수평 방향으로만 지난 점은 '-'으로, 수직과 수평 방향 모두로 지난 점은 '+'로 표기
		// . : 46,  | : 124,  - " 45,  + : 43
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				// 수직과 수평 방향 모두로 지난 점
				if(vertical[i][j]+horizontal[i][j] > 1) 
					System.out.print('+');
				else {
					if(vertical[i][j] == 1) System.out.print('|');
					else if(horizontal[i][j] == 1) System.out.print('-');
					else System.out.print('.');
				}
			}
			System.out.println();
		}

	}

}
