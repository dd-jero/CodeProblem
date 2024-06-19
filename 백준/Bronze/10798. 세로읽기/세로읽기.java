import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    static char[][] arr;
    static int len;
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder(); 

        arr = new char[5][15];
        len = 0;

        for(int i=0;i<5;i++){   
            String str = br.readLine();

            len = len < str.length() ? str.length() : len; 

            for(int j=0;j<str.length();j++){
                arr[i][j] = str.charAt(j);
            }
        }
        
        for(int i=0;i<len;i++){
            for(int j=0;j<5;j++){
                if(arr[j][i] != '\0') sb.append(arr[j][i]);
            }
        }

        bw.write(String.valueOf(sb));
        bw.flush();
        br.close();
        bw.close();
    }

}