import java.util.Scanner;

public class Solution1959 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, j, sum, res;
		int T = sc.nextInt();
		
		for(int tc=1; tc<=T ; tc++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int Ai[] = new int[N];
			int Bj[] = new int[M];
			res = 0;
			
			// Input
			for(i=0; i<N; i++) 
				Ai[i]= sc.nextInt();
			
			for(i=0; i<M; i++) 
				Bj[i]= sc.nextInt();
			
			// set standard
			int mn = Math.min(N, M);
			int mx = Math.max(N, M);
			boolean isMinA = (mn == N) ? true : false; 
			
			// 서로 마주보는 숫자들을 곱한 뒤 모두 더할 때 최댓값
			for(i=0; i<=mx-mn; i++) {
				sum = 0;
				
				for(j=0; j<mn; j++) {
					if(isMinA)
						sum += Ai[j] * Bj[i+j];
					else
						sum += Bj[j] * Ai[i+j];
				}
				
				res = Math.max(res, sum);
			}
			
			System.out.println("#" + tc + " " + res);
		}
	} 
}
