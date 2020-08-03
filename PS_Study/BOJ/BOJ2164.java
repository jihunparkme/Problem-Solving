import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class BOJ2164 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		Deque<Integer> q = new ArrayDeque<Integer>();
		int N = Integer.parseInt(br.readLine());
		for (int i = 1; i <= N; i++)
			q.add(i);

		while (q.size() != 1) {
			// 제일 위에 있는 카드를 바닥에 버린다
			q.pop();
			// 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로
			int tmp = q.pop();
			q.add(tmp);
		}

		System.out.println(q.pop());
	}

}
