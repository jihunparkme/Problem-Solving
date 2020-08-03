import java.util.Scanner;

public class Solution2025 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int res = 0;
		
		while(n > 0)
			res += n--;
		
		System.out.println(res);
	}
}
