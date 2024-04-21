import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
	
	static int N;
	static int[] dp;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		N = Integer.parseInt(br.readLine());
		dp = new int[1001];
		
		// 기저 조건 
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		
		for(int i=3;i<=N;i++) {
			dp[i] = (dp[i-1] % 10007 + dp[i-2] % 10007) % 10007;
		}
		
		bw.write(String.valueOf(dp[N]));
		bw.flush();
		
		br.close();
		bw.close();
	}
}