import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution3431 {
	
	static int T, info[];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			
			info = new int[3];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < 3; i++) 
				info[i] = Integer.parseInt(st.nextToken());
			
			bw.write("#" + (int)tc + " ");
			// L~U X
			// 필요한 양보다 더 많은 운동을 했을 경우
			if(info[1] < info[2])	bw.write("-1" + '\n');
			// 필요양 만큼 할 경우
			else if(info[0] < info[2])	bw.write("0" + '\n');
			// 필요시간보다 운동을 하지 않은 경우
			else bw.write(String.valueOf(info[0] - info[2]) + '\n');
			
			bw.flush();
		}	
		

		bw.close();
		br.close();
	}
}
// 1주일에 L분 이상 U분 이하의 운동
// 이번 주에 X분만큼 운동
// 제한되어 있는 시간을 넘은 운동을 한 것인지, 그것이 아니라면 몇 분 더 운동을 해야 제한을 맞출 수 있는지 출