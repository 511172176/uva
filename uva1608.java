import java.util.HashMap;
import java.util.Scanner;

public class uva1608 {
    // 定義一個等於Integer的最大值的常數，用作一個"無窮大"的值
    static final int INF = Integer.MAX_VALUE;
    
    // 設定數組最大值為200010，這通常是根據問題要求來的
    static int maxn = 200010;
    // 定義三個靜態數組：a存儲輸入的數字，L和R分別存儲該數字左側和右側相同數字的位置
    static int[] a = new int[maxn];
    static int[] L = new int[maxn];
    static int[] R = new int[maxn];

    // 函數檢查l到r的子數列是否是"non-boring"
    static boolean solve(int l, int r) {
        // 基本情況：如果子數列只有一個或沒有元素，則該子數列是"non-boring"的
        if (l >= r) return true;
        
        for (int i = l, j = r; i <= j; i++, j--) {
            // 檢查元素i和j是否存在符合條件的左右側界限
            // 如果存在，則繼續遞歸檢查分割後的左右子數列
            if (L[i] < l && R[i] > r) return solve(l, i - 1) && solve(i + 1, r);
            if (L[j] < l && R[j] > r) return solve(l, j - 1) && solve(j + 1, r);
        }
        // 如果所有元素都不滿足條件，返回false
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // 讀取測試用例數量
        int t = sc.nextInt();

        // 遍歷每一個測試用例
        while (t-- > 0) {
            // 讀取數組的大小
            int n = sc.nextInt();
            HashMap<Integer, Integer> mp = new HashMap<>();

            // 填充數組a並初始化L數組
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
                // 如果該元素之前沒出現過，L[i]設為0，否則設為該元素最後出現的位置
                L[i] = mp.getOrDefault(a[i], 0);
                mp.put(a[i], i); // 更新該元素最後出現的位置
            }

            // 清空映射以初始化R數組
            mp.clear();

            // 填充R數組
            for (int i = n; i >= 1; i--) {
                // 如果該元素之後沒出現過，R[i]設為INF，否則設為該元素接下來會出現的位置
                R[i] = mp.getOrDefault(a[i], INF);
                mp.put(a[i], i); // 更新該元素即將出現的位置
            }

            // 檢查整個數組是否是"non-boring"
            if (solve(1, n)) System.out.println("non-boring");
            else System.out.println("boring");
        }

        sc.close(); // 使用完畢後，關閉Scanner來釋放資源
    }
}

