import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


// 에라토스테네스의 체를 사용하면 메모리 초과됨! 

class Main{
	
	static int N;
	static boolean check; 
	static StringBuilder sb;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		
		recur(0,0);
		
		System.out.println(sb);
		
	}
	
	static void recur(int num, int cnt) {
		
		if(cnt == N) {
			sb.append(num).append("\n");
			return;
		}
		
		for(int i=1;i<10;i++) {
			int nextNum = 10*num + i; // 자리수 증가
			
			// 자리수 증가된 수가 소수면 재귀
			if(isPrime(nextNum)) recur(nextNum, cnt+1);
		}
	}
	
	static boolean isPrime(int num) { // 소수 판별
		
		if(num < 2) return false; // 1은 소수 아님 
		
		for(int i=2;i*i<=num;i++) {
			if(num%i == 0) return false;
		}
		
		return true;
		
	}
}