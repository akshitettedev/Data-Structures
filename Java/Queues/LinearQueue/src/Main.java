public class Main {
    public static void main(String[] args) {
        LinearQueue q=new LinearQueue(5);q.enqueue(10);q.enqueue(20);q.enqueue(30);
        System.out.print("Queue: ");q.display();System.out.println("Dequeued: "+q.dequeue());System.out.println("Front: "+q.peek());
    }
}
