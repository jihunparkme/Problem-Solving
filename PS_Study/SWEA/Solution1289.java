import java.util.Scanner;

public class Solution1289 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			String mem = sc.next();
			int memArr[] = new int[mem.length()];
			// 초기 메모리를 0
			for (int i = 0; i < mem.length(); i++)
				memArr[i] = 0;

			int cnt = 0;
			boolean isFinish = false;
			for (int i = 0; i < mem.length(); i++) {
				// 검색 위치가 다르다면
				if (memArr[i] != mem.charAt(i) - '0') {
					for (int j = i; j < mem.length(); j++) {
						memArr[j] = mem.charAt(i) - '0';
					}

					cnt++;
				}
			}

			System.out.println("#" + tc + " " + cnt);
		}
	}

}
