import java.util.Scanner;

public class Solution1289_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++) {
			String origin = sc.next();
			// my의 현재는 0
			char my = '0';
			int cnt = 0; //바꾼 횟수
			//첫번째 비트부터 검사해가면서
			for(int i = 0; i < origin.length(); i++) {
				//검사하는 위치에서 origin과 my가 다르다면.
				if( my != origin.charAt(i)) {
					cnt++; // 여기 들어올떄마다 센다.
					my = origin.charAt(i);
				}
			}
			System.out.println("#" + tc + " " + cnt);
		}
	}
}
