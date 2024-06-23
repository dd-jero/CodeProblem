import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{

    static int N, res, num;

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        N = Integer.parseInt(br.readLine());
        num = 1;
        res = 1;

        while(true){

            if(N <= num){
                System.out.println(res);
                break;
            }

            num = num + 6 * res;
            res++;

        }

    }
}