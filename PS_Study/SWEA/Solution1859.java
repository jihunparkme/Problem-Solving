import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1859 {

	static int T, N, maxPrice;
	static long res, sum;
	static int price[];
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			
			N = Integer.parseInt(br.readLine());
			price = new int[N];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < N; i++) 
				price[i] = Integer.parseInt(st.nextToken());
			
			sum = 0; res = 0; maxPrice = 0;
			for (int i = N-1; i >= 0; i--) {
				// 내 앞에 더 높은 가격이 있을 경우, 그 각격을 maxPrice로 설정
				if(maxPrice < price[i]) {
					maxPrice = price[i];
					res = Math.max(res, sum);
					continue;
				}
				// maxPrice보다 작은 가격과의 차를 누적
				sum += maxPrice - price[i];
			}
				
			System.out.println("#" + tc + " " + Math.max(res, sum));
		}
		
	}

}
