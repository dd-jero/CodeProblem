import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

class Main{
	
	static Deque<Integer> deq = new ArrayDeque<Integer>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i=N;i>0;i--) { // 큰 수부터 덱에 삽입 
			deq.add(i);
		}
		
		while(deq.size()>1) { // 덱 사이즈가 1이되면 종료 됨.
			deq.pollLast(); // Last-In 버림
			deq.addFirst(deq.pollLast());// 버린 후 Last-In을 First-In으로 삽입
		}
		
		sb.append(deq.peek());	// 남은 하나 출력
		System.out.println(sb);
	}
}