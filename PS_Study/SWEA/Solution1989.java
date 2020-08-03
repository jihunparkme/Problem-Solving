import java.util.Scanner;

public class Solution1989 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int N;
		boolean isSame;
		
		for(int tc=1; tc<=T; tc++) {
			String str = sc.next();
			N = str.length();
			
			isSame = true;
			for(int i=0; i<N; i++) {
				if(str.charAt(i) != str.charAt(N-1-i)) {
					isSame = false;
					break;
				}
			}
			
			if(isSame) 
				System.out.println("#" + tc + " " + "1");
			else
				System.out.println("#" + tc + " " + "0");
		}
	}
}