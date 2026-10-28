public class Main {
    public static void main(String[] args) {
        CircularLinkedList list=new CircularLinkedList();list.insertEnd(10);list.insertEnd(20);list.insertFront(5);
        list.display();System.out.println("Search 20: "+list.search(20));list.delete(10);System.out.print("After deleting 10: ");list.display();
    }
}
