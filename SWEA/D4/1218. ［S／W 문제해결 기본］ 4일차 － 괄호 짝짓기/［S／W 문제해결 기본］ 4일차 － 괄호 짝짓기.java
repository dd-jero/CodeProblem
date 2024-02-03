import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Solution {
	
	
	static Stack<Character> stack; // char형 넣을려면 기본형이 아님 클래스형으로 넣어야함.
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb;
		
		for(int t=1;t<=10;t++) {
			stack = new Stack<Character>();
			int N = Integer.parseInt(br.readLine());
			String str = br.readLine();
			
			for(int i=0;i<N;i++) {
				char curStr = str.charAt(i);
				
				if(stack.isEmpty()) stack.add(curStr); // 스택이 비어 있으면 삽입
				else { // 요소 존재하면
					char tmp = stack.peek(); // top 요소 확인 
					
					// 같은 묶음이면 pop
					if(tmp == '(' && curStr == ')') {
						stack.pop();
					}else if(tmp == '[' && curStr == ']') {
						stack.pop();
					}else if(tmp == '{' && curStr == '}') {
						stack.pop();
					}else if(tmp == '<' && curStr == '>') {
						stack.pop();
					}else { // 다르면 삽입
						stack.add(curStr);
					}
				}
				
			} // 짝 판별 종료
			
			sb = new StringBuilder();
			sb.append("#").append(t).append(" ");
			
			if(stack.isEmpty()) sb.append(1);
			else sb.append(0);
			
			System.out.println(sb);
			
		}
	}
}
