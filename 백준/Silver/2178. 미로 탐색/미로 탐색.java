import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int dir[][] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	
	static int n, m;
	static int arr[][];
	static int way[][];
	static boolean visited[][];
	
	static Queue<Integer> qx = new ArrayDeque<>();
	static Queue<Integer> qy = new ArrayDeque<>();
	
	static int ans = 98765432;
	static int leng = 0;
	
	static void bfs() {
		int cx, cy;
		int nx, ny;
		while(!qx.isEmpty() && !qy.isEmpty()) {			
			cx = qx.element();
			cy = qy.element();
			qx.poll();
			qy.poll();
						
			if(cx== m-1 && cy==n-1)	continue;
			
			for(int i =0; i<4; i++) {
				nx = cx+dir[i][0];
				ny = cy+dir[i][1];
				if(0<=nx && nx<m  && 0<=ny && ny<n) {
					if(visited[ny][nx] || arr[ny][nx] == 0) continue; 
					visited[ny][nx] = true;
					
					if(way[ny][nx] > way[cy][cx] +1) way[ny][nx] = way[cy][cx] +1;
					qx.offer(nx);
					qy.offer(ny);
				}
			}
		}
	}
	/*
	
	static void dfs(int leng, int cx, int cy) {
		if(leng >=ans) return;
		if(cx == m-1 && cy == n-1) {
			if (leng < ans) ans = leng;
			return;
		}
		
		int x, y;
		for(int i=0; i<4; i++) {
			x = cx+dir[i][0];
			y = cy+dir[i][1];
			if(0<=x && x<m  && 0<=y && y<n) {
				if(visited[y][x] || arr[y][x] == 0) continue; 
				visited[y][x] = true;
				dfs(leng+1, x, y);
				visited[y][x] = false;
			}
		}
	}
	
	*/
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st=new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); //세로 맥스
		m = Integer.parseInt(st.nextToken()); //가로 맥스
		
		way = new int[n][m];
		arr = new int[n][m];
		visited = new boolean[n][m];
		
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < m; j++) {
		        way[i][j] = 987654321;
		    }
		}
		
		String line;
		for(int i =0; i<n; i++) {
			line = br.readLine();
			for(int j =0; j<m; j++) {
				arr[i][j] = line.charAt(j) -'0';
			}
		}
		
		visited[0][0] = true;
		way[0][0] = 1;
		qx.offer(0);
		qy.offer(0);
		bfs();
		System.out.println(way[n-1][m-1]);
		
		br.close();
	}
}
