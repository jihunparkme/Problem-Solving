import java.util.Scanner;

public class Solution1936 {
	public static void main(String[] args) {
		Scanner sc = new Scanner((System.in));
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		if(a == 1 && b == 3 ||
				a == 2 && b == 1 ||
				a == 3 && b == 2) {
			System.out.println("A");
		}
		else 
			System.out.println("B");
	}
}
