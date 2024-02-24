import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Position{ // 사용자의 위치를 확인하기 위한 객체 
	int x; // 가로
	int y; // 세로 
	
	public Position(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public void move(int dir) { // 사용자의 위치 이동 
		
		switch(dir) {
		case 1: // 상
			y--;
			break;
		case 2: // 우
			x++;
			break;
		case 3: // 하
			y++;
			break;
		case 4: // 좌
			x--;
			break;
		}
	}
}
class AP{ // AP 정보
	
	int x; // 가로 위치
	int y; // 세로  위치
	int C; // 범위 
	int P; // 충전량 
	
	public AP(int x, int y, int c, int p) {
		this.x = x;
		this.y = y;
		C = c;
		P = p;
	}
}
class Solution{
	
	static int TC,M,A,res;
	static int[] pathA;
	static int[] pathB;
	static AP[] apList;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		TC = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=TC;t++) {
			
			st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken()); // 총 이동 시간
			A = Integer.parseInt(st.nextToken()); // BC의 개수
			
			// 사용자의 이동 정보 
			pathA = new int[M];
			pathB = new int[M];
			apList = new AP[A];
			res = 0;
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<M;i++) {
				pathA[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<M;i++) {
				pathB[i] = Integer.parseInt(st.nextToken());
			} 
			
			// 사용자 이동 정보 입력 완료 
			// AP 정보 입력 
			for(int i=0;i<A;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int C = Integer.parseInt(st.nextToken());
				int P = Integer.parseInt(st.nextToken());
				
				apList[i] = new AP(x,y,C,P);
			} // 모든 입력 완료
			
			// 각 사용자의 출발점
			Position userA = new Position(1,1);
			Position userB = new Position(10,10);
			
			charge(userA, userB); // 시작 위치에서의 충전 확인 
			
			for(int i=0;i<M;i++) { // M시간 동안 
				
				// 각각의 방향에 따라 이동 한뒤
				userA.move(pathA[i]);
				userB.move(pathB[i]);
				
				// 충전하기 
				charge(userA,userB);
			}
			sb.append("#"+t+" "+res+"\n");
		}
		
		bw.write(String.valueOf(sb));
		bw.flush();
		br.close();
		bw.close();
		
	}
	
	static void charge(Position userA, Position userB) { // 충전 하기 
		
		List<Integer> liA = new ArrayList<Integer>(); // 사용자 A가 사용 가능한 AP 목록
		List<Integer> liB = new ArrayList<Integer>(); // 사용자 B가 사용 가능한 AP 목록
		
		for(int i=0; i<A;i++) { // 각 사용자가 충전 가능한 AP 있으면 저장하기 위함.
			
			if(checkDist(userA.x, userA.y, apList[i].x, apList[i].y, apList[i].C)) {
				liA.add(i); // 사용자A가 해당 AP 사용 가능 하면 인덱스 저장
			}
			
			if(checkDist(userB.x, userB.y, apList[i].x, apList[i].y, apList[i].C)) {
				liB.add(i); // 사용자B가 해당 AP 사용 가능 하면 인덱스 저장
			}
		}
		
		// 각 리스트의 요소들을 확인해서 AP 겹치는지, 안 겹치는 지
		int tmpC = 0;
		int curMax = 0;
		
		if(liA.size() > 0 && liB.size() > 0) { // 두 사용자 모두 AP를 사용할 때 
			
			for(int a: liA) { // 두 사용자의 최대 충전량 완전탐색 
				for(int b: liB) {
					
					tmpC = 0; // 충전량 
					if(a==b) { // AP가 겹치면
						tmpC = apList[a].P; // 한번만 더하기 
						
					}else { // 다르면
						tmpC += apList[a].P; // 각 AP 충전량 더하기 
						tmpC += apList[b].P;
					}
					
					curMax = curMax < tmpC ? tmpC : curMax; // 현재 시간에서 구할 수 있는 최대 충전량 
				}
			}
		}else if(liA.size() > 0) { // 사용자 A만 사용할 때 
			
			for(int a : liA) { // A가 사용할 수 있는 AP중에
				
				if(curMax < apList[a].P) { // 가장 큰 것 고르기 
					curMax = apList[a].P;
				}
			}
			
		}else if(liB.size() > 0) { // 사용자 B만 사용할 때 
			
			for(int b : liB) { // B가 사용할 수 있는 AP중에
				
				if(curMax < apList[b].P) { // 가장 큰 것 고르기 
					curMax = apList[b].P;
				}
			}
		}
		
		// 현재 시간에서 최대 충전량을 누적
		res += curMax;
	}
	
	static boolean checkDist(int x, int y, int a, int b, int C) { // 충전 가능한지 확인 
		
		if(C >= (Math.abs(x-a)+Math.abs(y-b))) {
			return true; // 해당 AP에 대한 충전 가능
		}
		return false;
		
	}

	
}