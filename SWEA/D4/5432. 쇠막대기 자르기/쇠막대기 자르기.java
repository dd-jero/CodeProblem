import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	
	static int res; // 총 막대기 개수
	static int cnt; // 막대기 개수 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		
		int TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			
			String iron = br.readLine();
			res = 0;
			cnt = 0;
			
			for(int i=0;i<iron.length();i++) {
				
				if(iron.charAt(i) == '(' && iron.charAt(i+1) ==')') { // ()이면 레이저
					res += cnt;
					i++; // ()를 하나로 묶어서 
				}else if(iron.charAt(i) == '(') { // 막대기 시작 
					cnt++;
					
				}else { // 나며지는 막대기가 끝나면서 하나 더 생기는 
					res++; 
					cnt--;
				}
			}
			sb = new StringBuilder();
			sb.append("#").append(t).append(" ").append(res);
			System.out.println(sb);
		}
	}
}
