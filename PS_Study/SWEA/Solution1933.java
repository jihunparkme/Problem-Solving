import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Solution1933 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i;
		ArrayList<Integer> lst = new ArrayList<Integer>();
		
		for(i=1; i*i<=n; i++) {
			if(n%i == 0) {
				lst.add(i); lst.add(n/i);
			}
		}
		Collections.sort(lst);
		for(i=0; i<lst.size(); i++) 
			System.out.print(lst.get(i) + " ");
	}
}
