import java.util.Scanner;

public class Solution2805 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc=1; tc<=T; tc++) {
			int N = sc.nextInt();
			String map[] = new String[N];
			int sum = 0;
			int sp = N/2, ep = N/2;
			// Set Map
			for(int x=0; x<N; x++) {
				map[x] = sc.next();
			}
			// Find
			boolean isMid = false;
			for(int x=0; x<N; x++) {
				for(int y=sp; y<=ep; y++) {
					sum += map[x].charAt(y) - '0';
				}
				if(isMid) {
					sp++;
					ep--;
				}
				else {
					sp--;
					ep++;
				}
				
				if(sp == -1 && ep == N) {
					isMid = true;
					sp+=2;
					ep-=2;
				}
			}
			
			System.out.println("#" + tc + " " + sum);
		}
	}
}

/*

원점으로부터 거리가 N/2 인 좌표만 출력
int meR = N/2;
int meC = N/2;
..
Math.abs(meR-i) + Math.abs(meC-j) <= (N/2)
...

00 01 02
10 11 12
20 21 22



00 01 02 03 04		02		  
10 11 12 13 14		11 12 13	
20 21 22 23 24		20 21 22 23 24	
30 31 32 33 34		31 32 33
40 41 42 43 44		42
*/