import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution1288Optim {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= TC; test++) {
			int numberN = Integer.parseInt(br.readLine());
			boolean[] check = new boolean[10];
			boolean flag;
			int temp;
			int cnt = 0;
			
			do {
				cnt++;
				flag = false;
				temp = numberN * cnt;
				while (temp > 0) {
					check[temp % 10] = true;
					temp /= 10;
				}
				for (int i = 0; i < 10; i++) {
					if (!check[i]) {
						flag = true;
						break;
					}
				}
			} while (flag);
			System.out.println("#" + test + " " + numberN * cnt);
		}
	}
}