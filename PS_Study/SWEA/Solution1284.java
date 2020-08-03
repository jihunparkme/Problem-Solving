import java.util.Scanner;

public class Solution1284 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc=1; tc<=T; tc++) {
			int P = sc.nextInt(); // A사 : 1리터당 P원 
			int Q = sc.nextInt(); // B사 기본요금
			int R = sc.nextInt(); // B사 월간 사용량 기준 R리터
			int S = sc.nextInt(); // B사 초과량 1리터 당 S원
			int W = sc.nextInt(); // 한 달 수도 사용 양 (L)
			
			// A사 : 1리터당 P원의 돈을 내야 한다.
			int aFee = W * P;
			
			// B사 : 기본 요금이 Q원이고, 월간 사용량이 R리터 이하인 경우 요금은 기본 요금만 청구된다. 하지만 R 리터보다 많은 양을 사용한 경우
			// 초과량에 대해 1리터당 S원의 요금을 더 내야 한다.
			int bFee = Q;
			if (W > R) bFee += (W-R) * S;
			
			int res = aFee >= bFee ? bFee : aFee;
			
			System.out.println("#" + tc + " " + res);
		}
	}
}