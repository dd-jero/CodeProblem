import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    static int N,M,R;
    static int cmd;
    static int[][] arr;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        arr = new int[N][M];

        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++) {
                arr[i][j]= Integer.parseInt(st.nextToken());
            }
        }

        // 입력 완료
        st = new StringTokenizer(br.readLine());
        
        for(int r=0;r<R;r++) {
        	cmd = Integer.parseInt(st.nextToken());
            if(cmd == 1){
                cmd1();
            }else if (cmd == 2){
                cmd2();
            }else if (cmd == 3){
                arr = cmd3();
            }else if (cmd == 4){
                arr = cmd4();
            }else if (cmd == 5){
                arr = cmd5();
            }else if (cmd == 6){
                arr = cmd6();
            }
        } // R번 연산

        for(int i=0;i<arr.length;i++) {
            for(int j=0;j<arr[0].length;j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        } // 출력

    }

    static void cmd1() { // 상하반전

    	
    	N = arr.length;
    	M = arr[0].length;
    	
        for(int i=0;i<N/2;i++) {
            int[] tmp = arr[i];
            arr[i] = arr[N-i-1];
            arr[N-i-1] = tmp;
        }

    }

    static void cmd2() { // 좌우반전
    	
    	N = arr.length;
    	M = arr[0].length;
    	
        for(int i=0;i<M/2;i++) {
            for(int j=0;j<N;j++) {
                int tmp = arr[j][i];
                arr[j][i] = arr[j][M-i-1];
                arr[j][M-i-1] = tmp;

            }
        }
    }

    static int[][] cmd3() { // 오른쪽으로 90도 회전
        
    	N = arr.length;
    	M = arr[0].length;
    	// 주어진 배열의 첫 행부터 임시 배열의 마지막 열에 들어가는 형태
    	int[][] tmp = new int[M][N];
    	
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			tmp[j][N-1-i] = arr[i][j];
    		}
    	}
    	
    	return tmp;
        
    }

    static int[][] cmd4() {
    	
    	N = arr.length;
    	M = arr[0].length;
    	
    	// 주어진 배열의 첫 행부터 임시 배열의 마지막 행 첫 열 부터 들어가는 형태
    	int[][] tmp = new int[M][N];
    	
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			tmp[M-1-j][i] = arr[i][j];
    		}
    	}
    	
    	return tmp;

    }

    static int[][] cmd5() {
    	
    	N = arr.length;
    	M = arr[0].length;
    	
    	int[][] tmp = new int[N][M];
    	
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			
    			if(0<=i && i<=(N/2-1) && 0<=j && j<=(M/2-1)) { // 1 -> 2
    				tmp[i][j+M/2] = arr[i][j];
    			}else if(0<=i && i<=(N/2-1) && (M/2)<=j && j<=(M-1)) { // 2 -> 3
    				tmp[i+N/2][j] = arr[i][j];
    			}else if((N/2)<=i && i<=(N-1) && (M/2)<=j && j<=(M-1)) { // 3 -> 4
    				tmp[i][j-M/2] = arr[i][j];
    			}else if((N/2)<=i && i<=(N-1) && 0<=j && j<=(M/2-1)) { // 4 -> 1
    				tmp[i-N/2][j] = arr[i][j];
    			}
    		}
    	}
    	
    	return tmp;
    }

    static int[][] cmd6() {
    	
    	N = arr.length;
    	M = arr[0].length;
    	
    	int[][] tmp = new int[N][M];
    	
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<M;j++) {
    			
    			if(0<=i && i<=(N/2-1) && 0<=j && j<=(M/2-1)) { // 1 -> 4
    				tmp[i+N/2][j] = arr[i][j];
    			}else if(0<=i && i<=(N/2-1) && (M/2)<=j && j<=(M-1)) { // 2 -> 1
    				tmp[i][j-M/2] = arr[i][j];
    			}else if((N/2)<=i && i<=(N-1) && (M/2)<=j && j<=(M-1)) { // 3 -> 2
    				tmp[i-N/2][j] = arr[i][j];
    			}else if((N/2)<=i && i<=(N-1) && 0<=j && j<=(M/2-1)) { // 4 -> 3
    				tmp[i][j+M/2] = arr[i][j];
    			}
    		}
    	}
    	
    	return tmp;

    }
}