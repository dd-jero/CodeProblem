import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
	
	static BufferedWriter bw;
	static int N;
	static int M;
	static int[] res;
	static boolean[] visited;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		bw = new BufferedWriter (new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); // 1 ~ N
		M = Integer.parseInt(st.nextToken()); //  고르는 개수
		
		res = new int[M];
		visited = new boolean[N+1];
		visited[0] = true;
		
		recur(0);
		
		br.close();
		bw.flush();
		bw.close();
		
	}
	
	// 수열 
	static void recur(int cnt) throws IOException {
		
		if(cnt == M) { // 종료 조건 
			for(int i=0;i<M;i++) {
				bw.write(String.valueOf(res[i]));
				bw.write(" ");
			}
			bw.newLine();
			return;
		}
		
		for(int i=1;i<=N;i++) {
			
			if(visited[i]) continue;
			
			res[cnt] = i;
			visited[i] = true;
			recur(cnt+1);
			visited[i] = false;
		}
	}
}