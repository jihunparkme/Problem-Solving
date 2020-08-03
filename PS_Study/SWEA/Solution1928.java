import java.util.Base64;
import java.util.Scanner;

public class Solution1928 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			String str = sc.next();
			String res = new String(Base64.getDecoder().decode(str));
			
			System.out.println("#" + tc + " " + res);
		}
	}

}
