public class Main {
    public static void main(String[] args) {
        LinkedStack stack=new LinkedStack();stack.push(5);stack.push(15);stack.push(25);
        System.out.print("Stack: ");stack.display();System.out.println("Popped: "+stack.pop());System.out.println("Top: "+stack.peek());
    }
}
