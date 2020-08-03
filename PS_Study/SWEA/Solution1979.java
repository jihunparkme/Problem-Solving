import java.util.Scanner;

public class Solution1979 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc=1; tc<=T; tc++) {
			int N = sc.nextInt();
			int K = sc.nextInt();
			int map[][] = new int[N][N];
			int check = 0;
			int res = 0;
			
			// Input
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			
			// Find
			for(int x=0; x<N; x++) {
				for(int y=0; y<N; y++) {
					if(map[x][y] == 0) continue;
					
					// 가로 시작
					if(y == 0 || map[x][y-1] == 0) {
						int yy = y;
						check = 0;
						
						while(yy<N) {
							if(yy == N || map[x][yy] == 0) break;
							if(map[x][yy] == 1) {
								check++;
							}
							yy += 1;
						}
						
						if(check == K) res++;
					}
					
					// 세로 시작
					if(x == 0 || map[x-1][y] == 0) {
						int xx = x;
						check = 0;
						
						while(xx<N) {
							if(xx == N || map[xx][y] == 0) break;
							if(map[xx][y] == 1) {
								check++;
							}
							xx += 1;
						}
						
						if(check == K) res++;
					}
				}
			}
			
			System.out.println("#" + tc + " " + res);	
		}
	}
}

// 특정 길이 K를 갖는 단어가 들어갈 수 있는 자리의 수
// 빈칸 부분은 1, 벽 부분은 0 