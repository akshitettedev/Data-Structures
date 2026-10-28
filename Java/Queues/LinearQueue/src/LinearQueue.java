/** Simple linear queue using a fixed-size array; freed front slots are not reused. */
public class LinearQueue {
    private final int[] data; private int front=0,rear=-1;
    public LinearQueue(int capacity){if(capacity<=0)throw new IllegalArgumentException();data=new int[capacity];}
    public boolean isEmpty(){return rear<front;} public boolean isFull(){return rear==data.length-1;} public int size(){return isEmpty()?0:rear-front+1;}
    public void enqueue(int value){if(isFull())throw new IllegalStateException("Queue overflow");data[++rear]=value;}
    public int dequeue(){if(isEmpty())throw new IllegalStateException("Queue underflow");int value=data[front++];if(front>rear){front=0;rear=-1;}return value;}
    public int peek(){if(isEmpty())throw new IllegalStateException("Queue is empty");return data[front];}
    public void display(){for(int i=front;i<=rear;i++)System.out.print(data[i]+" ");System.out.println();}
}
