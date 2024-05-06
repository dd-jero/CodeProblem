import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
	
	static int N;
	static int[] stairs;
	static int[] score;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		N = Integer.parseInt(br.readLine());
		
		stairs = new int[301];
		score = new int[301];
		
		// 0번째는 시작점 
		for(int i=1;i<=N;i++) {
			stairs[i] = Integer.parseInt(br.readLine());
		} // 입력 완료 
		
		score[1] = stairs[1];
		score[2] = stairs[1] + stairs[2];
		
		// 연속해서 세 계단을 한칸씩오르지 못한다.
		score[3] = Math.max(stairs[1], stairs[2]) + stairs[3];
		
		for(int i=4;i<=N;i++) {
			score[i] = Math.max(score[i-3]+stairs[i-1], score[i-2]) + stairs[i];
		}
		
		bw.write(String.valueOf(score[N]));
		bw.flush();
		br.close();
		bw.close();
		
	}
}