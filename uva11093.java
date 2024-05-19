import java.util.*;

public class uva11093 {

    public static final int MAXN = 100005;  // 設定最大站點數

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);  // 從input.txt讀取輸入
        
        
        int T = input.nextInt();  // 讀取測試案例數量
        int kase = 0;  // 紀錄目前處理到的測試案例數

        // 針對每一個測試案例進行處理
        while (T-- > 0) {
            int[] p = new int[MAXN];  // 儲存每個加油站的油量
            int[] q = new int[MAXN];  // 儲存從當前加油站到下一站所需的油量
            int gas = 0, begin = 0, pass = 0;  // 初始化油量、起始加油站的索引和已經經過的站點數量
            boolean head = true;  // 判斷是否是當前循環的第一步

            int n = input.nextInt();  // 讀取加油站數量
            for (int i = 0; i < n; i++) p[i] = input.nextInt();  // 讀取每個加油站的油量
            for (int i = 0; i < n; i++) q[i] = input.nextInt();  // 讀取從每個加油站到下一站所需的油量

            // 嘗試從每一個起始站開始行駛
            while (begin < n) {
                int cur = pass % n;  // 計算當前站點的索引
                // 如果完成一圈且不是從新的起始站開始，則跳出循環
                if (!head && begin == cur) break;
                // 更新車上的油量
                gas += p[cur] - q[cur];

                // 如果油量足夠，繼續行駛
                if (gas >= 0) {
                    pass++;
                    head = false;
                } else {
                    // 如果油量不足，重新設定油量並從下一站開始行駛
                    gas = 0;
                    begin = ++pass;
                    head = true;
                }
            }

            // 根據是否能夠完成一圈輸出結果
            if (begin >= n || head) {
                System.out.println("Case " + (++kase) + ": Not possible");
            } else {
            	System.out.println("Case " + (++kase) + ": Possible from station " + (begin + 1));
            }
        }
        input.close();
    }
}
