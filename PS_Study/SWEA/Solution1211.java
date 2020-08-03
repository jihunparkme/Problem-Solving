import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
 
public class Solution1211 {
 
    static int T, N, map[][], res, resIdx, cnt;
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
        T = 10;
        N = 100;
 
        for (int tc = 1; tc <= T; tc++) {
             
            map = new int[N][N];
            ArrayList<Integer> startPointY = new ArrayList<Integer>();
            Integer.parseInt(br.readLine());
            res = 987654321;
            
            // 사다리 만들기
            for (int x = 0; x < N; x++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                for (int y = 0; y < N; y++) {    
                    map[x][y] = Integer.parseInt(st.nextToken());
                    // 시작지점 체크
                    if(x == 0 && map[x][y] == 1) startPointY.add(y);
                }
            }
  
            // 하나씩 내려가보기
            for (int i = 0; i < startPointY.size(); i++) {
				
            	int x = 0;
            	int y = startPointY.get(i);
            	int idx = i;
            	cnt = 0;
            	
            	// 먼저 한 칸 내려가고
            	x++; cnt++;
            	
            	// 도착지점에 도달할 때까지 반복
            	while(x != N-1) {
            		// 좌우에 길이 있는지 확인
            		// 0:좌, 1:우, 2:길 없음
            		int direction = 2;
            		// 좌측에 길이 있을 경우
            		if(y-1 >= 0 && map[x][y-1] == 1) {
            			direction = 0;
            			idx--;
            		}
            		// 우측에 길이 있을 경우
            		if(y+1 < N && map[x][y+1] == 1) {
            			direction = 1;
            			idx++;
            		}
            		// 길이 없다면
            		if(direction == 2) {
            			x += 1;
            			continue;
            		}
            		// 길이 있다면 해당 길로 이동
            		cnt += (Math.abs(y - startPointY.get(idx)));
            		y = startPointY.get(idx);
            		// 옮긴 행에서 다시 한 칸 내려가기
            		x++; cnt++;
            	}	
            	
            	if(res > cnt) {
            		res = cnt;
            		resIdx = startPointY.get(i);
            	}
			}
            
            // 모든 출발점을 검사하겨 가장 짦은 이동 거리를 갖는 시작점 x를 반환
    		// 복수개인 경우 가장 큰 x좌표
        	System.out.println("#" + tc + " " + resIdx);
        }
    }
}