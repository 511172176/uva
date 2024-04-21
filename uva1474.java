import java.util.*;

public class uva1474 {
    
	static int N = 4000+5, n, m;
	static long inf = 0x3f3f3f3f3f3f3f3fL;
	static int[] s_d = new int[N], s_id = new int[N];
	static int[] p_d = new int[N], p_id = new int[N];
	static int[] ans = new int[N];
	static int[][] path = new int[N][N];
	static long[][] dp = new long[2][N];
	
    public static void main(String[] args) {
    	
    	Scanner sc = new Scanner(System.in);
    	
    	init(sc);
    	System.out.println(slove());
    	put(n, m);
    	for(int i=1; i<n; i++) {
    		System.out.print(ans[i]+" ");
    	}
    	System.out.println(ans[n]);
    }
    
    static void put(int x, int y) {
    	if(x==0 || y==0) return;
    	ans[s_id[x]] = p_id[y];
    	put(x-1, y-path[x][y]);
    }
    
    static long slove() {
    	for(int i=1; i<=m; i++)
    		dp[0][i] = inf;
    	dp[0][0] = 0;
    	
    	for(int i=1; i<=n; i++) {
    		int u = i%2;
    		int v = 1-u;
    		Arrays.fill(dp[u], inf);
    		
    		for(int j=1; j<=m && j<=i; j++) {
    			if(dp[v][j-1]<dp[v][j]) {
    				dp[u][j] = dp[v][j-1] + Math.abs(s_d[i]-p_d[j]);
    				path[i][j] = 1;
    			}
    			else {
    				dp[u][j] = dp[v][j] + Math.abs(s_d[i]-p_d[j]);
    				path[i][j] = 0;
    			}
    		}
    	}
    	return dp[n%2][m];
    }
    
    static void sort(int[] d, int[] id, int start, int end) {
    	Integer[] r = new Integer[end-start];
    	
    	for(int i=0; i<r.length; i++) {
    		r[i] = i+start;
    	}
    	Arrays.sort(r, (i1, i2) ->{
    		if(d[i1]!=d[i2]) {
    			return Integer.compare(d[i1], d[i2]);
    		}
    		return Integer.compare(id[i1], id[i2]);
    	});
    	int[] tempd = d.clone();
    	int[] tempid = id.clone();
    	
    	for(int i=0; i<r.length; i++) {
    		d[i+start] = tempd[r[i]];
    		id[i+start] = tempid[r[i]];
    	}
    }
    
    static void init(Scanner sc) {
    	n = sc.nextInt();
    	for(int i=1; i<=n; i++) {
    		s_d[i] = sc.nextInt();
    		s_id[i] = i;
    	}
    	m = sc.nextInt();
    	for(int i=1; i<=m; i++) {
    		p_d[i] = sc.nextInt();
    		p_id[i] = i;
    	}
    	sort(s_d, s_id, 1, n+1);
    	sort(p_d, p_id, 1, m+1);
    }
}
