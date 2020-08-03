import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Solution6808 {

	static int T, N, kySum, iySum, resWin, resLose;
	static boolean[] cardList, visit;
	static int kyCard[], iyCard[], selCard[];


	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		T = Integer.parseInt(br.readLine());
		N = 9;
		for (int tc = 1; tc <= T; tc++) {

			cardList = new boolean[19];
			visit = new boolean[N];
			kyCard = new int[N];
			iyCard = new int[N];
			selCard = new int[N];
			// 규영이 카드
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < N; i++) {
				kyCard[i] = Integer.parseInt(st.nextToken());
				cardList[kyCard[i]] = true;
			}
			// 그 외는 카드가 인영이 카드
			int tmp = 0;
			for (int i = 1; i <= 18; i++) 
				if(!cardList[i]) iyCard[tmp++] = i;
		
			resWin = 0; resLose = 0;
			// 인영이 카드의 순열
			process(0);
			
			// 규영이가 이기는 경우와 지는 경우의 가지 수
			bw.write("#" + tc + " " + resWin + " " + resLose  + '\n');
			bw.flush();
		}
		br.close();
		bw.close();
	}

	public static void process(int cnt) {
		// 9장 다 뽑으면
		if(cnt == N) {
			// 높은 수가 적힌 카드를 낸 사람은 두 카드에 적힌 수의 합만큼 점수를
			// 낮은 수가 적힌 카드를 낸 사람은 아무런 점수도 얻을 수 없다.
			kySum = 0; iySum = 0;
			for (int i = 0; i < N; i++) {
				int getScore = kyCard[i] + selCard[i];
				if(kyCard[i] > selCard[i]) kySum += getScore;
				if(kyCard[i] < selCard[i]) iySum += getScore;
			}
			
			// 총점이 더 높은 사람이 이 게임의 승자가 된다.
			// 두 사람의 총점이 같으면 무승부이다.
			// 규영이가 게임을 이기는 경우의 수와 게임을 지는 경우
			if(kySum > iySum) resWin++;
			if(kySum < iySum) resLose++;
			return;
		}
		
		for (int i = 0; i < N; i++) {
			// 고르지 않은 카드라면
			if(!visit[i]) {
				visit[i] = true;
				selCard[cnt] = iyCard[i];
				process(cnt + 1);
				visit[i] = false;
			}
		}
	}
}
