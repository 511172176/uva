import java.util.*;

public class uva1267 {
	
	static int maxn = 1000+5;
	static int t, n, s, k, a, b;
	static int[] fa = new int[maxn];
	static int[] vis = new int[maxn];
	static ArrayList<Integer>[] graph = new ArrayList[maxn];
	static ArrayList<Integer>[] leaf = new ArrayList[maxn];
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		t = sc.nextInt();
		
		while(t-->0) {
			
			n = sc.nextInt();
			s = sc.nextInt();
			k = sc.nextInt();
			
			for(int i=1; i<=n; i++) {
				
				graph[i] = new ArrayList<>();
				leaf[i] = new ArrayList<>();
				
			}
			
			for(int i=1; i<n; i++) {
				
				a = sc.nextInt();
				b = sc.nextInt();
				graph[a].add(b);
				graph[b].add(a);
				
			}
			
			Arrays.fill(fa, -1);
			getfa(s, -1, 1);
			Arrays.fill(vis, 0);
			
			System.out.println(slove());
			
		}
	}
	
	static void getfa(int s, int f, int d) {
		if(graph[s].size() == 1) {
			if(d>k+1)
				leaf[d].add(s);
			return;
		}
		for(int t: graph[s]) {
			if(t==f) continue;
			fa[t] = s;
			getfa(t,s,d+1);
		}
	}
	
	static void dfs(int s, int f, int d) {
		if(d>=k) return;
		for(int t: graph[s]) {
			if(t == f) continue;
			vis[t] = 1;
			dfs(t, s, d+1);
		}
	}
	
	static int slove() {
		int ans = 0;
		for(int i=n; i>0; i--) {
			for(int t: leaf[i]) {
				if(vis[t]==0) {
					vis[t] = 1;
					int f = fa[t];
					for(int j=1; j<k; j++) {
						f = fa[f];
					}
					vis[f]=1;
					ans++;
					dfs(f, -1, 0);
				}
			}
		}
		return ans;
	}
}
