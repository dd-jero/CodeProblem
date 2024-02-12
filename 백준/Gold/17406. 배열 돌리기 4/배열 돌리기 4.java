import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


class Data{
	
	int r;
	int c;
	int s;
	
	public Data(int r, int c, int s) {
		this.r = r;
		this.c = c;
		this.s = s;
	}

	@Override
	public String toString() {
		return "Data [r=" + r + ", c=" + c + ", s=" + s + "]";
	}
	
	
	
}

class Main{
	
	static int N,M,K,r,c,s,ans;
	static int[][] arr, tmp;
	static Data[] cmd;
	static Data[] res;
	static boolean[] visited;
	
	// 하, 우, 상, 좌 
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1][M+1];
		tmp = new int[N+1][M+1];
		visited = new boolean[K];
		cmd = new Data[K];
		res = new Data[K];
		ans = Integer.MAX_VALUE;
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=M;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				tmp[i][j] = arr[i][j];
			}
		}
		
		for(int i=0;i<K;i++) { // 회전 연산의 순서는 상관 없음!!
			st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			cmd[i] = new Data(r,c,s);
		}
		
		permutation(0);
		bw.write(String.valueOf(ans));
		bw.flush();
		
		br.close();
		bw.close();
	}
	
	static void permutation(int cnt) { // K개의 회전 명령들을 순열
		
		if(cnt == K) { // 종료 조건 
			
//			System.out.println(Arrays.toString(res)); // 순열 확인 
			for(int i=0;i<K;i++) {
				rotate(res[i].r,res[i].c,res[i].s);
			}
			
			for(int i=1;i<=N;i++) { // 행의 합 중 최솟 값 구하기 
				int sum = 0;
				for(int j=1;j<=M;j++) {
					sum += arr[i][j];
				}
				ans = sum < ans? sum: ans;
			}
			
			for(int i=1;i<=N;i++) { // 이전 회전 연산을 초기화 (원상 복구 후 회전연산)
				for(int j=1;j<=M;j++) {
					arr[i][j] = tmp[i][j];
				}
			}
			
			return;
		}
		
		for(int i=0;i<K;i++) {
			if(visited[i]) continue;
			
			visited[i] = true;
			res[cnt] = cmd[i]; // 해당 data 저장
			permutation(cnt+1);
			visited[i] = false;
			
		}
	}
	
	static void rotate(int r, int c, int s) { // 회전 연산 
		
		for(int i=0;i<s;i++) { // 
			// 시작 위치 (왼쪽 상단 모서리)
			int x = r-s + i;
			int y = c-s + i;
			
			int tmp = arr[x][y]; // 초기 위치 저장 
			
			int d = 0; // 4방향 위한
			
			while(d < 4) {
				
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if((r-s+i)<=nx && nx<=(r+s-i) && (c-s+i)<=ny && ny<=(c+s-i)) { // 범위 내 존재
					arr[x][y] = arr[nx][ny]; // 이동
					x = nx;
					y = ny;
				}else { // 범위 벗어나면 방향 전환 
					d++;
				}
			}
			
			// 초기 시작위치 값을 마지막 위치에 저장
			arr[x][y+1] = tmp;
		}
		
		
		
	}
}