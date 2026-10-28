/** Fixed-capacity stack backed by an int array. */
public class ArrayStack {
    private final int[] data; private int top=-1;
    public ArrayStack(int capacity){if(capacity<=0)throw new IllegalArgumentException("Capacity must be positive");data=new int[capacity];}
    public boolean isEmpty(){return top==-1;} public boolean isFull(){return top==data.length-1;} public int size(){return top+1;}
    public void push(int value){if(isFull())throw new IllegalStateException("Stack overflow");data[++top]=value;}
    public int pop(){if(isEmpty())throw new IllegalStateException("Stack underflow");return data[top--];}
    public int peek(){if(isEmpty())throw new IllegalStateException("Stack is empty");return data[top];}
    public void display(){for(int i=top;i>=0;i--)System.out.print(data[i]+" ");System.out.println();}
}
