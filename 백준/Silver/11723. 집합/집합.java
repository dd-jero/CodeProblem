import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	
	static String command;
	static int num;
	static int S = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int M = Integer.parseInt(br.readLine());
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			command = st.nextToken();
			
			if(command.equals("all")) S = (1 << 21) - 1; // 최상위 비트만 1인 21자리에서 0b1 빼면 최상위 비트 제외 아래 20자리 모두 1임
			else if(command.equals("empty")) S = 0;
			else {
				num = Integer.parseInt(st.nextToken());
				
				if(command.equals("add")) S |= (1<<num); // OR 연산으로 해당 자리는 무조건 1로 
				else if(command.equals("remove")) S &= ~(1<<num); // 반전 시켜서 해당 자리만 0으로
				else if(command.equals("check")) sb.append(((S &(1<<num)) == 0?0:1)+"\n"); // AND 연산으로 1,1이면 존재 
				else if(command.equals("toggle")) S ^= (1<<num); // XOR로 두 비트가 서로 다르면 1
			}
		}
		System.out.println(sb);
		
		br.close();
		
	}
	
	
	
}
