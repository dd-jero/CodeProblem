import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
	
	static int N, nums[],maxRes;
	static char[] equation;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		N = Integer.parseInt(br.readLine()); // 수식의 길이 (1~19, 홀수)
		
		equation = new char[N];
		maxRes = Integer.MIN_VALUE;
		String eq = br.readLine();
		for(int i=0;i<N;i++) {
			equation[i] = eq.charAt(i);
		} // 입력 완료
		
		dfs(2,equation[0]-'0');
		
		bw.write(String.valueOf(maxRes));
		bw.flush();
		br.close();
		bw.close();
		
	}

	private static void dfs(int idx, int res) {

		if(idx >= N) { // 모든 연산 종료되면
			// 비교 갱신 
			maxRes = maxRes < res ? res : maxRes;
			return;
		}
		
		// 괄호 사용하고 연산 -> 현재 기준 다음 연산자에 괄호 활용
		if(idx+2 < N) {
			// 이전 연산 결과, (현재숫자, 연산자, 숫자), 연산자, 숫자[<= 여기 위치로]...
			int priorityRes = cal(equation[idx]-'0', equation[idx+2]-'0', equation[idx+1]); // 괄호 내부 연산
			int totalRes= cal(res, priorityRes, equation[idx-1]); // 이전 결과 값과 괄호 내부 값 연산 
			
			dfs(idx+4,totalRes);
		}
		
		// 괄호 사용하지 않고 연산 => 순서대로
		// 이전 연산 결과, 연산자, 현재숫자, 연산자, 숫자[<= 여기 위치로]... 
		int seqNum = cal(res, equation[idx]-'0', equation[idx-1]);
		dfs(idx+2, seqNum);
	}

	private static int cal(int num1, int num2, char oper) { // 왼쪽에 위치하는 숫자부터 num1로 넣어야됨!!!
		
		switch(oper) {
		case '+':
			return num1+num2;
		case '-':
			return num1-num2;
		default:
			return num1*num2;
		}
	}

	
}