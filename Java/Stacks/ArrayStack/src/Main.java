public class Main {
    public static void main(String[] args) {
        ArrayStack stack=new ArrayStack(5); stack.push(10);stack.push(20);stack.push(30);
        System.out.print("Stack (top to bottom): ");stack.display();
        System.out.println("Peek: "+stack.peek());System.out.println("Pop: "+stack.pop());System.out.println("Size: "+stack.size());
    }
}
