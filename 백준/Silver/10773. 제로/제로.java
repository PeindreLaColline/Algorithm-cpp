import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class Main {
	static int k;
	static ArrayDeque<Integer> q = new ArrayDeque<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		k = Integer.parseInt(br.readLine());
		int tmp;
		for(int i =0; i<k; i++) {
			tmp = Integer.parseInt(br.readLine());
			if(tmp==0) {
				q.removeLast();
			}
			else {
				q.offer(tmp);
			}
		}
		
		int num = q.size();
		int ans = 0;
		for(int i =0; i<num; i++) {
			ans += q.poll();
		}
		System.out.println(ans);
		
		br.close();
	}
}
