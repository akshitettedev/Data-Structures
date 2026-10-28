import java.util.Arrays;

/** Array-backed min-heap. Smaller integer values have higher priority. */
public class MinHeap {
    private int[] heap; private int size;
    public MinHeap(){heap=new int[8];}
    public int size(){return size;} public boolean isEmpty(){return size==0;}
    private void ensureCapacity(){if(size==heap.length)heap=Arrays.copyOf(heap,heap.length*2);}
    public void insert(int value){ensureCapacity();int i=size++;heap[i]=value;while(i>0){int p=(i-1)/2;if(heap[p]<=heap[i])break;swap(i,p);i=p;}}
    public int peek(){if(isEmpty())throw new IllegalStateException("Heap is empty");return heap[0];}
    public int extractMin(){if(isEmpty())throw new IllegalStateException("Heap underflow");int min=heap[0];heap[0]=heap[--size];if(size>0)siftDown(0);return min;}
    private void siftDown(int i){while(true){int left=2*i+1,right=2*i+2,smallest=i;if(left<size&&heap[left]<heap[smallest])smallest=left;if(right<size&&heap[right]<heap[smallest])smallest=right;if(smallest==i)return;swap(i,smallest);i=smallest;}}
    private void swap(int a,int b){int t=heap[a];heap[a]=heap[b];heap[b]=t;}
    public void display(){System.out.println(Arrays.toString(Arrays.copyOf(heap,size)));}
}
