public class Main {
    public static void main(String[] args) {
        ExpressionTree tree = new ExpressionTree();
        tree.buildFromPostfix("3 4 + 2 * 7 /");
        System.out.print("Infix: "); tree.inorder();
        System.out.print("Postfix: "); tree.postorder();
        System.out.println("Value: " + tree.evaluate());
    }
}
