import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1961 {
	static int[][] arr;
	static int N;
	
	public static void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		
		for(int T=0; T<tc; T++) {	// Number of test cases
			N = Integer.parseInt(br.readLine());
			arr = new int[N][N];	// array
			
			// Store a matrix in an array
			for(int i=0; i<N; i++) {	// Number of N
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j=0; j<N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int[][] rotation_90 = Rotation(arr);	// 90 degree rotation
			int[][] rotation_180 = Rotation(rotation_90);	// 180 degree rotation
			int[][] rotation_270 = Rotation(rotation_180);	// 270 degree rotation
			
			System.out.println("#" + (T+1));
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					System.out.print(rotation_90[i][j]);	// 90 degree rotated shape
				}
				System.out.print(" ");
				
				for(int j=0; j<N; j++) {
					System.out.print(rotation_180[i][j]);	// 180 degree rotated shape
				}
				System.out.print(" ");
				
				for(int j=0; j<N; j++) {
					System.out.print(rotation_270[i][j]);	// 270 degree rotated shape
				}
				System.out.println("");
			}
		}
	}
	
	// 90 degree rotation
	public static int[][] Rotation(int[][] arr) {
		int[][] temp_arr = new int[N][N];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				temp_arr[i][j] = arr[N-1-j][i];
			}
		}
		
		return temp_arr;
	}
	
	public static void main(String[] args) throws Exception {
		Solution1961.run();
	}
}
