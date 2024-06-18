import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution{
	
	static int N, cmdN;
	static List<Integer> nums;
	static char cmd;
	
	public static void main(String[] args) throws IOException {
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int t=1;t<=10;t++) {
			N = Integer.parseInt(br.readLine()); // 암호문의 개수
			nums = new ArrayList<Integer>();
			
			st = new StringTokenizer(br.readLine());
			
			// 숫자 하나씩 삽입 
			for(int i=0;i<N;i++) {
				nums.add(Integer.parseInt(st.nextToken()));
			}
			
			cmdN = Integer.parseInt(br.readLine()); // 명령어의 개수
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<cmdN;i++) {
				cmd = st.nextToken().charAt(0);
				
				switch (cmd) {
				case 'I': { // x,y,s 앞에서부터 x번째 암호문 바로 다음에 y개의 암호문 삽입
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					
					for(int idx=x;idx<x+y;idx++) {
						nums.add(idx,Integer.parseInt(st.nextToken()));
					}
					
					break;
				}
				case 'D':{ // x,y 앞에서부터 x번째 암호문 바로 다음부터 y개의 암호문 삭제
					
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					
					for(int idx=0;idx<y;idx++) {
						nums.remove(x);
					}
					break;
				}
				case 'A':{ // y,s 암호문 뭉치 맨뒤에 y개 암호문 덧붙임 
					int y = Integer.parseInt(st.nextToken());
					
					for(int idx=0;idx<y;idx++) {
						nums.add(Integer.parseInt(st.nextToken()));
					}
					break;
				}
				default:
					
				}
			}
			sb.append("#"+t+" ");
			
			for(int i=0;i<10;i++) {
				sb.append(nums.get(i)+" ");
			}
			
			sb.append("\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
	}
}