import java.util.*;
import java.math.*;

public class uva10814 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		while(n-->0)
		{
			BigInteger a = sc.nextBigInteger();
			sc.next();
			BigInteger b = sc.nextBigInteger();
			
			BigInteger avg = a.gcd(b);
			System.out.println(a.divide(avg) + " / " + b.divide(avg));
		}
		sc.close();
	}

}
