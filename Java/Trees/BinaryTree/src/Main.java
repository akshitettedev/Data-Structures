public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        BinaryTree.Node root = new BinaryTree.Node(1);
        root.left = new BinaryTree.Node(2); root.right = new BinaryTree.Node(3);
        root.left.left = new BinaryTree.Node(4); root.left.right = new BinaryTree.Node(5);
        tree.setRoot(root);
        System.out.print("Preorder: "); tree.preorder();
        System.out.print("Inorder: "); tree.inorder();
        System.out.print("Postorder: "); tree.postorder();
        System.out.print("Level order: "); tree.levelOrder();
    }
}
