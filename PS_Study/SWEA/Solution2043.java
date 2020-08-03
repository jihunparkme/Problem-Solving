import java.util.Scanner;

public class Solution2043 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int P = sc.nextInt();
		int K = sc.nextInt();
		int cnt = 1;
		
		while(true) {
			if(P == K) break;
			else {
				K++; cnt++;
			}
		}
		
		System.out.println(cnt);
	}
}
