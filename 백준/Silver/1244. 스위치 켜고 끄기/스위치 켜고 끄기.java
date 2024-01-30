import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // 스위치 개수
		
		int[] switches = new int[N]; // 스위치 상태
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			switches[i] = Integer.parseInt(st.nextToken());
		}
		
		int students = Integer.parseInt(br.readLine()); // 학생 수
		
		for(int i=0;i<students;i++) {
			st = new StringTokenizer(br.readLine());
			int gender = Integer.parseInt(st.nextToken()); // 성별
			int number = Integer.parseInt(st.nextToken()); // 받는 수 
			
			if(gender == 1) { // 남학생
				for(int j=0;j<N;j++) {
					if((j+1) % number == 0) { // 받은 수의 배수이면
						switches[j] = switches[j]==0?1:0; // 상태 반전
					}
				}
			}
			else { // 여학생
				switches[number-1] = switches[number-1]==0?1:0; // 받은 수와 동일 인덱스 값 반전
				
				for(int j=1;j<N/2;j++) {
					if(number-1-j < 0 ||number-1+j >= N) { // 인덱스 범위 넘어가면 종료
						break;
					}
					
					if(switches[number-1-j] == switches[number-1+j]) { // 대칭 값 동일하면 반전  
						switches[number-1-j] = switches[number-1-j]==0?1:0;
						switches[number-1+j] = switches[number-1+j]==0?1:0;
					}
					else{ // 동일하지 않으면 종료
						break;
					}
					
				}
			}
		}
		for(int i=1;i<=N;i++) {
			
			System.out.printf("%d ",switches[i-1]);
			
			if(i % 20 == 0) { // 한 줄에 20개씩 출력 
				System.out.println();
			}
			
		}
		
		
		
	}

}
