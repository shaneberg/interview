import java.util.Arrays;
import java.util.Random;

public class BubbleSort {

    // Will modify input and return a reference to it.
    private static int[] sort(int[] toSort) {
        for (int i = 0; i < toSort.length; i++) {
            int curLength = toSort.length - i;
            for (int j = 1; j < curLength; j++) {
                if (toSort[j] < toSort[j-1]) {
                    int temp = toSort[j-1];
                    toSort[j-1] = toSort[j];
                    toSort[j] = temp;
                }
            }
        }

        return toSort;
    }

    private static int[] getTestArray(int size) {
        int[] result = new int[size];
        Random rand = new Random();

        for (int i = 0; i < result.length; i++) {
            result[i] = rand.nextInt();
        }

        return result;
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
        int[] sorted = BubbleSort.sort(test);
        endTime = System.currentTimeMillis();
        long testDuration = endTime - startTime;
        System.out.println("test duration: " + testDuration + "ms");
        System.out.println("delta: " + (controlDuration - testDuration) + "ms");

        System.out.println("match: " + Arrays.equals(expected, test));
    }
}

