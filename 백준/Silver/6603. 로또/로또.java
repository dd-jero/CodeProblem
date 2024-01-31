import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
	
	static int K;
	static int[] nums;
	static int[] res;
	static BufferedReader br;
	static BufferedWriter bw;
	static StringTokenizer st;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		while(true) {

			st = new StringTokenizer(br.readLine());
			K = Integer.parseInt(st.nextToken()); // K
			
			if (K == 0) { // 0이면 프로그램 종료 
				br.close();
				bw.flush();
				bw.close();
				return;
			}
			
			nums = new int[K];
			res = new int[6];
			
			for(int i=0;i<K;i++) {
				nums[i] = Integer.parseInt(st.nextToken()); // 오름차순으로 주어지는 원소 
			}
			
			recur(0,0);
			bw.newLine();
			
			
		}
		
		
	}
	
	// 순열
	static void recur(int cnt, int start) throws IOException {
		
		if(cnt == 6) { // 종료 조건 
			for(int i=0;i<6;i++) {
				
				bw.write(String.valueOf(res[i]));
				bw.write(" ");
			}
			bw.newLine();
			
			return;
		}
		
		for(int i=start;i<K;i++) {
			
			res[cnt] = nums[i];
			
			recur(cnt+1, i+1);
			
		}
	}
}