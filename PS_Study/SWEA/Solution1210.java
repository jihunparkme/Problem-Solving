import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution1210 {

	static int T, N, map[][], res;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		T = 10;
		N = 100;

		for (int tc = 1; tc <= T; tc++) {
			
			map = new int[N][N];
			ArrayList<Integer> startPointY = new ArrayList<Integer>();
			Point endPoint = null;
			int tmp = Integer.parseInt(br.readLine());
			
			// 사다리 만들기
			for (int x = 0; x < N; x++) {
				StringTokenizer st = new StringTokenizer(br.readLine(), " ");
				for (int y = 0; y < N; y++) {	
					map[x][y] = Integer.parseInt(st.nextToken());
					// 시작지점 체크
					if(x == 0 && map[x][y] == 1) startPointY.add(y);
					// 종료지점 체크
					if(map[x][y] == 2) endPoint= new Point(x, y);
				}
			}
			
			// 도착지점에서 올라오기
			int x = endPoint.x;
			int y = endPoint.y;
			int idx = startPointY.indexOf(y);
			
			// 도착점에서 먼저 한 칸 올라오고
			x -= 1;
			// 맨 위에 올라올 때까지
			while(x != 0) {
				// 좌우에 길이 있나 확인
				// 0 : 좌, 1 : 우, 2 : 길 없음
				int direction = 2;
				// 좌측에 길이 있다면
				if(y-1 >= 0 && y < N && map[x][y-1] == 1) {
					direction = 0;
					idx--;
				}
				// 우측에 길이 있다면
				if(y >= 0 && y+1 < N && map[x][y+1] == 1) {
					direction = 1;
					idx++;
				}
				// 길이 없다면
				if(direction == 2) {
					x -= 1;
					continue;
				}
				// 길이 있다면 해당 길로 이동
				y = startPointY.get(idx);
				// 해당 길에서 다시 한 칸 위로 이동
				x -= 1;
			}
			
			System.out.println("#" + tc + " " + y);
			// 아래 방향으로 진행하면서 좌우 방향으로 이동 가능한 통로가 나타나면 방향 전환
			// 방향 전환 이후엔 다시 아래 방향으로만 이동하게 되며, 바닥에 도착하면 멈추게 된다
		}

	}

}
