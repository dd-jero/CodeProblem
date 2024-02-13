import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main{
	
	static int N, res,cntFive,cntThree;
	static boolean flag;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		
		while(true) {
			
			if(N<0) {
				flag = true; 
				break;
			}else if(N==0) break;
			
			
			if(N % 15 == 0 || N % 5 == 0) {
				N -= 5;
				cntFive++;
			}
			else{
				N -= 3;
				cntThree++;
			}
		}
		
		if(!flag) System.out.println(cntFive + cntThree);
		else System.out.println(-1);
	}
}