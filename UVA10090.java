import java.util.Scanner;

public class UVA10090 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			long n = sc.nextInt();
			if(n==0) break;
			
			long c1 = sc.nextLong();
			long n1 = sc.nextLong();
			long c2 = sc.nextLong();
			long n2 = sc.nextLong();
			
			long[] r = ex(n1,n2);
			long x = r[0], y = r[1], z = r[2];
			long lower = (long) Math.ceil(-1.0 * n * x/n2);
			long upper = (long) Math.floor(1.0 * n * y/n1);
			
			if(n%z !=0 || lower>upper) {
				System.out.print("failed");
			}
			else if(c1*n2 >= c2*n1) {
				x = x * n/z + n2/z * lower;
				y = y * n/z - n1/z * lower;
				System.out.println(x+" "+y);
			}
			else {
				x = x * n/z + n2/z * upper;
				y = y * n/z - n1/z * upper;
				System.out.println(x+" "+y);
			}
		}
		sc.close();
		
	}
	public static long[] ex(long a, long b) {
		if(b==0) 
			return new long[] {1, 0, a};
		
		long[] re = ex(b, a%b);
		long z = re[2];
		long x = re[1];
		long y = re[0] - re[1] * (a/b);
		
		return new long[] {x, y, z};
	}

}
