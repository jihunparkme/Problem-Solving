import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution2046 {
	public void run() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++) {
			sb.append('#');
		}
		System.out.println(sb);
	}
	
	public static void main(String[] args) throws Exception {
		new Solution2046().run();
	}
}