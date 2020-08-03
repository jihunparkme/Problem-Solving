import java.util.Arrays;
import java.util.Scanner;

public class Solution1288 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean chk[] = new boolean[10];
		int T = sc.nextInt();
		int mul = 1;
		boolean isAll = true;;
		
		for(int tc=1; tc<=T; tc++) {
			int n = sc.nextInt();
			int tmp = n;
			Arrays.fill(chk, false);
			mul = 1;
			
			while(true) {
				while(tmp > 0) {
					chk[tmp % 10] = true;
					tmp /= 10;
				}
				
				isAll = true;
				for(int i=0; i<=9; i++) {
					if(!chk[i]) {
						isAll = false;
						break;
					}
				}
				
				if(isAll) {
					tmp = n * mul;
					break;
				}
				else {
					mul++;
					tmp = n * mul;
				}
			}
			
			System.out.println("#" + tc + " " + tmp);
		}
	}
}
