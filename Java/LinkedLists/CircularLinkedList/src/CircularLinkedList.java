/** Circular singly linked list with tail pointer; tail.next is the head. */
public class CircularLinkedList {
    private static class Node { int data; Node next; Node(int data){this.data=data;} }
    private Node tail; private int size;
    public int size(){return size;} public boolean isEmpty(){return tail==null;}
    public void insertFront(int value){Node n=new Node(value);if(tail==null){tail=n;n.next=n;}else{n.next=tail.next;tail.next=n;}size++;}
    public void insertEnd(int value){insertFront(value);tail=tail.next;}
    public boolean search(int value){if(tail==null)return false;Node n=tail.next;do{if(n.data==value)return true;n=n.next;}while(n!=tail.next);return false;}
    public boolean delete(int value){if(tail==null)return false;Node prev=tail,cur=tail.next;do{if(cur.data==value){if(cur==tail&&cur.next==tail){tail=null;}else{prev.next=cur.next;if(cur==tail)tail=prev;}size--;return true;}prev=cur;cur=cur.next;}while(cur!=tail.next);return false;}
    public void display(){if(tail==null){System.out.println("(empty)");return;}Node n=tail.next;do{System.out.print(n.data+" -> ");n=n.next;}while(n!=tail.next);System.out.println("(back to head)");}
}
