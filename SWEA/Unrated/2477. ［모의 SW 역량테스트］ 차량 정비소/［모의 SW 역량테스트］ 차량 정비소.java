import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Solution{
	
	static class People{
		int k; // 고객 번호
		int arrTime; // 고객 도착 시간 
		int t; // 해당 창구에서 남은 시간 
		int aNum; // 이용 접수 창구 번호
		
		int aStartTime; // 접수 창구 시작 시간
		int aEndTime; // 접수 창구 완료 시간
		int bStartTime; // 정비 창구 시작 시간
		int bEndTime; // 정비 창구 종료 시간 
		
		public People(int k, int arrTime) {
			this.k = k; // 고객 번호
			this.arrTime = arrTime; // 고객 도착 시간 
		}
		
	}
	
	static int TC, res;
	static int N,M,K,A,B,curTime,finish;
	static int[] a,b;
	static People[] aa,bb;
	static PriorityQueue<People> q1,q2;
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine()); // 테스트 케이스
		
		for(int tc=1;tc<=TC;tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 접수 창구 수
			M = Integer.parseInt(st.nextToken()); // 정비 창구 수
			K = Integer.parseInt(st.nextToken()); // 고객 수
			A = Integer.parseInt(st.nextToken()); // 지갑 분실 고객의 접수 창구 번호
			B = Integer.parseInt(st.nextToken()); // 지각 분실 고객의 정비 창구 번호 
			
			a = new int[N+1]; // 접수하는데 걸리는 시간 
			b = new int[M+1]; // 정비하는데 걸리는 시간
			
			aa = new People[N+1];
			bb = new People[M+1];
			
			st = new StringTokenizer(br.readLine());
			for(int i=1;i<=N;i++) {
				a[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=1;i<=M;i++) {
				b[i] = Integer.parseInt(st.nextToken());
			}
			
			res = 0; // 고객 번호 합 
			curTime = 0; // 시간
			finish = 0; // 정비 창구 완료 고객 수
			
			// 접수 창구 대기 큐
			q1 = new PriorityQueue<People>((o1, o2) -> o1.k - o2.k); // 고객 번호가 낮은 순서대로 
			
			
			// 일단 접수 창구 대기 큐에 모두 삽입 
			st = new StringTokenizer(br.readLine());
			for(int i=1;i<=K;i++) {
				q1.offer(new People(i,Integer.parseInt(st.nextToken()))); // 고객 번호, 도착 시간 
			}  
			
			// 정비 창구 대기 큐 
			q2 = new PriorityQueue<People>(new Comparator<People>() {

				@Override
				public int compare(People o1, People o2) {
					if(o1.aEndTime == o2.aEndTime) {
						return o1.aNum - o2.aNum; // 이용 접수 창구 번호 작은대로
					} else {
						return o1.aEndTime - o2.aEndTime; // 접수 창구 끝난 대로
					}
				}
			}); 
			
			
			
			while(true) {
				
				// 종료조건 : 모든 고객이 접수/정비 창구 이용 완료
				if(finish == K) break;
				
				
				// 접수 창구 확인
				checkFirst(curTime);
				checkSecond(curTime);
				
				curTime++;
				
			}
			
			res = res == 0 ? -1 : res;
			sb.append("#"+tc+" "+res+"\n");
			
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		br.close();
	}
	
	static void checkFirst(int curTime){
		
		for(int i=1;i<=N;i++) {  // 기존 사용중인 고객 확인 
			if(aa[i] != null) { // 창구에 고객이 존재할 때
				
				if(aa[i].aEndTime == curTime) { // 끝나면
					
					aa[i].aNum = i; // 접수 창구 번호 입력
					q2.offer(aa[i]); // 정비 창구 대기 큐로 이동 
					aa[i] = null; // 창구 비우기 
				}
			}
			
		}
		
		for(int i=1;i<=N;i++) {  
			if(aa[i] == null) { // 비어 있는 접수 창구가 있으면
				if(!q1.isEmpty()) { // 큐에 남은 요소 존재할 때 
					if(q1.peek().arrTime <= curTime) { // 도착 이후 계속 대기하고 있을 수도 있어서 
						aa[i] = q1.poll(); // 해당 창구에 채우기
						aa[i].aStartTime = curTime; // 현재 시간을 시작 시간으로 
						aa[i].aEndTime = curTime + a[i]; // 걸리는 시간 + 현재 시간을 종료 시간으로
					}
				}
			}
		}
	}
	
	static void checkSecond(int cur){
		
		for(int i=1;i<=M;i++) {  // 기존 확인
			if(bb[i] != null) { // 창구에 고객이 존재할 때
				if(bb[i].bEndTime == curTime) { // 끝나면
					if(i == B && bb[i].aNum == A) res +=  bb[i].k;
					bb[i] = null; // 창구 비우기 
					finish++;
				}
			}
			
		}
		
		for(int i=1;i<=M;i++) {  
			if(bb[i] == null) { // 비어 있는 접수 창구가 있으면
				if(!q2.isEmpty()) { // 큐에 남은 요소 존재할 때 
					if(q2.peek().aEndTime <= curTime) { // 도착 이후 계속 대기하고 있을 수도 있어서 
						bb[i] = q2.poll(); // 해당 창구에 채우기
						bb[i].aStartTime = curTime; // 현재 시간을 시작 시간으로 
						bb[i].bEndTime = curTime + b[i]; // 걸리는 시간 + 현재 시간을  종료 시간으로
					}
				}
			}
		}
		
	}
}