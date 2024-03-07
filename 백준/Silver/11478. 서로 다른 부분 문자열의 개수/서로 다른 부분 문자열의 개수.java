import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Main{
	
	static Set<String> set;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb;
		
		set = new HashSet<String>();
		
		String tmp = br.readLine();
		
		// 1개 부터 N개까지
		for(int c=1;c<=tmp.length();c++) {
			for(int idx=0;idx<tmp.length()-c+1;idx++) { // 시작 인덱스 
				sb = new StringBuilder();
				for(int j=idx;j<idx+c;j++) {
					sb.append(tmp.charAt(j));
				}
				set.add(String.valueOf(sb));
			}
		}
		
		bw.write(String.valueOf(set.size()));
		bw.flush();
		br.close();
		bw.close();
	}
}