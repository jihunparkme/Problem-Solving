import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution2005 {

	static int T, N, M;
	static int nums[][];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		M = 10;
		
		for (int tc = 1; tc <= T; tc++) {
			
			N = Integer.parseInt(br.readLine());
			nums = new int[N+1][N+1];
			nums[1][1] = 1;
			System.out.println("#" + tc);
			
			for (int i = 1; i <= N; i++) {
				
				for (int j = 1; j <= i; j++) {
					System.out.print(nums[i][j] + " ");
				}
				System.out.println();
				
				if(i == N) break;
				
				for (int j = 1; j <= i+1; j++) {
					nums[i+1][j] = nums[i][j-1] + nums[i][j];
				}
			}
		}
		// 각 숫자들은 자신의 왼쪽과 오른쪽 위의 숫자의 합으로 구성
	}
}
