import java.util.Scanner;

public class Solution2071 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		
		for(int i=1; i<=tc; i++) {
			double res = 0;
			
			for(int j=0; j<10; j++) {
				int n = sc.nextInt();
				res += n;
			}
			
			System.out.println("#" + i + " " + (int)(res/10+0.5));
		}		
	}
}
