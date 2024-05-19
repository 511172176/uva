import java.util.Scanner;

public class UVA1595 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		while(t-->0) {
			int n = sc.nextInt();
			int[][] r = new int[n][2];
			int sumr = 0;
			
			if(n<2) {
				System.out.println("YES");
				continue;
			}
			
			for(int i=0; i<n; i++) {
				r[i][0] = sc.nextInt();
				r[i][1] = sc.nextInt();
				sumr += r[i][0];
			}
			double avgr = (double) sumr/n;
			boolean is = true;
			
			for(int i=0; i<n; i++) {
				boolean has = false;
				
				for(int j=0; j<n; j++) {
					if(r[i][1]==r[j][1] && (r[i][0]+r[j][0])/(double)2 == avgr) {
						has = true;
						break;
					}
				}
				
				if(!has) {
					is = false;
					break;
				}
			}
			
			if(!is)
				System.out.println("NO");
			else
				System.out.println("YES");
		}
		
		sc.close();
	}

}
