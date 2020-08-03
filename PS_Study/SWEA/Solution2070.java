import java.util.Arrays;
import java.util.Scanner;

public class Solution2070 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		
		for(int i=1; i<=tc; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();

			System.out.print("#" + i + " ");
			
			if(a > b) System.out.println(">");
			else if(a == b) System.out.println("=");
			else System.out.println("<");
		}		
	}
}
