import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1874 {
	
	static int N;
	static int[] nums;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		nums = new int[N];
		for (int i = 0; i < N; i++) 
			nums[i] = Integer.parseInt(br.readLine()); 
		
		int[] stack = new int[N];
		int top = -1;
		int idx = 0;
		for (int i = 1; i <= N; i++) {
			// 일단 push
			stack[++top] = i;
			sb.append("+" + "\n");
			// 입력된 수열의 idx번째 수와 stack의 peek가 같다면 pop
			while(nums[idx] == stack[top]) {
				sb.append("-" + "\n");
				top--;
				idx++;
				if(top < 0 || idx > N) break;
			}
		}
		if(top == -1 && idx == N) 	
			System.out.println(sb);
		else {
			System.out.println("NO");
		}
			
		br.close();
	}
	
}
