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
 
class People {
     
    int x;
    int y;
     
    public People(int x, int y) {
        this.x = x;
        this.y = y;
    }
 
}
 
class Solution{
     
    static int TC,N,res,pSize;
    static int[][] map;
    static List<People> pList;
    static List<int[]> sList;
    static boolean[] checkP;
    static int s1x,s1y,s2x,s2y,K1,K2;
    static List<Integer> list1,list2; // 이동 시간에 따른 오름차순 
     
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
                     
                    if(map[i][j] == 1) pList.add(new People(i,j)); // 사람 위치
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
             
            checkP = new boolean[pSize];
            list1 = new ArrayList<Integer>();
            list2 = new ArrayList<Integer>();
             
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
                if(checkP[i]) list1.add(Math.abs(px-s1x)+Math.abs(py-s1y));
                else list2.add(Math.abs(px-s2x)+Math.abs(py-s2y));
                 
            } // 분배 완료
              
             
            // 오름 차순 정렬 (이동 시간이 빠른 = 작은 수)
            Collections.sort(list1);
            Collections.sort(list2);
            move();
            return; 
        }
         
        checkP[cnt] = true; // 계단 1로
        recur(cnt+1);
        checkP[cnt] = false; // 계단 2로 
        recur(cnt+1);
    }
     
    static void move() { // 각 계단까지 이동하기 
         
        int timeCnt = 0;
         
        while(true) {
             
            if(list1.isEmpty() && list2.isEmpty()) { // 더이상 내려갈 사람 없으면 리턴
                res = timeCnt < res ? timeCnt : res;
                return; 
            }
             
            for(int i=0;i<list1.size();i++) { // 계단 1로
                int curTime = list1.get(i);
                if(curTime < 0) { // 현재 계단을 내려가고 있는 사람이 있으면 
                    if(Math.abs(curTime) == K1) {// 계단을 다 내려가면 
                        list1.remove(i--);
                    }else { // 아직 내려가는 중이면 
                        list1.set(i, curTime-1);
                    }
                }else if(curTime == 0) { // 계단에 도착 했으면 
                    if(checkCnt(list1) < 3) { // 계단을 이용할 수 있다면
                        list1.set(i, curTime-1);
                    }
                }else if(curTime > 0) { // 이동 중이라면 
                    list1.set(i, curTime-1);
                }
            }
             
            for(int i=0;i<list2.size();i++) { // 계단 1로
                int curTime =list2.get(i);
                if(curTime < 0) { // 현재 계단을 내려가고 있는 사람이 있으면 
                    if(Math.abs(curTime) == K2) {// 계단을 다 내려가면 
                        list2.remove(i--);
                    }else { // 아직 내려가는 중이면 
                        list2.set(i, curTime-1);
                    }
                }else if(curTime == 0) { // 계단에 도착 했으면 
                    if(checkCnt(list2) < 3) { // 계단을 이용할 수 있다면
                        list2.set(i, curTime-1);
                    }
                }else if(curTime > 0) { // 이동 중이라면 
                    list2.set(i, curTime-1);
                }
            }
             
            timeCnt++;
             
        }
    }
     
    static int checkCnt(List<Integer> li) { // 현재 계단 이용중인 사람 수 세기 
        int cnt = 0;
         
        for(int i=0;i<li.size();i++) {
            if(li.get(i) < 0) {
                cnt++;
            }
        }
         
        return cnt;
    }
     
}