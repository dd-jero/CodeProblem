import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge>{
	
	int start;
	int end;
	int weight;
	
	public Edge(int start, int end, int weight) {
		this.start = start;
		this.end = end;
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge o) {
		return this.weight - o.weight; // 가중치 오름차순 
	}
}

// 크루스칼 알고리즘 
class Main{
	
	static int V,E;
	static int A,B,C;
	static Edge[] edgeList;
	static int[] parents;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken()); // 정점 수
		E = Integer.parseInt(st.nextToken()); // 간선 수
		
		edgeList = new Edge[E];
		
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken()); // 시작
			B = Integer.parseInt(st.nextToken()); // 끝
			C = Integer.parseInt(st.nextToken()); // 가중치 
			
			edgeList[i] = new Edge(A, B, C);
		} // 입력 완료
		
		Arrays.sort(edgeList); // 정렬 
		
		makeSet(); 
		
		int cnt = 0;
		Long minWeight = 0L;
		
		for(Edge e : edgeList) {
			if(!union(e.start, e.end)) continue; // 이미 같은 트리이면 무시
			
			union(e.start,e.end);
			cnt++;
			minWeight += e.weight;
			
			if(cnt == V-1) break; // 간선의 수가 정점 - 1개 되면 종료 
		}
		
		bw.write(String.valueOf(minWeight));
		bw.flush();
		
		br.close();
		bw.close();
		
	}
	
	static void makeSet() { // 전처리 => 자신만으로 이루어진 트리 형성 
		
		parents = new int[V+1];
		
		for(int i=1;i<=V;i++) {
			parents[i] = i;
		}
	}
	
	static int findSet(int a) {
		if(a == parents[a]) return a; // 자신과 루트가 동일하면 반환
		return parents[a] = findSet(parents[a]); // a의 루트를 찾아 a의 부모 배열에 저장 (경로 압축 방법)
	}
	
	static boolean union(int a, int b) {
		
		a = findSet(a);
		b = findSet(b);
		
		if(a==b) return false; // 이미 같은 트리 내에 존재
		
		parents[b] = a; // b의 루트를 a로 변경 
		return true;
		
	}
}