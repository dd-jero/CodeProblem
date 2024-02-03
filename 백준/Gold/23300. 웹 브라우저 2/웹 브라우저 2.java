import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	

	static Deque<Integer> bspace = new ArrayDeque<Integer>();
	static Deque<Integer> fspace = new ArrayDeque<Integer>();

	static int curPage;
	static int N,Q, number;
	static String command;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());

		for(int i=0;i<Q;i++) {
			
			st = new StringTokenizer(br.readLine());
			command = st.nextToken();
			
			if(command.equals("B")) backward();
			else if(command.equals("F")) forward();
			else if(command.equals("C")) compression();
			else {
				number = Integer.parseInt(st.nextToken());
				access(number);
			}
			
//			System.out.println(bspace+"//"+curPage+"//"+fspace);
			
		} // 명령 종료
		
		StringBuilder sb = new StringBuilder();
		
		sb.append(curPage).append("\n");
		
		if(bspace.isEmpty()) sb.append(-1).append("\n");
		else {
			while(!bspace.isEmpty()) {
				sb.append(bspace.pollLast()).append(" ");
			}
			sb.append("\n");
		}
		
		if(fspace.isEmpty()) sb.append(-1);
		else {
			while(!fspace.isEmpty()) {
				sb.append(fspace.pollLast()).append(" ");
			}
		}
		System.out.println(sb);
	}
	
	static void backward() {
		if(!bspace.isEmpty()) {
			fspace.add(curPage); // 현재 페이지 앞 공간 삽입
			curPage = bspace.pollLast(); // 뒷 공간에서 최근 페이지 삭제 및 현재 페이지에 저장
		}
	}
	
	static void forward() {
		if(!fspace.isEmpty()) {
			bspace.add(curPage); // 현재 페이지 뒷 공간 삽입
			curPage = fspace.pollLast(); // 앞 공간에서 최근 페이지 삭제 및 현재 페이지에 저장
		}
	}
	
	static void compression() {
		Deque<Integer> tmp = new ArrayDeque<Integer>();
		
		if(!bspace.isEmpty()) {
			
			tmp.add(bspace.pollFirst()); // 처음에 임시공간에 요소 하나 추가
			
			for(int n:bspace) { // 뒷 공간 요소 확인
				if(tmp.peekLast() != n) tmp.add(n); // 가장 최근 삽입 페이지와 비교하여 다르면 삽입 
			}
			bspace = tmp; // 갱신
		}
		
//			System.out.println(tmp+"//"+curPage+"//"+bspace);
		
		
	}
	
	static void access(int p) {
		fspace.clear(); // 앞 공간 페이지 전체 삭제
		
		if(curPage!=0) { // 첫 접속이 아니면 
			bspace.add(curPage); // 현재 페이지 뒷 공간 추가
		}
		
		curPage = p; // 접속 페이지를 현재페이지로 갱신
	}
}