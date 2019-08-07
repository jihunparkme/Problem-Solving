import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1204 {
	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int i=0; i<T; i++) {	// 테스트 케이스 수
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int[] score_arr = new int[101];		// score 배열
			
			while (st.hasMoreTokens()) {
				int tmp = Integer.parseInt(st.nextToken());
				score_arr[tmp]++;
			}
			
			int max = 0;	// 빈도수
			int max_idx = 0;	// 최빈수
			int sc_ar_idx = 0;	// array index

			for(int sc : score_arr) {
				if(sc > max) {
					max = sc;
					max_idx = sc_ar_idx;
				} 
				if(sc == max) {
					if (sc_ar_idx > max_idx) {
						max_idx = sc_ar_idx;
					}
				}
				sc_ar_idx++;
			}

			System.out.println("#" + (i+1) + " " + max_idx);
		}
	}
	
	public static void main(String[] args) throws Exception {
		new Solution1204().run();
	}
}