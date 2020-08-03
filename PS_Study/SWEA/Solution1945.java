import java.util.Scanner;

public class Solution1945 {

	static int[] lst = { 2, 3, 5, 7, 11 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int tc = sc.nextInt();

		for (int i = 1; i <= tc; i++) {

			int n = sc.nextInt();
			int[] cnt = new int[15];

			for (int j = 0; j < 5; j++) {
				while (n % lst[j] == 0) {
					n /= lst[j];
					cnt[lst[j]]++;
				}
			}

			System.out.print("#" + i + " ");
			for (int j = 0; j < 5; j++)
				System.out.print(cnt[lst[j]] + " ");
			System.out.println();
		}

	}
}
