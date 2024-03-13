public class Program {
    public static void main(String[] args) {
        Supplier<Integer> intSupplier = () -> new Random().nextInt(10);
        BinaryTreeNode<Integer> head = BinaryTree.generateBinaryTree(3, intSupplier);
        BinaryTree.print(head);
    }
}
