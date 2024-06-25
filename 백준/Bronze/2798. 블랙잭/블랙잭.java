import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static int ans = 0;

	static int[] card;
	static boolean[] visited;
	
	static void combi(int cnt, int val, int start) {
		if(cnt == 3) {
			if(ans<val && val<=m) ans = val;
			return;
		}
		
		for(int i =start; i<n; i++) {
			if(visited[i]) continue;
			visited[i] = true;
			combi(cnt+1, val+card[i], i+1);
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		card = new int[n];
		visited = new boolean[n];
		
		 st = new StringTokenizer(br.readLine(), " ");
		for(int i =0; i<n; i++) {
			card[i] = Integer.parseInt(st.nextToken());
		}
		
		combi(0, 0, 0);
		System.out.println(ans);
	}
}
