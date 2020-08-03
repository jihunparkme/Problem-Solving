import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class BOJ5568_v2 {

	static int N, K, card[];
	static boolean visited[];
	static Set<Integer> setNum;	// 중복 저장을 막기 위한 Set 자료형 사용

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		K = Integer.parseInt(br.readLine());
		
		// init
		visited = new boolean[11];
		card = new int[N];
		setNum = new HashSet<Integer>();
		
		for (int i = 0; i < N; i++)
			card[i] = Integer.parseInt(br.readLine());

		process(0, 0);
		System.out.println(setNum.size());
	}

	// 문자열대신 숫자를 사용한 방법
	public static void process(int cnt, int num) {
		// K 개수만큼 카드가 선택되었을 경우, Set에 add
		if(cnt  == K) {
			setNum.add(num);
			return;
		}
		for (int i = 0; i < N; i++) {
			// 이미 사용된 카드라면 pass
			if(visited[i]) continue;
			visited[i] = true;	// 카드를 사용해볼까?
			int tmp;
			// 카드는 1이상 99이하라고 했다.
			// 카드가 두 자리 숫자라면 기존 숫자에 100을 곱한 후 추가된 숫자를 더해주고
			// 한 자리 숫자라면 기존 숫자에 10을 곱한 후 추가된 숫자를 더해주자.
			if(card[i] > 9) tmp = num * 100 + card[i];
			else tmp = num * 10 + card[i];
			process(cnt + 1, tmp);
			visited[i] = false;	// 카드를 사용하지 않을래
		}
	}
}
