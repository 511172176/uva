//package uva;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class uva10107 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		ArrayList<Integer> ar = new ArrayList<Integer>();
		int index = 1;
		while(sc.hasNext())
		{
			int n = sc.nextInt();
			ar.add(n);
			Collections.sort(ar);
			int size = ar.size();
			//int i = index;
			
			/*for(int i=1; i<=index; i++)
			{
				int j = i-1;
				int temp = ar[i];
				while(j>0 && ar[j]>temp)
				{
					ar[j+1] = ar[j];
					j--;
				}
				ar[j+1] = temp;
			}*/
			
			if(index%2==0)
				System.out.println((ar.get(size/2)+ar.get(size/2-1))/2);
			else
				System.out.println(ar.get(size/2));
			index++;
			
		}
		sc.close();
	}

}
