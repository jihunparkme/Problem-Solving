import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class BOJ2164_v3 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		// 1. N과 가장 가까운 2의 제곱수를 찾기
		// 2. N - (그 제곱수) * 2 가 답
		
		int n = 1;
		while(n < N) {
			n *= 2;
		}
		// 여기서 n은 N보다 큰 2의 제곱수
		n /= 2;
		if(N == 1) 
			System.out.println(1);
		else
			System.out.println((N-n) * 2);
	}

}
