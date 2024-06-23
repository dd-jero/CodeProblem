import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution{

    static int N;
    static Node[] nodeArr;
    static StringBuilder sb;

    static class Node{

        int cur;
        char info;
        int leftchild;
        int rightchild;
        
		public Node(int cur, char info) {
			this.cur = cur;
			this.info = info;
		}

		@Override
		public String toString() {
			return "Node [cur=" + cur + ", info=" + info + ", leftchild=" + leftchild + ", rightchild=" + rightchild
					+ "]";
		}
		
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        sb = new StringBuilder();
        

        // 10개의 테케 주어짐.
        for(int t=1;t<=10;t++){

            N = Integer.parseInt(br.readLine()); // 트리 정점의 수
            nodeArr = new Node[N+1];
            
            for(int i=1;i<N+1;i++) {
            	st = new StringTokenizer(br.readLine());
            	
            	// 노드 정보 입력
            	int num = Integer.parseInt(st.nextToken()); // 현재 번호
            	char info = st.nextToken().charAt(0); // 알파벳
            	
            	Node node = new Node(num, info);
            	
            	if(st.hasMoreTokens()) { // 왼쪽 자식
            		node.leftchild = Integer.parseInt(st.nextToken());
            	}else {
            		
            	}
            	
            	if(st.hasMoreTokens()) { // 오른 자식
            		node.rightchild = Integer.parseInt(st.nextToken());
            	}
            	
            	// 해당 노드 저장
            	nodeArr[i] = node; 
            }
            
            sb.append("#"+t+" ");
        	inorder(1);
        	sb.append("\n");
            
        }
        
        bw.write(String.valueOf(sb));
        bw.flush();
        br.close();
        bw.close();
    }

	private static void inorder(int curNum) { // 중위 순회
		
		Node curNode = nodeArr[curNum];
		
		if(curNode.leftchild != 0) {
			inorder(curNode.leftchild); // 왼쪽 자식
		}
		
		sb.append(curNode.info); // 해당 노드 알파벳 저장
		
		if(curNode.rightchild != 0) {
			inorder(curNode.rightchild); // 오른 자식 
		}
	}
}