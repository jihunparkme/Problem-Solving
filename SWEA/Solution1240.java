import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution1240 {
	/* 1. save password code */
	static String[] pw_code = {"0001101","0011001","0010011","0111101","0100011",
			"0110001","0101111","0111011","0110111","0001011"};
	
	public static void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for(int T=0; T<tc; T++) {	// Number of test cases
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());	// Array Vertical Size
			int M = Integer.parseInt(st.nextToken());	// Array Horizontal Size
			int[] rc = new int[8];	// Array containing translated code (Real_Code)
			
			int flag = 1;
			
			for(int h=0; h<N; h++) {
				String code =  br.readLine();
				/* 2. search for a number 1 from behind a string */
				int last_idx = code.lastIndexOf("1");  
				
				if (last_idx == -1 || flag == 0) {	// NOT include a number 1 in  a string
					continue;	// continue if return is -1
				}
				else {	// include a number 1 in  a string
					code = code.substring(last_idx-55, last_idx+1);
					for(int c=0; c<8; c++) {
						String temp_code = code.substring(c*7, c*7+7);
						for(int pw=0; pw<10; pw++) {	// search the index of the element
							if(pw_code[pw].equals(temp_code)) {
								rc[c] = pw;
								break;
							}
						}
					}
					// password verification
					int check = (rc[0] + rc[2] + rc[4] + rc[6]) * 3 + (rc[1] + rc[3] + rc[5]) + rc[7];
					if (check%10==0 && check>0) {	// correct password code
						flag = 0;
						int total = 0;
						for(int j=0; j<8; j++) total += rc[j];
						System.out.println("#" + (T+1) + " " + total);
					}
					else {		// incorrect password code
						flag = 0;
						System.out.println("#" + (T+1) + " " + 0);
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		Solution1240.run();
	}
}
