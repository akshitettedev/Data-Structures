public class Main {
    public static void main(String[] args) {
        MinHeap heap=new MinHeap();int[] values={40,10,30,5,12,6};for(int v:values)heap.insert(v);
        System.out.print("Heap array: ");heap.display();System.out.println("Minimum: "+heap.peek());
        System.out.print("Extract order: ");while(!heap.isEmpty())System.out.print(heap.extractMin()+" ");System.out.println();
    }
}
