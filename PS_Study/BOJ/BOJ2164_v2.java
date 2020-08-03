import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class BOJ2164_v2 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int arr[] = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = i+1;

		int front = 0;
		int rear = N-1;
		
		while (front != rear) {
			// 제일 위에 있는 카드를 바닥에 버린다
			arr[front++] = 0;
			if(front >= N) front -= N;
			// 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로
			int tmp = arr[front];
			arr[front++] = 0;
			if(front >= N) front -= N;
			rear++;
			if(rear >= N) rear -= N;
			arr[rear] = tmp;
		}

		System.out.println(arr[rear]);
	}

}
