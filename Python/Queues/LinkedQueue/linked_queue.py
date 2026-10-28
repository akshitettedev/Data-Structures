"""FIFO queue implemented with front and rear pointers."""
class _Node:
    def __init__(self,data):self.data,self.next=data,None
class LinkedQueue:
    def __init__(self):self._front=self._rear=None;self._size=0
    def is_empty(self):return self._front is None
    def size(self):return self._size
    def enqueue(self,value):
        node=_Node(value)
        if self._rear is None:self._front=self._rear=node
        else:self._rear.next=node;self._rear=node
        self._size+=1
    def dequeue(self):
        if self.is_empty():raise IndexError("Queue underflow")
        value=self._front.data;self._front=self._front.next
        if self._front is None:self._rear=None
        self._size-=1;return value
    def peek(self):
        if self.is_empty():raise IndexError("Queue is empty")
        return self._front.data
    def display(self):
        result=[];node=self._front
        while node:result.append(node.data);node=node.next
        return result
