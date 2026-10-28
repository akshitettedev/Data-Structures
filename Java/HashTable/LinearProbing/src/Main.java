public class Main {
    public static void main(String[] args) {
        HashTable table=new HashTable(7);for(int x:new int[]{10,17,24,5})table.insert(x);
        System.out.println("Search 17: "+table.search(17));table.delete(17);System.out.println("Search 17 after delete: "+table.search(17));
        System.out.println("Slots:");table.display();
    }
}
