"""Fixed-capacity stack backed by a Python list."""
class ArrayStack:
    def __init__(self, capacity):
        if capacity<=0:raise ValueError("Capacity must be positive")
        self.capacity=capacity;self._data=[]
    def is_empty(self):return len(self._data)==0
    def is_full(self):return len(self._data)==self.capacity
    def size(self):return len(self._data)
    def push(self,value):
        if self.is_full():raise OverflowError("Stack overflow")
        self._data.append(value)
    def pop(self):
        if self.is_empty():raise IndexError("Stack underflow")
        return self._data.pop()
    def peek(self):
        if self.is_empty():raise IndexError("Stack is empty")
        return self._data[-1]
    def display(self):return list(reversed(self._data))
