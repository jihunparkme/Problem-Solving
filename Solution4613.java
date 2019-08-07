import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution4613 {
//	static String[] flag;
	static int[] W;
	static int[] B;
	static int[] R;
	static int N;
	static int M;
	
	public static void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int tc = Integer.parseInt(br.readLine());	// test_cast 입력
		
		for(int T=0; T<tc; T++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());  // line
			M = Integer.parseInt(st.nextToken());  // char
			
//			flag = new String[N];  // 초기 국기의 색
			W = new int[N];	// 각 행에서의 색상 개수
			B = new int[N];
			R = new int[N];
			
//			// 처음 입력된 국기의 색 저장
//			for(int ln=0; ln<N; ln++) {  
//				String line = br.readLine();
//				flag[ln] = line;
//			}
			
			// 1. 각 행의 W, B, R 개수 저장
			for(int i=0; i<N; i++) {	
				String flagRow = br.readLine();
				for(int j=0; j<M; j++) {
					int word = flagRow.charAt(j);
					if( word == 'W') W[i]++;
					else if(word == 'B') B[i]++;
					else R[i]++;
				}
			}
			
			// 2. 모든 경우의 수를 확인하여 최솟값 구하기
			int sum = 0;
			for(int i=1; i<=N-2; i++) {	// W가 나올 수 있는 경우의 수 : 1 ~ N-2  
				for(int j=i; j<N-1; j++) {	// W기준 B가 나올 수 있는 경우 : 2 ~ N-1
					int wCnt = 0;
					int bCnt = 0;
					int rCnt = 0;
					
					for(int k=0; k<i; k++) wCnt += W[k];	// W가 나올 수 있는 행에서 W의 개수
					for(int k=i; k<=j; k++) bCnt += B[k];	// W가 나올 수 있는 행에서 B의 개수
					for(int k=j+1; k<N; k++) rCnt += R[k];
					
					sum = Math.max(sum, wCnt+bCnt+rCnt);	// sum이 높을 수록 새로 칠해야하는 칸의 개수가 작음
				}
			}
			sum = N * M - sum;
			bw.write("#" + (T+1) + " " + sum + "\n");
		}
		br.close();	
		bw.close();
	}
	
	public static void main(String[] args) throws Exception{
		Solution4613.run();
	}
}
