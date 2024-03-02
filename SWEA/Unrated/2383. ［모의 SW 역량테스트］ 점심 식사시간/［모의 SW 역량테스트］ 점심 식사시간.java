import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class People implements Comparable<People>{
	
	int x;
	int y;
	int time; // 이동 시간 + 계단 내려가는 시간 
	
	public People(int x, int y, int time) {
		this.x = x;
		this.y = y;
		this.time = time;
	}

	@Override
	public String toString() {
		return "People [x=" + x + ", y=" + y + ", time=" + time + "]";
	}

	@Override
	public int compareTo(People o) {
		return this.time - o.time;
	}
}

class Solution{
	
	static int TC,N,res,pSize;
	static int[][] map;
	static List<People> pList;
	static List<int[]> sList;
	static boolean[] checkP;
	static int s1x,s1y,s2x,s2y,K1,K2;
	static List<People> list1,list2; // 이동 시간에 따른 오름차순 
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			N = Integer.parseInt(br.readLine());
			
			res = Integer.MAX_VALUE;
			map = new int[N][N];
			pList = new ArrayList<People>();
			sList = new ArrayList<int[]>();
			
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					
					if(map[i][j] == 1) pList.add(new People(i,j,0)); // 사람 위치
					else if(map[i][j] > 1) sList.add(new int[] {i,j}); // 계단 위치 
				}
			} // 입력 완료 
			
			pSize = pList.size();
			s1x = sList.get(0)[0];
			s1y = sList.get(0)[1];
			s2x = sList.get(1)[0];
			s2y = sList.get(1)[1];
			K1 = map[s1x][s1y];
			K2 = map[s2x][s2y];
			
			
			checkP = new boolean[pList.size()];
			list1 = new ArrayList<People>();
			list2 = new ArrayList<People>();
			
			recur(0);
			sb.append("#"+t+" "+res+"\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		
		br.close();
		bw.close();
	}
	
	static void recur(int cnt) { // 부분 집합 (계단 1에 포함할지, 안할지)
		
		if(cnt == pSize) { // 모든 사람을 고려했으면 
			
			for(int i=0;i<pSize;i++) { // true, false에 따른 계단 사용자 분배 
				int px = pList.get(i).x;
				int py = pList.get(i).y;
				
				// 각 계단에 따른 사람 삽입 
				if(checkP[i]) list1.add(new People(px,py,Math.abs(px-s1x)+Math.abs(py-s1y)));
				else list2.add(new People(px,py,Math.abs(px-s2x)+Math.abs(py-s2y)));
				
			} // 분배 완료
			
			Collections.sort(list1);
			Collections.sort(list2);
			move();
//			System.exit(0);
			return; 
		}
		
		checkP[cnt] = true; // 계단 1로
		recur(cnt+1);
		checkP[cnt] = false; // 계단 2로 
		recur(cnt+1);
	}
	
	static void move() { // 각 계단까지 이동하기 
		
		// 각 PQ에 앞의 3개씩 time -1 진행 (time =0이 되면 삭제, 아니면 다시 pq 삽입)
		int timeCnt = 0;
		int useCnt1 = 0;
		int useCnt2 = 0;
		
		while(true) {
			
//			System.out.println("start");
//			System.out.println(list1);
//			System.out.println(list2);
//			System.out.println("cnt1: "+useCnt1+" cnt2: "+ useCnt2);
//			System.out.println("end");
			
			
			if(list1.isEmpty() && list2.isEmpty()) { // 더이상 내려갈 사람 없으면 리턴
				res = timeCnt < res ? timeCnt : res;
				return; 
			}
			
			for(int i=0;i<list1.size();i++) { // 계단 1로
				People curP =list1.get(i);
				if(curP.time < 0) { // 현재 계단을 내려가고 있는 사람이 있으면 
					if(Math.abs(curP.time) == K1) {// 계단을 다 내려가면 
						list1.remove(i--);
					}else { // 아직 내려가는 중이면 
						curP.time--;
					}
				}else if(curP.time == 0) { // 계단에 도착 했으면 
					if(checkCnt(list1) < 3) { // 계단을 이용할 수 있다면
						curP.time--;
					}
				}else if(curP.time > 0) { // 이동 중이라면 
					curP.time--;
				}
			}
			
			for(int i=0;i<list2.size();i++) { // 계단 1로
				People curP =list2.get(i);
				if(curP.time < 0) { // 현재 계단을 내려가고 있는 사람이 있으면 
					if(Math.abs(curP.time) == K2) {// 계단을 다 내려가면 
						list2.remove(i--);
					}else { // 아직 내려가는 중이면 
						curP.time--;
					}
				}else if(curP.time == 0) { // 계단에 도착 했으면 
					if(checkCnt(list2) < 3) { // 계단을 이용할 수 있다면
						curP.time--;
					}
				}else if(curP.time > 0) { // 이동 중이라면 
					curP.time--;
				}
			}
			
			timeCnt++;
			
		}
	}
	
	static int checkCnt(List<People> li) {
		int cnt = 0;
		
		for(int i=0;i<li.size();i++) {
			if(li.get(i).time < 0) {
				cnt++;
			}
		}
		
		return cnt;
	}
	
}