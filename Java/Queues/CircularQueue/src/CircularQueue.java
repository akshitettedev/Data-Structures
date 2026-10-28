/** Fixed-capacity circular queue. */
public class CircularQueue {
    private final int[] data; private int front=0,rear=0,size=0;
    public CircularQueue(int capacity){if(capacity<=0)throw new IllegalArgumentException();data=new int[capacity];}
    public boolean isEmpty(){return size==0;} public boolean isFull(){return size==data.length;} public int size(){return size;}
    public void enqueue(int value){if(isFull())throw new IllegalStateException("Queue overflow");data[rear]=value;rear=(rear+1)%data.length;size++;}
    public int dequeue(){if(isEmpty())throw new IllegalStateException("Queue underflow");int value=data[front];front=(front+1)%data.length;size--;return value;}
    public int peek(){if(isEmpty())throw new IllegalStateException("Queue is empty");return data[front];}
    public void display(){for(int i=0;i<size;i++)System.out.print(data[(front+i)%data.length]+" ");System.out.println();}
}
