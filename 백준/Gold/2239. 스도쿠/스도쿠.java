import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class Main{
	
	static int[][] map;
	static List<int[]> zeroList;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		map = new int[9][9];
		zeroList = new ArrayList<int[]>();
		
		for(int i=0;i<9;i++) {
			String tmp = br.readLine();
			
			for(int j=0;j<9;j++) {
				map[i][j] = Character.getNumericValue(tmp.charAt(j));
				
				if(map[i][j] == 0) {
					zeroList.add(new int[] {i,j});
				}
			}
		} // 입력완료 
		
		
		dfs(0);
		
	}
	
	
	private static void dfs(int cnt) {
		
		if(cnt  == zeroList.size()) {
			for(int i=0;i<9;i++) {
				for(int j=0;j<9;j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
		}
		
		int x = zeroList.get(cnt)[0];
		int y = zeroList.get(cnt)[1];
		
		for(int n=1;n<10;n++) {
			
			// 행,열, 3x3 모두 겹치치 않으면
			if(checkRow(x,y,n) && checkCol(x,y,n) && checkRegion(x,y,n)) {
				map[x][y] = n;  
				dfs(cnt+1);
				map[x][y] = 0;
			}
		}
		
		
	}

	private static boolean checkRow(int x, int y, int number) { // 행에 겹치는 숫자 있는지 검사
		
		for(int i=0;i<9;i++) {
			if(map[x][i] == number) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean checkCol(int x, int y, int number) { // 열에 겹치는 숫자 있는지 검사
		for(int i=0;i<9;i++) {
			if(map[i][y] == number) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean checkRegion(int x, int y, int number) { // 3x3 영역에 겹치는 숫자 있는지 검사 
		int xStart = (x/3)*3;
		int yStart = (y/3)*3;
		
		for(int i=xStart;i<xStart+3;i++) {
			for(int j=yStart;j<yStart+3;j++) {
				if(map[i][j] == number) {
					return false;
				}
			}
		}
		return true;
	}
	
}