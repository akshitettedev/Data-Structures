"""Circular singly linked list maintained with a tail pointer."""
class _Node:
    def __init__(self,data):self.data,self.next=data,None
class CircularLinkedList:
    def __init__(self):self._tail=None;self._size=0
    def is_empty(self):return self._tail is None
    def size(self):return self._size
    def insert_front(self,value):
        node=_Node(value)
        if self._tail is None:node.next=node;self._tail=node
        else:node.next=self._tail.next;self._tail.next=node
        self._size+=1
    def insert_end(self,value):self.insert_front(value);self._tail=self._tail.next
    def search(self,value):
        if self._tail is None:return False
        node=self._tail.next
        while True:
            if node.data==value:return True
            node=node.next
            if node is self._tail.next:return False
    def delete(self,value):
        if self._tail is None:return False
        previous=self._tail;current=self._tail.next
        while True:
            if current.data==value:
                if current is self._tail and current.next is self._tail:self._tail=None
                else:
                    previous.next=current.next
                    if current is self._tail:self._tail=previous
                self._size-=1;return True
            previous,current=current,current.next
            if current is self._tail.next:return False
    def display(self):
        if self._tail is None:return []
        result=[];node=self._tail.next
        while True:
            result.append(node.data);node=node.next
            if node is self._tail.next:return result
