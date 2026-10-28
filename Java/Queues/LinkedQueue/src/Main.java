public class Main {
    public static void main(String[] args) {
        LinkedQueue q=new LinkedQueue();q.enqueue(100);q.enqueue(200);q.enqueue(300);
        System.out.print("Queue: ");q.display();System.out.println("Dequeued: "+q.dequeue());System.out.println("Size: "+q.size());
    }
}
