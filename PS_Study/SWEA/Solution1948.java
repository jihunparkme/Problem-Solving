import java.util.Scanner;

public class Solution1948 {
	static int[] endDay = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int start[] = new int[2]; 
		int end[] = new int[2];
		int i, res;
		
		for(int tc=1; tc<=T; tc++) {
			res = 0;
					
			for(i=0; i<2; i++) {
				start[i] = sc.nextInt();
			}
			for(i=0; i<2; i++) {
				end[i] = sc.nextInt();
			}
			
			// 월이 같을 경우
			if(start[0] == end[0]) {
				res = end[1] - start[1] + 1;
			}
			else {
				for(i=start[0]; i<end[0]; i++) {
					res += endDay[i];
				}
				res = res - start[1] + end[1] + 1;
			}
			
			System.out.println("#" + tc + " " + res);
		}
	}
}

//  두 번째 날짜가 첫 번째 날짜의 며칠째인지
// 5 5 8 15 =? 103

//5  6  7
//31 30 31
//
//92 - 5 + 15 + 1