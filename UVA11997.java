import java.util.*;

public class UVA11997 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            int K = scanner.nextInt();
            int[][] lists = new int[K][K];

            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    lists[i][j] = scanner.nextInt();
                }
                Arrays.sort(lists[i]);
            }

            int[] mergedList = mergeKSortedLists(lists, K);

            for (int i = 0; i < K - 1; i++) {
                System.out.print(mergedList[i] + " ");
            }
            System.out.println(mergedList[K - 1]);
        }

        scanner.close();
    }

    private static int[] mergeKSortedLists(int[][] lists, int K) {
        int[] mergedList = Arrays.copyOf(lists[0], K);

        for (int i = 1; i < K; i++) {
            mergedList = mergeTwoLists(mergedList, lists[i], K);
        }

        return mergedList;
    }

    private static int[] mergeTwoLists(int[] list1, int[] list2, int K) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < K; i++) {
            pq.offer(new int[]{list1[i] + list2[0], 0});
        }

        int[] result = new int[K];
        for (int i = 0; i < K; i++) {
            int[] current = pq.poll();
            result[i] = current[0];
            int indexList2 = current[1];
            if (indexList2 + 1 < K) {
                pq.offer(new int[]{current[0] - list2[indexList2] + list2[indexList2 + 1], indexList2 + 1});
            }
        }

        return result;
    }
}
