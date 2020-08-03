import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BOJ14888 {

	// 덧셈, 뺄셈, 곱셈, 나눗셈
	static int[] operation, nums, visit;
	static int N, resMax, resMin;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		N = Integer.parseInt(br.readLine());
		nums = new int[N];
		visit = new int[4];
		operation = new int[4];
		// An 입력
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < N; i++) 
			nums[i] = Integer.parseInt(st.nextToken());
		// 연산자 개수 입력
		StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < 4; i++) 
			operation[i] = Integer.parseInt(st2.nextToken());
		
		resMax = -987654321;
		resMin = 987654321;
		// 주어진 수의 순서를 바꾸면 안돼
		// 연산자 우선순위를 무시하고 앞에서 부터 진행
		process(1, nums[0]);
		
		// 최대인 것과 최소인 것
		bw.write(resMax + "\n" + resMin);
		bw.flush();
		
		br.close();
		bw.close();
	}

	public static void process(int idx, int sum) {
		// 주어진 수의 연산을 완료했을 때,
		if(idx == N) {
			resMax = Math.max(resMax, sum);
			resMin = Math.min(resMin, sum);
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			// 입력받은 연산자가 있고, 사용되지 않은 연산자를 사용해보자
			if(operation[i] != 0 && visit[i] != operation[i]) {
				// 이 연산자를 지금 사용할래!
				visit[i]++;
				// 0:덧셈, 1:뺄셈, 2:곱셈, 3:나눗셈
				// 연산자를 사용하지 않을 경우 sum 연산자를 그대로 넘겨줘야하기 때문에 tmp 변수 사용
				int sumTmp = sum;
				if(i==0) sumTmp += nums[idx];
				else if(i==1) sumTmp -= nums[idx];
				else if(i==2) sumTmp *= nums[idx];
				else {
					// 나눗셈은 정수 나눗셈으로 몫만
					if(sumTmp >= 0) sumTmp /= nums[idx];
					else {
						// 음수를 양수로 나눌 때는 음수를 양수로 바꾼 뒤 몫을 취하고 음수로 바꿔
						sumTmp *= -1;
						sumTmp /= nums[idx];
						sumTmp *= -1;
					}
					
				}		
				process(idx + 1, sumTmp);
				// 이 연산자를 지금 사용 안함
				visit[i]--;
			}
		}
	}
	
}
