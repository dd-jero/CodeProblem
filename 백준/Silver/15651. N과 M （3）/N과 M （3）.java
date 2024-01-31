import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
	
	static int N;
	static int M;
	static BufferedWriter bw;
	static int[] res;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		res = new int[M];
		
		recur(0);
		
		br.close();
		bw.flush();
		bw.close();
	}
	
	// 중복 순열 
	static void recur(int cnt) throws IOException {
		
		if(cnt == M) {
			for(int i=0;i<M;i++) {
				bw.write(String.valueOf(res[i]));
				bw.write(" ");
			}
			bw.newLine();
			return;
		}
		
		for(int i=1;i<=N;i++) {
			res[cnt] = i;
			recur(cnt+1);
		}
	}
	
}