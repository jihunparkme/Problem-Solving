import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1242 {
	// 1. Save password code ratio
	static String[] pw_ratio = {"3211","2221","2122","1411","1132",
			"1231","1114","1312","1213","3112"};
	static String[] binary = {"0000","0001","0010","0011","0100","0101",
			"0110","0111","1000","1001","1010",
			"1011","1100","1101","1110","1111"};
	
	public static void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int tc = Integer.parseInt(br.readLine());
		
		for(int T=0; T<tc; T++) {	// Number of test cases
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());	// Array Vertical Size
			int M = Integer.parseInt(st.nextToken());	// Array Horizontal Size
			String[][] code_store = new String[N][M];	// 코드 저장소
			int[] rc = new int[8];	// Array containing translated code (Real_Code)
			int flag = 1;
			
			for(int h=0; h<N; h++) {
				// 2. input hexa password
				String code =  br.readLine();
				
				int another = 0;
				// check for multiple password codes 
				for(int an=0; an<M; an++) {		//store code
					for(int s=0; s<M; s++) {	// A line
						char cc = code.charAt(s);
						if(cc == '0') continue;
						// Convert to binary code by char
						sb.append(chageToBinary(cc));
						another = 1;
					}
					code_store[h][an] = sb.toString();
					sb.setLength(0);	// reset stringbuilder
				}
				
				int last_idx = binCode.lastIndexOf("1");
				
				if (last_idx == -1 || flag == 0) continue;	// NOT include a number 1 in  a string
				
				binCode = binCode.substring(last_idx-55, last_idx+1);
				
				rc = decode();
				// 검증하고 배열 초기화 
			}
		}
	}

	public static int[] decode(String binCode) {
		int[] temp_arr = new int[8];
		StringBuilder sb2 = new StringBuilder();
		int check = 0;
		int ratio = 0;

		for(int c=0; c<8; c++) {	// password
			String temp_code = binCode.substring(c*7, c*7+7);
			// check ratio
			for(int i=0; i<7; i++) {
				int num = temp_code.charAt(i);
			}
			
			
			for(int pw=0; pw<10; pw++) {	// search the index of the element
				if(pw_code[pw].equals(temp_code)) {
					rc[c] = pw;
					break;
				}
			}
		}
		
		return temp_arr;
	}
			
	public static String chageToBinary(char Code) {
		int inCode;
		String bCode;
		if (Code>= 48&&Code<=57) inCode = Code - '0';	// code is number
		else inCode = Code - 'A' + 10;	// code is character
		
		bCode = binary[inCode];
	
		return bCode;
	}
	
	public static void main(String[] args) throws Exception {
		Solution1242.run();
	}
}
