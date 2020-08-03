import java.util.Scanner;

public class Solution2007 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextShort();
		for(int tc=1; tc<=T; tc++) {
			String str = sc.next();
			int N = str.length();
			boolean isFind = true;
			
			// 마디의 길이 1~10
			for(int i=1; i<=10; i++) {
				isFind = true;
				
				for(int j=0; j<=N-i-1; j++) {
					if(str.charAt(j) != str.charAt(j+i)) {
						isFind = false;
						break;
					}
				}
				
				if(isFind) {
					System.out.println("#" + tc + " " + i);
					break;
				}
			}
			
		}
	}
}
