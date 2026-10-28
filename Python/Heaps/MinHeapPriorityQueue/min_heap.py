"""Array-backed min-heap priority queue; lowest value has highest priority."""
class MinHeap:
    def __init__(self):self._heap=[]
    def size(self):return len(self._heap)
    def is_empty(self):return not self._heap
    def insert(self,value):
        self._heap.append(value);i=len(self._heap)-1
        while i>0:
            parent=(i-1)//2
            if self._heap[parent]<=self._heap[i]:break
            self._heap[parent],self._heap[i]=self._heap[i],self._heap[parent];i=parent
    def peek(self):
        if self.is_empty():raise IndexError("Heap is empty")
        return self._heap[0]
    def extract_min(self):
        if self.is_empty():raise IndexError("Heap underflow")
        if len(self._heap)==1:return self._heap.pop()
        minimum=self._heap[0];self._heap[0]=self._heap.pop();self._sift_down(0);return minimum
    def _sift_down(self,i):
        n=len(self._heap)
        while True:
            left,right,smallest=2*i+1,2*i+2,i
            if left<n and self._heap[left]<self._heap[smallest]:smallest=left
            if right<n and self._heap[right]<self._heap[smallest]:smallest=right
            if smallest==i:return
            self._heap[i],self._heap[smallest]=self._heap[smallest],self._heap[i];i=smallest
    def display(self):return self._heap[:]
