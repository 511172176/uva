import java.util.*;

/**
 * UVA406B
 */
public class UVA406B {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = 1000;
        boolean[] p = new boolean[N+1];
        p[0] = p[1] = true;
        for(int i=2; i<=Math.sqrt(N); i++){
            for(int j=i*i; j<=N; j+=i){
                p[j] = true;
            }
        }
        p[1] = false;
        int[] ps = new int[N+1];
        for(int i=1; i<ps.length; i++){
            ps[i] += ps[i-1];
            if(!p[i]) ps[i]++;
        } 

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            int c = sc.nextInt();
            System.out.print(n+" "+c+":");
            int si = ps[n]%2 == 0? ps[n]/2: ps[n]/2+1;
            si -= (c-1);
            int ei = si + (ps[n]%2 == 0? 2*c-1: 2*c-2);

            int count=0;
            for(int i=1; i<=n; i++){
                if(!p[i]){
                    count++;
                    if(count>=si && count<=ei)
                        System.out.print(" " + i);
                }
            }
            System.out.println("\n");
        }
        sc.close();
    }
}