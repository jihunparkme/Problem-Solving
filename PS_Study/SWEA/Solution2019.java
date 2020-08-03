import java.util.Scanner;

public class Solution2019 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int res = 1;
		
		for(int i=1; i<=n+1; i++) {
			System.out.print(res + " ");
			res *= 2;
		}
		
	}
}
