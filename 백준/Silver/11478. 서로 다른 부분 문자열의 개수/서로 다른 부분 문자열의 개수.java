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
		int size = tmp.length();
		for(int i=0;i<size;i++) {
			for(int j=i+1;j<size+1;j++) {
				set.add(tmp.substring(i,j));
			}
		}
		
		bw.write(String.valueOf(set.size()));
		bw.flush();
		br.close();
		bw.close();
	}
}