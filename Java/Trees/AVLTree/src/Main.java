public class Main {
    public static void main(String[] args) {
        AVLTree tree = new AVLTree();
        int[] values = {10, 20, 30, 40, 50, 25};
        for (int value : values) tree.insert(value);
        System.out.print("Balanced inorder: "); tree.inorder();
        System.out.println("Height: " + tree.height());
        System.out.println("Search 25: " + tree.search(25));
        tree.delete(40); System.out.print("After deleting 40: "); tree.inorder();
    }
}
