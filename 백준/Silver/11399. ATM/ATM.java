import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int[] a;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		
		a = new int[n+1];
		a[0] = 0;
		st = new StringTokenizer(br.readLine());
		for(int i =1; i<=n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(a);
		
		int ans = 0;
		for(int i =1; i<=n; i++) {
			ans += a[i]*(n-i+1);
		}
		
		System.out.println(ans);
		br.close();
	}
}
