import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main{
	
	static int N,d,k,c,res,tmp	;
	static int[] arr;
	static int[] visited; // 인덱스는 초밥 종류 의미
	static boolean cantUse, prevcantUse; // 쿠폰 사용 여부
	
 	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); // 벨트에 놓인 접시 수
		d = Integer.parseInt(st.nextToken()); // 초밥의 가짓 수
		k = Integer.parseInt(st.nextToken()); // 연속해서 먹는 접시 수
		c = Integer.parseInt(st.nextToken()); // 쿠폰번호 
		
		arr = new int[N];
		visited = new int[d+1];
		
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(br.readLine());
			
			if(i < k) { // 초기 k개 확인
				if(visited[arr[i]] == 0) tmp++; // 새로운 가짓수면 
				visited[arr[i]]++; // 방문 
				
			} // 초기화 
			
		} // 벨트위에 놓인 초밥 입력 
		
		// 투포인터 시작
		int left = 0;
		int right = k-1;
		res = tmp; // 초기 가짓수를 res에 저장 
		
		while(true) {
			
			if(res <= tmp) { // 쿠폰 여부 상관 없이 새로운 가짓수는 tmp
				if(visited[c] == 0) res = tmp + 1; // 해당 초밥을 먹지 않았으면 쿠폰 사용 
				else res = tmp;
			}
			
			if(left == N-1) break; // 왼쪽 인덱스가 arr 마지막 인덱스이면 종료 
			
			// 왼쪽 요소 제외  
			visited[arr[left]]--;
			if(visited[arr[left]] == 0) { // 아예 없어지면 
				tmp--;
			}
			
			// 왼쪽 , 오른쪽 포인터 증가 
			left++;
			right++;
			
			// 오른쪽이 배열 범위를 넘어가면 다시 0으로 돌아오도록
			right = (right == N) ? right % N : right;
			
			// 오른쪽 초밥 넣기 
			visited[arr[right]]++;
			if(visited[arr[right]] == 1) tmp++; // 새로운 가짓수 
			
			
			// tmp는 쿠폰 여부 상관없이 다른 가짓수
			res = res < tmp ? tmp : res; // 기존 최대 가짓수와 비교 
		}
		
		
		bw.write(String.valueOf(res));
		
		bw.flush();
		br.close();
		bw.close();
	
	}
}