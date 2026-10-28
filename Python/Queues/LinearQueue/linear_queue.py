"""Simple fixed-array linear queue. Front slots are reused only when empty."""
class LinearQueue:
    def __init__(self,capacity):
        if capacity<=0:raise ValueError("Capacity must be positive")
        self._data=[None]*capacity;self._front=0;self._rear=-1
    def is_empty(self):return self._rear<self._front
    def is_full(self):return self._rear==len(self._data)-1
    def size(self):return 0 if self.is_empty() else self._rear-self._front+1
    def enqueue(self,value):
        if self.is_full():raise OverflowError("Queue overflow")
        self._rear+=1;self._data[self._rear]=value
    def dequeue(self):
        if self.is_empty():raise IndexError("Queue underflow")
        value=self._data[self._front];self._front+=1
        if self._front>self._rear:self._front=0;self._rear=-1
        return value
    def peek(self):
        if self.is_empty():raise IndexError("Queue is empty")
        return self._data[self._front]
    def display(self):return [] if self.is_empty() else self._data[self._front:self._rear+1]
