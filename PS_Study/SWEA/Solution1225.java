import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution1225 {

	static int T;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = 10;

		for (int tc = 1; tc <= T; tc++) {

			Queue<Integer> queue = new LinkedList<Integer>();
			br.readLine();
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < 8; i++)
				queue.add(Integer.parseInt(st.nextToken()));

			int tmp, idx = 1;
			while (true) {
				// 첫 번째 숫자를 뽑아서
				tmp = queue.poll();
				// 감소한 뒤
				tmp -= idx++;
				if (idx > 5)
					idx = 1;
				// 맨 뒤에 넣어주기
				if (tmp <= 0) {
					queue.add(0);
					break;
				}
				queue.add(tmp);

			}

			System.out.print("#" + tc + " ");
			for (int i = 0; i < 8; i++) {
				System.out.print(queue.poll() + " ");
			}
			System.out.println();
		}

	}

}
