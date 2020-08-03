import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution1926 {

	static int N;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());

		for (int i = 1; i <= N; i++) {

			int x = i;
			boolean isPass = true;

			while (x > 0) {
				int tmp = x % 10;
				if (tmp == 3 || tmp == 6 || tmp == 9) {
					isPass = false;
					sb.append('-');
				}
				x /= 10;
			}

			if (isPass)
				sb.append(i + " ");
			else
				sb.append(" ");
		}

		System.out.println(sb);
	}

}
