import java.util.ArrayDeque;
import java.util.Queue;

/** A basic binary tree with recursive traversals and level-order traversal. */
public class BinaryTree {
    public static class Node {
        public int data;
        public Node left, right;
        public Node(int data) { this.data = data; }
    }
    private Node root;
    public Node getRoot() { return root; }
    public void setRoot(Node root) { this.root = root; }
    public void preorder() { preorder(root); System.out.println(); }
    private void preorder(Node n) { if (n != null) { System.out.print(n.data + " "); preorder(n.left); preorder(n.right); } }
    public void inorder() { inorder(root); System.out.println(); }
    private void inorder(Node n) { if (n != null) { inorder(n.left); System.out.print(n.data + " "); inorder(n.right); } }
    public void postorder() { postorder(root); System.out.println(); }
    private void postorder(Node n) { if (n != null) { postorder(n.left); postorder(n.right); System.out.print(n.data + " "); } }
    public void levelOrder() {
        if (root == null) { System.out.println(); return; }
        Queue<Node> q = new ArrayDeque<>(); q.add(root);
        while (!q.isEmpty()) { Node n = q.remove(); System.out.print(n.data + " "); if (n.left != null) q.add(n.left); if (n.right != null) q.add(n.right); }
        System.out.println();
    }
}
