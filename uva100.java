import java.util.*;
 
public class uva100 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            
            int a = sc.nextInt();
            int b = sc.nextInt();
            int len = 0;
            System.out.print(a+" "+b+" ");

            for(int i=Math.min(a, b); i<=Math.max(a, b); i++)
            {

                len = Math.max(len(i), len);
                
            }
            System.out.println(len);
        }
    }

    public static int len(int n)
    {
        
        int leng = 1;
        while(n!=1)
        {

            if(n%2==1)
                n = 3*n+1;
            else if(n%2==0)
                n /=2;
            leng++;
        }
        return leng;
    }
}