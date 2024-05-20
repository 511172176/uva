import java.util.*;
 
public class uva406 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int N = 1000;
        boolean prime[] = new boolean[N+1];
        prime[0] = true;
        prime[1] = true;
        for(int i=2; i<=Math.sqrt(N); i++)
        {
        	for(int j=i*i; j<=N; j+=i)
        	{
        		prime[j] = true;
        	}
        }
        prime[1] = false;
        
        int primes[] = new int[1001];
        for(int i=1; i<prime.length; i++)
        {
        	primes[i] += primes[i - 1];
        	if(!prime[i]) primes[i] ++;
        }
 
        while (in.hasNext()) {
            int n = in.nextInt();
            int c = in.nextInt();
            int startIndex = (primes[n] % 2 == 0) ? (primes[n] / 2) : (primes[n] / 2 + 1);
            startIndex -= (c - 1);
            startIndex = startIndex > 0 ? startIndex : 1;
            int endIndex = startIndex + ((primes[n] % 2 == 0) ? (2 * c - 1) : (2 * c - 2));
            endIndex = endIndex > n ? n : endIndex;
 
            System.out.print(n + " " + c + ":");
            
            int index = 0;
            for (int i = 1; i <= n; i++) {
                if (!prime[i]) {
                    index++;
                    if (index >= startIndex && index <= endIndex) {
                        System.out.print(" " + i);
                    }
                }
            }
            System.out.println();
            System.out.println();
        }
        in.close();
    }
}