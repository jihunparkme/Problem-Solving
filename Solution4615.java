import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution4615 {
	static int[][] board;
	static int N;

	public static void run() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		
		for(int T=0; T<tc; T++) {  // Number of test cases
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());  // a side length
			int M = Integer.parseInt(st.nextToken());  // number of times
			
			int blackCnt = 0;
			int whiteCnt = 0;
			
			board = new int[N][N];  // 1:black, 2:white
			board[N/2-1][N/2-1] = 2;  // setitng
			board[N/2][N/2-1] = 1;
			board[N/2-1][N/2] = 1;
			board[N/2][N/2] = 2;
			
			for(int i=0; i<M; i++) { // Number of times
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken())-1;  // x coordinates
				int y = Integer.parseInt(st.nextToken())-1;  // y coordinates
				int color = Integer.parseInt(st.nextToken());  // stone color
				
				board[x][y] = color;
				othello(x, y, color);
			}
			
			for(int[] tempArr : board) {
				for(int tempVal : tempArr) {
					if(tempVal == 1) blackCnt++;
					else if(tempVal == 2) whiteCnt++;
				}
			}
			System.out.println("#" + (T+1) + " " + blackCnt + " " + whiteCnt);
		}
	}
	
	public static void othello(int x, int y, int color) {
		for (int ix = -1; ix <= 1; ix++) {	// (x,y) 의 주변에 있는 돌 탐색
			for (int iy = -1; iy <= 1; iy++) { 
				if (ix == 0 && iy == 0)
					continue;

				int xx = x + ix;	// (x,y) 주변 돌 좌표
				int yy = y + iy;

				boolean check = false;	// (xx,yy)가 자신의 돌인지 체크
				while (xx >= 0 && xx < N && yy >= 0 && yy < N && board[xx][yy] != 0) {	
					if(board[xx][yy] == color) {	// (xx,yy)가 자신의 돌일 경우 
						check = true;
						break;
					}
					xx += ix;	// 상대의 돌일 경우 자신의 돌이 나올 때까지 탐색 
					yy += iy;
				}
				
				while(check) {
					if(xx == x && yy == y) break;
					board[xx][yy] = color;	// 상대 돌을 자신의 돌로 교체
					xx -= ix;
					yy -= iy;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		Solution4615.run();
	}	
}
