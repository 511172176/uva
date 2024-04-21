import java.util.Scanner;

public class UVA10104 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			long a,b;
			long[] r = new long[3]; //X Y D
			a = sc.nextLong();
			b = sc.nextLong();
			ex(a, b, r);
			System.out.println(r[0]+" "+r[1]+" "+r[2]);
		}
	}
	public static void ex(long a, long b, long[] r) {
		if(b==0) {
			r[2] = a; //d
			r[0] = 1; //x
			r[1] = 0; //y
		}
		else {
			ex(b, a%b, r);
			long temp=r[0]; //x to temp
			r[0] = r[1]; //y to x
			r[1] = temp - r[1] * (a/b); //y=x-y(a/b)
		}
	}

}
