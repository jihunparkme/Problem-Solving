import java.util.Scanner;

public class Solution1961 {
	
	static int N;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int tc=1; tc<=T; tc++) {
			N = sc.nextInt();
			int arr[][] = new int[N][N];
			int arr90[][] = new int[N][N];
			int arr180[][] = new int[N][N];
			int arr270[][] = new int[N][N];
			// Input
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			
			arr90 = rotation90(arr, arr90);
			arr180 = rotation180(arr, arr180);
			arr270 = rotation270(arr, arr270);
			
			System.out.println("#" + tc);
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) 
					System.out.print(arr90[i][j]);
				System.out.print(" ");
				for(int j=0; j<N; j++) 
					System.out.print(arr180[i][j]);
				System.out.print(" ");
				for(int j=0; j<N; j++) 
					System.out.print(arr270[i][j]);
				System.out.println();
			}
		}
	}
	
	public static int[][] rotation90(int[][] arr, int[][] res) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				res[j][N-1-i] = arr[i][j];
			}
		}
		
		return res;
	}
	
	public static int[][] rotation180(int[][] arr, int[][] res) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				res[N-1-i][N-1-j] = arr[i][j];
			}
		}
		
		return res;
	}
	
	public static int[][] rotation270(int[][] arr, int[][] res) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				res[N-1-j][i] = arr[i][j];
			}
		}
		
		return res;
	}
}
/*
[90도]
00 01 02
10 11 12
20 21 22

20 10 00
21 11 01
22 12 02

00 -> 02
01 -> 12
02 -> 22

10 -> 01 
11 -> 11
12 -> 21
*/
/*
[180도]
00 01 02
10 11 12
20 21 22

22 21 20
12 11 10
02 01 00

00 -> 22
01 -> 21
02 -> 20

10 -> 12 
11 -> 11
12 -> 10
*/
/*
[270도]
00 01 02
10 11 12
20 21 22

02 12 22
01 11 21
00 10 20

00 -> 20
01 -> 10
02 -> 00

10 -> 21
11 -> 11
12 -> 01
*/