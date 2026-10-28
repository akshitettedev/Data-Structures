/** Binary Search Tree for integer keys. Duplicate keys are ignored. */
public class BinarySearchTree {
    private static class Node { int key; Node left, right; Node(int key) { this.key = key; } }
    private Node root;
    public void insert(int key) { root = insert(root, key); }
    private Node insert(Node n, int key) { if (n == null) return new Node(key); if (key < n.key) n.left = insert(n.left, key); else if (key > n.key) n.right = insert(n.right, key); return n; }
    public boolean search(int key) { Node n = root; while (n != null) { if (key == n.key) return true; n = key < n.key ? n.left : n.right; } return false; }
    public void delete(int key) { root = delete(root, key); }
    private Node delete(Node n, int key) {
        if (n == null) return null;
        if (key < n.key) n.left = delete(n.left, key);
        else if (key > n.key) n.right = delete(n.right, key);
        else { if (n.left == null) return n.right; if (n.right == null) return n.left; Node s = min(n.right); n.key = s.key; n.right = delete(n.right, s.key); }
        return n;
    }
    private Node min(Node n) { while (n.left != null) n = n.left; return n; }
    public void inorder() { inorder(root); System.out.println(); }
    private void inorder(Node n) { if (n != null) { inorder(n.left); System.out.print(n.key + " "); inorder(n.right); } }
    public void preorder() { preorder(root); System.out.println(); }
    private void preorder(Node n) { if (n != null) { System.out.print(n.key + " "); preorder(n.left); preorder(n.right); } }
    public void postorder() { postorder(root); System.out.println(); }
    private void postorder(Node n) { if (n != null) { postorder(n.left); postorder(n.right); System.out.print(n.key + " "); } }
}
