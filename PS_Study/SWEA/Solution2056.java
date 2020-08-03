import java.util.Scanner;

public class Solution2056 {

	static int[] endDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	public static void main(String[] args) {
		// 유효하면 ”YYYY/MM/DD”형식으로 출력,
		// 날짜가 유효하지 않을 경우, -1 을 출력
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();

		for (int i = 1; i <= tc; i++) {
			int input = sc.nextInt();
			int year = input / 10000;
			input %= 10000;
			int month = input / 100;
			input %= 100;
			int day = input;

			boolean unval = false;
			if (month < 1 || month > 12 || endDay[month] < day || day < 1)
				unval = true;

			System.out.print("#" + i + " ");
			if (unval)
				System.out.println("-1");
			else
				System.out.printf("%04d/%02d/%02d\n", year, month, day);

		}
	}

}
