import java.util.Scanner;

public class Solution1940 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc=1; tc<=T; tc++) {
			int N = sc.nextInt();
			int range = 0;
			int nowSpeed = 0;
			int speed; 
			
			for(int scd=1; scd<=N; scd++) {
				int oper = sc.nextInt();
				if (oper == 0) {
					speed = 0;
					range += nowSpeed;
				}
				else {
					speed = sc.nextInt();
					
					if(oper == 1) 
						nowSpeed += speed;
					else 
						nowSpeed -= speed;
					
					if(nowSpeed < 0) nowSpeed = 0;
					range += nowSpeed; 
				}
			}
			
			System.out.println("#" + tc + " " + range);
		}
	}
}

/*
0 : 현재 속도 유지.
1 : 가속
2 : 감속

48
111
*/