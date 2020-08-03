import java.util.Arrays;
import java.util.Scanner;

public class Solution2072 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		
		for(int i=1; i<=tc; i++) {
			int res = 0;
			
			for(int j=0; j<10; j++) {
				int n = sc.nextInt();
				if(n%2 == 1) res += n;
			}
			
			System.out.println("#" + i + " " + res);
		}		
	}
}
