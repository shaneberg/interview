import java.util.Arrays;
import java.util.Random;

public class MergeSort {

    private static int[] getTestArray(int size) {
        int[] result = new int[size];
        Random rand = new Random();

        for (int i = 0; i < result.length; i++) {
            result[i] = rand.nextInt();
        }

        return result;
    }

    private static int[] merge(int[] left, int[] right) {
        int[] combinedArray = new int[left.length + right.length];

        int curLeft = 0;
        int curRight = 0;
        int curWrite = 0;

        while(curWrite < combinedArray.length) {

            boolean leftDone = curLeft >= left.length;
            boolean rightDone = curRight >= right.length;

            if (!leftDone && (rightDone || left[curLeft] <= right[curRight])) {
                combinedArray[curWrite] = left[curLeft];
                curLeft++;
            } else {
                combinedArray[curWrite] = right[curRight];
                curRight++;
            }

            curWrite++;
        }

        return combinedArray;
    }

    private static int[] sort(int[] toSort) {

        if (toSort.length < 2) {
            return toSort;
        }

        int leftStart = 0;
        int leftEnd = toSort.length / 2;
        int rightStart = leftEnd;
        int rightEnd = toSort.length;

        int[] left = sort(Arrays.copyOfRange(toSort, 0, toSort.length / 2));
        int[] right = sort(Arrays.copyOfRange(toSort, toSort.length / 2, toSort.length));

        return merge(left, right);
    }

    public static void main(String[] args) {
        int[] merge_test = getTestArray(10000);

        int[] result = MergeSort.sort(merge_test);
        Arrays.sort(merge_test);
        System.out.println("match: " + Arrays.equals(result, merge_test));
    }
}
