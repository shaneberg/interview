import java.util.Arrays;
import java.util.Random;

public class InsertSort {

    private static int[] getTestArray(int size) {
        int[] result = new int[size];
        Random rand = new Random();

        for (int i = 0; i < result.length; i++) {
            result[i] = rand.nextInt();
        }

        return result;
    }

    private static int[] sort(int[] unsorted) {
        for (int i = 1; i < unsorted.length; i++) {
            for (int j = i; j > 0; j--) {
                if (unsorted[j - 1] > unsorted[j]) {
                    int temp = unsorted[j];
                    unsorted[j] = unsorted[j - 1];
                    unsorted[j - 1] = temp;
                } else {
                    break;
                }
            }
        }

        return unsorted;
    }

    public static void main(String[] args) {
        int[] test = getTestArray(10 * 1024);
        int[] expected = Arrays.copyOf(test, test.length);

        long startTime = System.currentTimeMillis();
        Arrays.sort(expected);
        long endTime = System.currentTimeMillis();
        long controlDuration = endTime - startTime;
        System.out.println("control duration: " + controlDuration + "ms");

        startTime = System.currentTimeMillis();
        int[] sorted = InsertSort.sort(test);
        endTime = System.currentTimeMillis();
        long testDuration = endTime - startTime;
        System.out.println("test duration: " + testDuration + "ms");
        System.out.println("delta: " + (controlDuration - testDuration) + "ms");

        System.out.println("match: " + Arrays.equals(expected, test));
    }
}

