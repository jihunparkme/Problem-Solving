import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution1976 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {

			int hour = 0, minute = 0;
			int startH = 0, startM = 0, endH = 0, endM = 0;
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			
			startH = Integer.parseInt(st.nextToken());
			startM = Integer.parseInt(st.nextToken());
			endH = Integer.parseInt(st.nextToken());
			endM = Integer.parseInt(st.nextToken());
			
			hour = startH + endH;
			minute = startM + endM;

			if (minute > 59) {
				minute -= 60;
				hour++;
			}
			if (hour > 12)
				hour -= 12;

			System.out.println("#" + tc + " " + hour + " " + minute);
		}

	}

}
