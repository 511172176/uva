import java.util.*;

public class UVA1513 {

	static int offset, t, n, m, x;
	static int[] movie, b, tree;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		t = sc.nextInt();
		
		while(t-->0) {
			
			n = sc.nextInt();
			m = sc.nextInt();
			
			offset = n+m;
			movie = new int[offset+5];
			b = new int[m+5];
			tree = new int[offset+5];
			
			for(int i=1; i<=n; i++) {
				
				movie[i] = i+m;
				insert(movie[i], 1);
			}
			
			for(int i=1; i<=m; i++) {
				
				x = sc.nextInt();
				b[i] = clac(movie[x]-1);
				insert(movie[x], -1);
				movie[x] = m-i+1;
				insert(movie[x], 1);
			}
			
			for(int i=1; i<=m; i++) {
				
				System.out.print(b[i]+"　");
			}
			System.out.println();
		}
	}
	
	static int clac(int a) {
		int sum = 0;
		while(a>0) {
			sum += tree[a];
			a -= lowbit(a);
		}
		return sum;
	}
	
	static int lowbit(int a) {
		return a & -a;
	}
	
	static void insert(int a, int b) {
		while(a<=offset) {
			tree[a] += b;
			a += lowbit(a);
		}
	}
}
