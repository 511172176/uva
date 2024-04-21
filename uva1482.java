import java.util.Scanner;

public class uva1482 {

    // 定义long long类型为long
    public static long SG(long x) {
        // 如果x是奇数，则递归调用SG函数并将x右移一位
        // 如果x是偶数，则直接返回x右移一位的结果
        return (x & 1) == 1 ? SG(x >> 1) : x >> 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int cas = scanner.nextInt();  // 读取测试用例的数量

        // 对于每一个测试用例进行操作
        for (int t = 0; t < cas; t++) {
            long m, v = 0;
            int n = scanner.nextInt();  // 读取每个测试用例中的数字的数量

            // 对于每个数字进行操作
            for (int i = 0; i < n; i++) {
                m = scanner.nextLong();  // 读取数字
                v ^= SG(m);  // 对数字的SG值进行异或操作
            }

            // 如果最后的异或结果不为0，则输出YES
            // 否则，输出NO
            System.out.println(v != 0 ? "YES" : "NO");
        }

        scanner.close();
    }
}
