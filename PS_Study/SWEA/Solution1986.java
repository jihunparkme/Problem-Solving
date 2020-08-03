import java.util.Scanner;

public class Solution1986 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int i=1; i<=T; i++) {
			int N = sc.nextInt();
			int sum = 0;
			
			while(N > 0) {
				if(N % 2 == 0) sum -= N;
				else sum += N;
				
				N--;
			}
			
			System.out.println("#" + i + " " + sum);
		}
	}
}
