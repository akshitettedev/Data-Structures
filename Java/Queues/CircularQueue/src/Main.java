public class Main {
    public static void main(String[] args) {
        CircularQueue q=new CircularQueue(3);q.enqueue(1);q.enqueue(2);q.enqueue(3);q.dequeue();q.enqueue(4);
        System.out.print("Circular queue: ");q.display();System.out.println("Front: "+q.peek());
    }
}
