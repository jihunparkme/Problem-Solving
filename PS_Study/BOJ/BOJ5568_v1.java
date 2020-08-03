import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class BOJ5568_v1 {

	static int N, K, card[];
	static boolean visited[];
	static HashSet<String> setNum;	// 중복 저장을 막기 위한 Set 자료형 사용

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		K = Integer.parseInt(br.readLine());
		
		// init
		visited = new boolean[11];
		card = new int[N];
		setNum = new HashSet<String>();
		
		for (int i = 0; i < N; i++)
			card[i] = Integer.parseInt(br.readLine());

		process(0, "");
		System.out.println(setNum.size());
	}

	// 초기 StringBuilder를 사용해보았지만, 계속 string이 누적되어서
	// + operator 사용
	public static void process(int cnt, String str) {
		// K 개수만큼 카드가 선택되었을 경우, Set에 add
		if(cnt  == K) {
			setNum.add(str);
			return;
		}
		// 순서를 생각하면 안되므로 for문을 사용
		for (int i = 0; i < N; i++) {
			// 이미 사용된 카드라면 pass
			if(visited[i]) continue;
			visited[i] = true;	// 카드를 사용해볼까?
			// 카드를 사용했으니까 cnt를 늘려주고, str에 추가된 숫자를 더해주자
			process(cnt + 1, str + Integer.toString(card[i]));
			visited[i] = false;	// 카드를 사용하지 않을래
		}
	}
}
