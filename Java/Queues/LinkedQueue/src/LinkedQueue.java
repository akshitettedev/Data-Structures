/** FIFO queue implemented with front and rear pointers. */
public class LinkedQueue {
    private static class Node { int data; Node next; Node(int data){this.data=data;} }
    private Node front,rear; private int size;
    public boolean isEmpty(){return front==null;} public int size(){return size;}
    public void enqueue(int value){Node n=new Node(value);if(rear==null)front=rear=n;else{rear.next=n;rear=n;}size++;}
    public int dequeue(){if(isEmpty())throw new IllegalStateException("Queue underflow");int value=front.data;front=front.next;if(front==null)rear=null;size--;return value;}
    public int peek(){if(isEmpty())throw new IllegalStateException("Queue is empty");return front.data;}
    public void display(){for(Node n=front;n!=null;n=n.next)System.out.print(n.data+" ");System.out.println();}
}
