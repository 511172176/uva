import java.util.*;

public class uva11389 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			int n = sc.nextInt();
			int d = sc.nextInt();
			int r = sc.nextInt();
			
			if(n==0 && d==0 && r==0) break;
			
			int[] day = new int[n];
			int[] night = new int[n];
			
			for(int i=0; i<n; i++)
			{
				day[i] = sc.nextInt();
			}
			
			for(int i=0; i<n; i++)
			{
				night[i] = -sc.nextInt();
			}
			
			Arrays.sort(day);
			Arrays.sort(night);
			
			int sum = 0;
			
			for(int i=0; i<n; i++)
			{
				int count = day[i] - night[i];
				if(count > d)
				{
					sum += (count-d) * r;
				}
			}
			
			System.out.println(sum);
		}
		sc.close();
	}
	

}
