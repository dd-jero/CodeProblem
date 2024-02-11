import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Element{
	
	int num;
	int cnt;
	int when;
	
	public Element(int num, int cnt, int when) {
		this.num = num;
		this.cnt = cnt;
		this.when = when;
	}

	@Override
	public String toString() {
		return "Element [num=" + num + ", cnt=" + cnt + ", when=" + when + "]";
	}

	
}

class Main{
	
	static int N,M;
	static List<Integer> res;
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		res = new ArrayList<Integer>();
		
		PriorityQueue<Element> deq = new PriorityQueue<Element>(new Comparator<Element>() {

			@Override
			public int compare(Element o1, Element o2) {
				if(o1.cnt == o2.cnt) return o1.when - o2.when; // 추천 수 같으면 게시 일자 오름차순
				return o1.cnt-o2.cnt; // 추천 수 오름차순 
			}
		});

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<M;i++) {
			boolean flag = false;
			int number = Integer.parseInt(st.nextToken()); // 추천 받기
			
			if(deq.isEmpty()) { // 큐가 비어 있으면 
				deq.add(new Element(number,1,i)); // 삽입
				continue;
			}
			
			for(Element e:deq) {
				if(e.num == number) { // 이미 게시되어 있으면 추천 수 증가 
					deq.remove(e);
					deq.add(new Element(e.num, e.cnt+1, e.when));
					flag = true;
					break;
				}
			}
			
			if(!flag) {
				if(deq.size() >= N) deq.poll(); // 큐가 꽉 차있으면 
				
				deq.add(new Element(number,1,i)); // 삽입
			}
			
		}
		for(Element e:deq) {
			res.add(e.num);
		}
		
		Collections.sort(res);
		
		for(int n:res) {
			sb.append(n).append(" ");
		}
		
		System.out.println(sb);
	}
}