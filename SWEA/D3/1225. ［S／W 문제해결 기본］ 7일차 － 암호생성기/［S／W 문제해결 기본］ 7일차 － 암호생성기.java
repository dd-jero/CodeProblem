import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Solution {
	
	static Deque<Integer> nums;
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb;
		
		for(int t=1;t<=10;t++) {
			
			int N = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			
			nums = new ArrayDeque<Integer>();
			for(int i=0;i<8;i++) {
				nums.add(Integer.parseInt(st.nextToken()));
			}// 입력 완료
			
			int cnt = 1; // 감소 숫자

			while(true) {
				
				int n = nums.pollFirst() - cnt; // 앞의 숫자 cnt 만큼 감소
				
				if(n <=0) { // 감소 후 0보다 작아지면 0 삽입 후 종료  
					nums.add(0);
					break;
				}else { // 0보다 크면 
					nums.add(n); // 뒤에 삽입
				}
				
				cnt++;
				
				if(cnt == 6) cnt = 1;
			}
			
			sb = new StringBuilder();
			sb.append("#").append(t).append(" ");
			
			while(!nums.isEmpty()) {
				sb.append(nums.pollFirst()).append(" ");
			}
			
			System.out.println(sb);
			
		}
	}
}
