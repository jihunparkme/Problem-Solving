import java.util.Scanner;

public class Solution2047 {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		char[] strArr = new char[str.length()];
		
		for(int i=0; i<strArr.length; i++) {
			if((char)str.charAt(i) >= 97 && (char)str.charAt(i) <=122)
				strArr[i] = (char)((char)str.charAt(i) - 32);
			else
				strArr[i] = str.charAt(i);
		}
		
		System.out.println(strArr);
	}
}
