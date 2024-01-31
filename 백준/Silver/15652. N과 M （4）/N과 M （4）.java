import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


class Main {
	
	static int[] res;
	static int N;
	static int M;
	static BufferedWriter bw;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken()); // 1 ~ N
		M = Integer.parseInt(st.nextToken()); // 고른 개수
		res = new int[M];
		
		recur(0,1);
		
		bw.flush();
		br.close();
		bw.close();
	}
	
	// 중복 조합 
	static void recur(int cnt, int start) throws IOException {
		
		if(cnt == M) { // 종료 조건
			
			for(int i=0;i<M;i++) {
				bw.write(String.valueOf(res[i]));
				bw.write(" ");
			}
			bw.newLine();
			
			return;
		}
		
		for(int i=start;i<=N;i++) { 
			res[cnt] = i; // 해당 cnt 인덱스에 값 저장
			recur(cnt+1, i); // 재귀 : 시작 인덱스로 i를 넣어줌.
		}
		
		
	}
}