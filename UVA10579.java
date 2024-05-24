import java.math.BigInteger;
import java.util.*;

/**
 * UVA10579 
 */
//Dynamic Programming && BigInteger

public class UVA10579 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            System.out.println(fib(n));
        }
        sc.close();
    }
    public static BigInteger fib(int n){
        if(n==0) return BigInteger.ZERO;
        else if(n==1 || n==2) return BigInteger.ONE;

        BigInteger[] dp = new BigInteger[n+1];
        dp[0] = BigInteger.ZERO;
        dp[1] = dp[2] = BigInteger.ONE;
        for(int i=3; i<=n; i++)
            dp[i] = dp[i-1].add(dp[i-2]);
        return dp[n];
    }
}