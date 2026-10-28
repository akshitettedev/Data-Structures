/** AVL self-balancing binary search tree. Duplicate keys are ignored. */
public class AVLTree {
    private static class Node { int key, height = 1; Node left, right; Node(int key) { this.key = key; } }
    private Node root;
    private int height(Node n) { return n == null ? 0 : n.height; }
    private int balance(Node n) { return n == null ? 0 : height(n.left) - height(n.right); }
    private void update(Node n) { n.height = 1 + Math.max(height(n.left), height(n.right)); }
    private Node rotateRight(Node y) { Node x = y.left, t = x.right; x.right = y; y.left = t; update(y); update(x); return x; }
    private Node rotateLeft(Node x) { Node y = x.right, t = y.left; y.left = x; x.right = t; update(x); update(y); return y; }
    public void insert(int key) { root = insert(root, key); }
    private Node insert(Node n, int key) {
        if (n == null) return new Node(key);
        if (key < n.key) n.left = insert(n.left, key); else if (key > n.key) n.right = insert(n.right, key); else return n;
        update(n); int b = balance(n);
        if (b > 1 && key < n.left.key) return rotateRight(n);       // LL
        if (b < -1 && key > n.right.key) return rotateLeft(n);      // RR
        if (b > 1 && key > n.left.key) { n.left = rotateLeft(n.left); return rotateRight(n); } // LR
        if (b < -1 && key < n.right.key) { n.right = rotateRight(n.right); return rotateLeft(n); } // RL
        return n;
    }
    public boolean search(int key) { Node n = root; while (n != null) { if (key == n.key) return true; n = key < n.key ? n.left : n.right; } return false; }
    public void delete(int key) { root = delete(root, key); }
    private Node delete(Node n, int key) {
        if (n == null) return null;
        if (key < n.key) n.left = delete(n.left, key); else if (key > n.key) n.right = delete(n.right, key);
        else { if (n.left == null || n.right == null) n = n.left != null ? n.left : n.right; else { Node s = min(n.right); n.key = s.key; n.right = delete(n.right, s.key); } }
        if (n == null) return null;
        update(n); int b = balance(n);
        if (b > 1 && balance(n.left) >= 0) return rotateRight(n);
        if (b > 1 && balance(n.left) < 0) { n.left = rotateLeft(n.left); return rotateRight(n); }
        if (b < -1 && balance(n.right) <= 0) return rotateLeft(n);
        if (b < -1 && balance(n.right) > 0) { n.right = rotateRight(n.right); return rotateLeft(n); }
        return n;
    }
    private Node min(Node n) { while (n.left != null) n = n.left; return n; }
    public void inorder() { inorder(root); System.out.println(); }
    private void inorder(Node n) { if (n != null) { inorder(n.left); System.out.print(n.key + " "); inorder(n.right); } }
    public int height() { return height(root); }
}
