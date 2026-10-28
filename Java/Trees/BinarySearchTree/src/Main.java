public class Main {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] values = {50, 30, 70, 20, 40, 60, 80};
        for (int value : values) bst.insert(value);
        System.out.print("Inorder: "); bst.inorder();
        System.out.println("Search 40: " + bst.search(40));
        bst.delete(30);
        System.out.print("After deleting 30: "); bst.inorder();
    }
}
