import java.util.Scanner;

public class UVA11456 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n-->0) {
			
			int m = sc.nextInt();
			int[] r = new int[m];
			
			for(int i=0; i<m; i++) {
				r[i] = sc.nextInt();
			}
			
			int ans = 0;
			int lis[] = new int[m];
			int lds[] = new int[m];
			
			for(int i=m-1; i>=0; i--) {
				lis[i] = 1;
				lds[i] = 1;
				
				for(int j=m-1; j>=i; j--) {
					if(r[j]>r[i]) {
						lds[i] = Math.max(lds[i],lds[j]+1);
					}
					if(r[j]<r[i]) {
						lis[i] = Math.max(lis[i],lis[j]+1);
					}
				}
				
				ans = Math.max(ans,lis[i]+lds[i]-1);
			}
			System.out.println(ans);
		}
		sc.close();
	}
}
