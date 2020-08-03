import java.util.Arrays;
import java.util.Scanner;

public class Solution1966 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc=1; tc<=T; tc++) {
			int N = sc.nextInt();
			int nums[] = new int[N];
			for(int i=0; i<N; i++) 
				nums[i] = sc.nextInt();
			
			Arrays.sort(nums);
			System.out.print("#" + tc + " ");
			for(int i=0; i<N; i++)
				System.out.print(nums[i] + " ");
			System.out.println();
		}
	}
}
