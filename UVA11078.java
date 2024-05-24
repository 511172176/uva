import java.util.*;

/**
 * UVA11078
 */
public class UVA11078 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n-->0){
            int m = sc.nextInt();
            int[] lst = new int[m];
            
            for(int i=0; i<lst.length; i++)
                lst[i] = sc.nextInt();

            int max = Integer.MIN_VALUE;
            int i = lst[0]; 
            for(int j=1; j<lst.length; j++){
                max = Math.max(max, i-lst[j]); //i-j
                i = Math.max(i, lst[j]); //i<j
            }
            System.out.println(max);
        }
        sc.close();
    }
}