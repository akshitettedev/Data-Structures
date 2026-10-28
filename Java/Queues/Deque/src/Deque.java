/** Fixed-capacity double-ended queue implemented as a circular array. */
public class Deque {
    private final int[] data; private int front=0,size=0;
    public Deque(int capacity){if(capacity<=0)throw new IllegalArgumentException();data=new int[capacity];}
    public boolean isEmpty(){return size==0;} public boolean isFull(){return size==data.length;} public int size(){return size;}
    public void insertFront(int value){if(isFull())throw new IllegalStateException("Deque overflow");front=(front-1+data.length)%data.length;data[front]=value;size++;}
    public void insertRear(int value){if(isFull())throw new IllegalStateException("Deque overflow");data[(front+size)%data.length]=value;size++;}
    public int deleteFront(){if(isEmpty())throw new IllegalStateException("Deque underflow");int v=data[front];front=(front+1)%data.length;size--;return v;}
    public int deleteRear(){if(isEmpty())throw new IllegalStateException("Deque underflow");int i=(front+size-1)%data.length;int v=data[i];size--;return v;}
    public int getFront(){if(isEmpty())throw new IllegalStateException("Deque is empty");return data[front];}
    public int getRear(){if(isEmpty())throw new IllegalStateException("Deque is empty");return data[(front+size-1)%data.length];}
    public void display(){for(int i=0;i<size;i++)System.out.print(data[(front+i)%data.length]+" ");System.out.println();}
}
