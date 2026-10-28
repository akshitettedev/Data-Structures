"""Fixed-capacity deque (double-ended queue) backed by a circular array."""
class Deque:
    def __init__(self,capacity):
        if capacity<=0:raise ValueError("Capacity must be positive")
        self._data=[None]*capacity;self._front=0;self._size=0
    def is_empty(self):return self._size==0
    def is_full(self):return self._size==len(self._data)
    def size(self):return self._size
    def insert_front(self,value):
        if self.is_full():raise OverflowError("Deque overflow")
        self._front=(self._front-1)%len(self._data);self._data[self._front]=value;self._size+=1
    def insert_rear(self,value):
        if self.is_full():raise OverflowError("Deque overflow")
        self._data[(self._front+self._size)%len(self._data)]=value;self._size+=1
    def delete_front(self):
        if self.is_empty():raise IndexError("Deque underflow")
        value=self._data[self._front];self._front=(self._front+1)%len(self._data);self._size-=1;return value
    def delete_rear(self):
        if self.is_empty():raise IndexError("Deque underflow")
        value=self._data[(self._front+self._size-1)%len(self._data)];self._size-=1;return value
    def get_front(self):
        if self.is_empty():raise IndexError("Deque is empty")
        return self._data[self._front]
    def get_rear(self):
        if self.is_empty():raise IndexError("Deque is empty")
        return self._data[(self._front+self._size-1)%len(self._data)]
    def display(self):return [self._data[(self._front+i)%len(self._data)] for i in range(self._size)]
