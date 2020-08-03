import java.util.Arrays;
import java.util.Scanner;

public class Solution2068 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		int arr[] = new int[10];
		
		for(int i=1; i<=tc; i++) {
			for(int j=0; j<10; j++) {
				arr[j] = sc.nextInt();
			}
			
			Arrays.sort(arr);
			System.out.println("#" + i + " " + arr[9]);
		}		
	}
}
