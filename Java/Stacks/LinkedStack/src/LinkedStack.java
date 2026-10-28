/** Stack implemented using a singly linked list. */
public class LinkedStack {
    private static class Node { int data; Node next; Node(int data,Node next){this.data=data;this.next=next;} }
    private Node top; private int size;
    public boolean isEmpty(){return top==null;} public int size(){return size;}
    public void push(int value){top=new Node(value,top);size++;}
    public int pop(){if(isEmpty())throw new IllegalStateException("Stack underflow");int value=top.data;top=top.next;size--;return value;}
    public int peek(){if(isEmpty())throw new IllegalStateException("Stack is empty");return top.data;}
    public void display(){for(Node n=top;n!=null;n=n.next)System.out.print(n.data+" ");System.out.println();}
}
