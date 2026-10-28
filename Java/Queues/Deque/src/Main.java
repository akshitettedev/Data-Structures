public class Main {
    public static void main(String[] args) {
        Deque deque=new Deque(5);deque.insertRear(20);deque.insertRear(30);deque.insertFront(10);
        System.out.print("Deque: ");deque.display();System.out.println("Front removed: "+deque.deleteFront());System.out.println("Rear: "+deque.getRear());
    }
}
