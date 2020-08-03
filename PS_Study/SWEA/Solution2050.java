import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution2050 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		for(int i=0; i<str.length(); i++) {
			System.out.print((int)str.charAt(i) - 64 + " ");
		}
	}
}
