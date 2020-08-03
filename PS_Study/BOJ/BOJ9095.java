import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class BOJ9095 {

	static int T, N;
	static Set<Integer> setNum;	// 121, 121 중복을 제외시키기 위해 Set 사용
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());

		for (int i = 1; i <= T; i++) {
			
			setNum = new HashSet<Integer>();
			N = Integer.parseInt(br.readLine());
			
			process(0, 0);
			
			System.out.println(setNum.size());
		}
	}

	public static void process(int sum, int num) {
		if(sum > N) return;
		if(sum == N) {
			setNum.add(num);
			return;
		}
		// n을 1, 2, 3의 합으로 나타내는 방법의 수
		for (int i = 1; i <= 3; i++) {
			process(sum + i, num * 10 + i);
		}
	}
	
}
