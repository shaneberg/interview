import java.util.Arrays;
import java.util.Random;

public class BubbleSort {

    private static int[] getTestArray(int size) {
        int[] result = new int[size];
        Random rand = new Random();

        for (int i = 0; i < result.length; i++) {
            result[i] = rand.nextInt();
        }

        return result;
    }

    private static int[] sort(int[] toSort) {
        for (int i = 0; i < toSort.length; i++) {
            int curLength = toSort.length - i;

            for (int j = 1; j < curLength; j++) {
                if (toSort[j] < toSort[j - 1]) {
                    // Pair out of order, perform a swap!
                    int temp = toSort[j];
                    toSort[j] = toSort[j - 1];
                    toSort[j - 1] = temp;
                }
            }

        }

        return toSort;
    }

    public static void main(String[] args) {
        int[] testArray = BubbleSort.getTestArray(10 * 1000000);
        long startTime = System.currentTimeMillis();
        // Arrays.sort(testArray);
        BubbleSort.sort(testArray);
        long endTime = System.currentTimeMillis();
        long testDuration = endTime - startTime;
        System.out.println("test duration: " + testDuration + "ms");
    }
}
