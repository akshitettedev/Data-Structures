"""Stack implemented using a singly linked list."""
class _Node:
    def __init__(self,data,next_node=None):self.data,self.next=data,next_node
class LinkedStack:
    def __init__(self):self._top=None;self._size=0
    def is_empty(self):return self._top is None
    def size(self):return self._size
    def push(self,value):self._top=_Node(value,self._top);self._size+=1
    def pop(self):
        if self.is_empty():raise IndexError("Stack underflow")
        value=self._top.data;self._top=self._top.next;self._size-=1;return value
    def peek(self):
        if self.is_empty():raise IndexError("Stack is empty")
        return self._top.data
    def display(self):
        result=[];node=self._top
        while node:result.append(node.data);node=node.next
        return result
