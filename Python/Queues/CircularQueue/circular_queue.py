"""Fixed-capacity circular queue."""
class CircularQueue:
    def __init__(self,capacity):
        if capacity<=0:raise ValueError("Capacity must be positive")
        self._data=[None]*capacity;self._front=0;self._rear=0;self._size=0
    def is_empty(self):return self._size==0
    def is_full(self):return self._size==len(self._data)
    def size(self):return self._size
    def enqueue(self,value):
        if self.is_full():raise OverflowError("Queue overflow")
        self._data[self._rear]=value;self._rear=(self._rear+1)%len(self._data);self._size+=1
    def dequeue(self):
        if self.is_empty():raise IndexError("Queue underflow")
        value=self._data[self._front];self._front=(self._front+1)%len(self._data);self._size-=1;return value
    def peek(self):
        if self.is_empty():raise IndexError("Queue is empty")
        return self._data[self._front]
    def display(self):return [self._data[(self._front+i)%len(self._data)] for i in range(self._size)]
