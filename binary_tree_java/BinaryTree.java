import java.util.function.Supplier;
import java.util.Objects;

import java.util.HashMap;
import java.util.Map;

import java.util.Random;


public class BinaryTree {

    public class BinaryTreeNode<T> {
        private BinaryTreeNode<T> left;
        private BinaryTreeNode<T> right;
        private T data;

        public BinaryTreeNode(T data) {
            this.data = data;
        }

        public T getData() {
            return this.data;
        }

        public void setLeft(BinaryTreeNode<T> left) {
            this.left = left;
        }

        public void setRight(BinaryTreeNode<T> right) {
            this.right = right;
        }

        public BinaryTreeNode<T> getLeft() {
            this.left = left;
        }

        public BinaryTreeNode<T> getRight() {
            this.right = right;
        }
    }

    public class Coordinate {
        private final int x;
        private final int y;

        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Coordinate that = (Coordinate) o;
            return x == that.x && y == that.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    public class CoordinateMap<T> {

        private Map<Coordinate, T> map = new HashMap<Coordinate, T>();

        public void put(int x, int y, T value) {
            map.put(new Coordinate(x, y), value);
        }

        public T get(int x, int y) {
            return map.get(new Coordinate(x, y));
        }
    }

    private static <T> BinaryTreeNode<T> generateBinaryTree(int height, Supplier<T> valueGenerator) {
        if (height <= 0) {
            return null;
        }

        BinaryTreeNode<T> node = new BinaryTreeNode<T>(valueGenerator.get());
        node.setLeft(generateBinaryTree(height - 1, valueGenerator));
        node.setRight(generateBinaryTree(height - 1, valueGenerator));
        return node;
    }


    private static <T> int determineDepth(BinaryTreeNode<T> head) {
        int left = head.getLeft() != null ? determineDepth(head.getLeft()) : 0;
        int right = head.getRight() != null ? determineDepth(head.getRight()) : 0;
        int max = Math.max(left, right);
        return 1 + max;
    }

    public static <T> void print(BinaryTreeNode<T> head) {
        int height = determineDepth(head);
        System.out.println("Determined the height is " + height);

        CoordinateMap<T> map = new CoordinateMap<T>();

        int maxNodes = (int)Math.pow(2, height - 1);
        int max = (maxNodes * 2) - 1;
        System.out.println("max width is: " + max);

        for (int i = 0; i < height; i++) {
            int nodes = (int)Math.pow(2, i);
            for (int j = 0; j < nodes; j++) {
                int padding = max / (int)Math.pow(2, i+1);
                for (int k = 0; k < padding; k++) {
                    System.out.print(" ");
                }

                int width = 1;
                for (int k = 0; k < width; k++) {
                    System.out.print("x");
                }

                if (j < nodes - 1) {
                    int spaces = padding + 1;
                    for (int k = 0; k < spaces; k++) {
                        System.out.print(" ");
                    }
                }
            }

            System.out.println("");
        }
    }

}
