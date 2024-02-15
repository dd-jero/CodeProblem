import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {

	static int N, M, K, res;
	static Node[][] map;
	static PriorityQueue<Node> q;

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	static class Node implements Comparable<Node> {
		int x;
		int y;
		int size;
		int dir;
		int time;

		Node(int x, int y, int size, int dir, int time) {
			this.x = x;
			this.y = y;
			this.size = size;
			this.dir = dir;
			this.time = time;
		}

		@Override
		public int compareTo(Node o) {
			return o.size - this.size; // 미생물 수에 따른 오름차순 
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int T = Integer.parseInt(st.nextToken());

		for (int t = 1; t <= T; t++) {
			// 첫 번째 줄
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken()); // 셀 크기 
			M = Integer.parseInt(st.nextToken()); // 시간
			K = Integer.parseInt(st.nextToken()); // 미생물 수

			res = 0;
			map = new Node[N][N];
			q = new PriorityQueue<>();

			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int size = Integer.parseInt(st.nextToken());
				int dir = Integer.parseInt(st.nextToken()) - 1; // 인덱스로 활용 
				q.add(new Node(x, y, size, dir, 0));
			}

			bfs(); 

			System.out.println("#" + t + " " + res);

		}
	}

	private static void bfs() {
		
		while (!q.isEmpty()) {
			Node p = q.poll();

			// 시간이 모두 지나면 종료
			if (p.time == M) {
				res += p.size;

				while (!q.isEmpty()) {
					p = q.poll();
					res += p.size;
				}

				return;
			}

			int nx = p.x + dx[p.dir];
			int ny = p.y + dy[p.dir];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				
				// 가장자리라면
				if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
					p.size /= 2; // 사이즈를 반으로 만듦

					if (p.dir == 0) { 
						p.dir = 1;
					} else if (p.dir == 1) {
						p.dir = 0;
					} else if (p.dir == 2) {
						p.dir = 3;
					} else if (p.dir == 3) {
						p.dir = 2;
					}
				}

				Node before = map[nx][ny]; // 동일 좌표의 군집 
				
				// 맵에 동일좌표 군집이 존재한다면 값을 비교
				if (before != null) {
					// 현재 값이 더 크다면
					if (before.size < p.size) {
						before.dir = p.dir; // 방향 수정 
					}
					
					before.size += p.size; // 미생물 수 합치기 

				}
				// 동일 좌표 군집이 존재하지 않는다면
				else {
					map[nx][ny] = new Node(nx, ny, p.size, p.dir, p.time + 1);
				}
			}
		} 

		// 모든 미생물 처리가 끝나면 맵을 탐색하여 미생물을 q에 저장
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				if (map[i][j] != null) {
					q.add(map[i][j]);
				}
			}
		}

		// map 초기화
		map = new Node[N][N];
		bfs();
	}
}