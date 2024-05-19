import java.util.*;

public class UVA1421 {
    
	static int maxn = 5000+5, n;
	static double pi = Math.acos(-1.0);
	static int[] D = new int[maxn];
	static int[] L = new int[maxn];
	static int[] R = new int[maxn];
	
    public static void main(String[] args) {
        
    	Scanner sc = new Scanner(System.in);
    	
    	int T = sc.nextInt();
    	
    	for(int ti=0; ti<=T; ti++) {
    		
    		R[0] = sc.nextInt();
    		n = sc.nextInt();
    		
    		for(int i=1; i<=n; i++) {
    			
    			D[i] = sc.nextInt();
    			L[i] = sc.nextInt();
    			R[i] = sc.nextInt();
    		}
    		boolean f1 = check();
    		
    		if(!f1) {
    			for(int i=0; i<=n; i++) {
    				
    				boolean ok = true;
    				double an = 0, ax = pi;
    				
    				for(int j=0; j<=n; j++) {
    					
    					double[] a = new double[2];
    					geta(L[i], D[i], j, a);
    					
    					if(a[0]>ax || a[1]<an) {
    						ok = false;
    						break;
    					}
    					an = Math.max(an, a[0]);
    					ax = Math.min(ax, a[1]);
    				}
    				if(ok) {
    					f1 = true;
    					break;
    				}
    			}
    		}
    		System.out.println(f1? "YES": "NO");
    	}
		sc.close();
    }
    static double geta3(int x0, int x1, int y0, int y1) {
    	return (y1-y0)*1.0/(x1-x0);
    }
    
    static double geta2(int x0, int x1, int y0, int y1) {
    	if(x1==x0) return pi/2;
    	double a = Math.atan(geta3(x0, x1, y0, y1));
    	if(a<0) return a+pi;
    	return a;
    }
    
    static void geta(int x0, int y0, int index, double[] a) {
    	if(D[index]==y0) {
    		a[0] = 0;
    		a[1] = pi;
    	}
    	else if(D[index]>y0) {
    		a[0] = geta2(x0, R[index], y0, D[index]);
    		a[1] = geta2(x0, L[index], y0, D[index]);
    	}
    	else {
    		a[0] = geta2(x0, L[index], y0, D[index]);
    		a[1] = geta2(x0, R[index], y0, D[index]);
    	}
    }
    
    static boolean check() {
    	int an = 0, ax = R[0];
    	for(int i=0; i<=n; i++) {
    		an = Math.max(an, R[i]);
    		ax = Math.min(ax, R[i]);
    	}
    	return an <= ax;
    }
}

