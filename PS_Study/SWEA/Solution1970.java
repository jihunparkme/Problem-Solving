import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution1970 {

	static int[] money = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
	static int[] res;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= T; tc++) {

			res = new int[8];
			int N = Integer.parseInt(br.readLine());

			for (int i = 0; i < 8; i++) {
				// 낼 수 있는 돈이면 계속 내기
				while(N - money[i] >= 0) {
					N -= money[i];
					res[i]++;
				}
			}

			System.out.println("#" + tc);
			for (int i = 0; i < 8; i++) {
				System.out.print(res[i] + " ");
			}
			System.out.println();
		}

	}

}
