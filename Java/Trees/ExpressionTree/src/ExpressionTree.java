import java.util.ArrayDeque;
import java.util.Deque;

/** Builds an expression tree from a whitespace-separated postfix expression. */
public class ExpressionTree {
    private static class Node { String token; Node left, right; Node(String token) { this.token = token; } }
    private Node root;
    private boolean isOperator(String s) { return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("^"); }
    public void buildFromPostfix(String postfix) {
        Deque<Node> stack = new ArrayDeque<>();
        for (String token : postfix.trim().split("\\s+")) {
            if (token.isEmpty()) continue;
            Node node = new Node(token);
            if (isOperator(token)) { if (stack.size() < 2) throw new IllegalArgumentException("Invalid postfix expression"); node.right = stack.pop(); node.left = stack.pop(); }
            stack.push(node);
        }
        if (stack.size() != 1) throw new IllegalArgumentException("Invalid postfix expression");
        root = stack.pop();
    }
    public void inorder() { inorder(root); System.out.println(); }
    private void inorder(Node n) { if (n == null) return; if (isOperator(n.token)) System.out.print("("); inorder(n.left); System.out.print(n.token); inorder(n.right); if (isOperator(n.token)) System.out.print(")"); }
    public void postorder() { postorder(root); System.out.println(); }
    private void postorder(Node n) { if (n != null) { postorder(n.left); postorder(n.right); System.out.print(n.token + " "); } }
    public double evaluate() { return evaluate(root); }
    private double evaluate(Node n) {
        if (n == null) throw new IllegalStateException("Tree is empty");
        if (!isOperator(n.token)) return Double.parseDouble(n.token);
        double a = evaluate(n.left), b = evaluate(n.right);
        switch (n.token) { case "+": return a+b; case "-": return a-b; case "*": return a*b; case "/": return a/b; case "^": return Math.pow(a,b); default: throw new IllegalStateException("Unknown operator"); }
    }
}
